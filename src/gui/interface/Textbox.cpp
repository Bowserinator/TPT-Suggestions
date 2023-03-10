#include "Textbox.h"
#include "Format.h"
#include "PowderToySDL.h"
#include "common/platform/Platform.h"
#include "graphics/FontReader.h"
#include "graphics/Graphics.h"
#include "gui/interface/Engine.h"
#include "gui/interface/Point.h"
#include "ContextMenu.h"
#include <SDL.h>

using namespace ui;

Textbox::Textbox(Point position, Point size, String textboxText, String textboxPlaceholder):
	Label(position, size, ""),
	ReadOnly(false),
	inputType(All),
	limit(String::npos),
	keyDown(0),
	characterDown(0),
	mouseDown(false),
	masked(false),
	border(true),
	inputRectPosition(0, 0),
	textEditing(false)
{
	DoesTextInput = true;
	placeHolder = textboxPlaceholder;

	SetText(textboxText);
	cursor = text.length();

	menu->RemoveItem(0);
	menu->AddItem(ContextMenuItem("Cut", 1, true));
	menu->AddItem(ContextMenuItem("Copy", 0, true));
	menu->AddItem(ContextMenuItem("Paste", 2, true));
}

void Textbox::SetHidden(bool hidden)
{
	menu->RemoveItem(0);
	menu->RemoveItem(1);
	menu->RemoveItem(2);
	menu->AddItem(ContextMenuItem("Cut", 1, !hidden));
	menu->AddItem(ContextMenuItem("Copy", 0, !hidden));
	menu->AddItem(ContextMenuItem("Paste", 2, true));

	masked = hidden;
}

void Textbox::SetPlaceholder(String text)
{
	placeHolder = text;
}

void Textbox::SetText(String newText)
{
	StopTextEditing();

	backingText = newText;

	if(masked)
	{
		String maskedText = newText;
		std::fill(maskedText.begin(), maskedText.end(), 0xE00D);
		Label::SetText(maskedText);
	}
	else
		Label::SetText(newText);

	cursor = newText.length();

	resetCursorPosition();
}

Textbox::ValidInput Textbox::GetInputType()
{
	return inputType;
}

void Textbox::SetInputType(ValidInput input)
{
	inputType = input;
}

void Textbox::SetLimit(size_t limit)
{
	this->limit = limit;
}

size_t Textbox::GetLimit()
{
	return limit;
}

String Textbox::GetText()
{
	return backingText;
}

void Textbox::OnContextMenuAction(int item)
{
	StopTextEditing();

	switch(item)
	{
	case 0:
		copySelection();
		break;
	case 1:
		cutSelection();
		break;
	case 2:
		pasteIntoSelection();
		break;
	}
}

void Textbox::resetCursorPosition()
{
	if(cursor)
	{
		textWrapper.Index2Point(textWrapper.Clear2Index(cursor), cursorPositionX, cursorPositionY);
	}
	else
	{
		cursorPositionY = cursorPositionX = 0;
	}
}

void Textbox::TabFocus()
{
	GetParentWindow()->FocusComponent(this);
	selectAll();
}

void Textbox::cutSelection()
{
	StopTextEditing();

	if (HasSelection())
	{
		if (getLowerSelectionBound() < 0 || getHigherSelectionBound() > (int)backingText.length())
			return;
		String toCopy = backingText.Between(getLowerSelectionBound(), getHigherSelectionBound());
		ClipboardPush(format::CleanString(toCopy, false, true, false).ToUtf8());
		backingText.erase(backingText.begin()+getLowerSelectionBound(), backingText.begin()+getHigherSelectionBound());
		cursor = getLowerSelectionBound();
	}
	else
	{
		if (!backingText.length())
			return;
		ClipboardPush(format::CleanString(backingText, false, true, false).ToUtf8());
		backingText.clear();
		cursor = 0;
	}
	ClearSelection();

	if(masked)
	{
		String maskedText = backingText;
		std::fill(maskedText.begin(), maskedText.end(), 0xE00D);
		Label::SetText(maskedText);
	}
	else
	{
		text = backingText;
	}

	updateTextWrapper();
	updateSelection();
	TextPosition(displayTextWrapper.WrappedText());

	resetCursorPosition();
	if (actionCallback.change)
		actionCallback.change();
}

void Textbox::pasteIntoSelection()
{
	StopTextEditing();

	String newText = format::CleanString(ClipboardPull().FromUtf8(), false, true, inputType != Multiline, inputType == Number || inputType == Numeric);
	if (HasSelection())
	{
		if (getLowerSelectionBound() < 0 || getHigherSelectionBound() > (int)backingText.length())
			return;
		backingText.EraseBetween(getLowerSelectionBound(), getHigherSelectionBound());
		cursor = getLowerSelectionBound();
	}

	int regionWidth = Size.X;
	if (Appearance.icon)
		regionWidth -= 13;
	regionWidth -= Appearance.Margin.Left;
	regionWidth -= Appearance.Margin.Right;

	if (limit != String::npos)
	{
		newText = newText.Substr(0, limit-backingText.length());
	}
	if (!multiline && Graphics::textwidth(backingText + newText) > regionWidth)
	{
		int pLimit = regionWidth - Graphics::textwidth(backingText);
		int pWidth = 0;
		auto it = newText.begin();
		while (it != newText.end())
		{
			auto w = Graphics::CharWidth(*it);
			if (pWidth + w > pLimit)
			{
				break;
			}
			pWidth += w;
			++it;
		}
		newText = String(newText.begin(), it);
	}

	backingText.Insert(cursor, newText);
	cursor = cursor+newText.length();
	ClearSelection();

	if(masked)
	{
		String maskedText = backingText;
		std::fill(maskedText.begin(), maskedText.end(), 0xE00D);
		Label::SetText(maskedText);
	}
	else
	{
		text = backingText;
	}

	updateTextWrapper();
	updateSelection();
	TextPosition(displayTextWrapper.WrappedText());

	resetCursorPosition();
	if (actionCallback.change)
		actionCallback.change();
}

bool Textbox::CharacterValid(int character)
{
	switch(inputType)
	{
		case Numeric:
			if (character == '-' && cursor == 0 && backingText[0] != '-')
				return true;
		case Number:
			return (character >= '0' && character <= '9');
		case Multiline:
			if (character == '\n')
				return true;
		case All:
		default:
			return character >= ' ' && character <= 0x10FFFF && !(character >= 0xD800 && character <= 0xDFFF) && !(character >= 0xFDD0 && character <= 0xFDEF) && !((character & 0xFFFF) >= 0xFFFE);
	}
	return false;
}

// TODO: proper unicode validation
bool Textbox::StringValid(String text)
{
	for (String::value_type c : text)
		if (!CharacterValid(c))
			return false;
	return true;
}

void Textbox::Tick(float dt)
{
	Label::Tick(dt);
	if (GetParentWindow() && Visible && Enabled && IsFocused())
	{
		ui::Engine::Ref().TextInputRect(GetScreenPos() + textPosition + inputRectPosition - Point(1, 3), Point(Size.X - textPosition.X - inputRectPosition.X, FONT_H + 2));
	}
	if (!IsFocused())
	{
		keyDown = 0;
		characterDown = 0;
	}
	unsigned long time_pls = Platform::GetTime();
	if ((keyDown || characterDown) && repeatTime <= time_pls)
	{
		//OnVKeyPress(keyDown, characterDown, false, false, false);
		repeatTime = Platform::GetTime()+30;
	}
}

void Textbox::OnKeyRelease(int key, int scan, bool repeat, bool shift, bool ctrl, bool alt)
{
	keyDown = 0;
	characterDown = 0;
}

void Textbox::OnKeyPress(int key, int scan, bool repeat, bool shift, bool ctrl, bool alt)
{
	characterDown = scan;
	keyDown = key;
	repeatTime = Platform::GetTime()+300;
	OnVKeyPress(key, scan, repeat, shift, ctrl, alt);
}

void Textbox::OnVKeyPress(int key, int scan, bool repeat, bool shift, bool ctrl, bool alt)
{
	bool changed = false;
	if (ctrl && scan == SDL_SCANCODE_C && !masked && !repeat)
	{
		copySelection();
		return;
	}
	if (ctrl && scan == SDL_SCANCODE_V && !ReadOnly)
	{
		pasteIntoSelection();
		return;
	}
	if (ctrl && scan == SDL_SCANCODE_X && !masked && !repeat && !ReadOnly)
	{
		cutSelection();
		return;
	}
	if (ctrl && scan == SDL_SCANCODE_A)
	{
		selectAll();
		return;
	}

	try
	{
		switch(key)
		{
		case SDLK_HOME:
			StopTextEditing();
			cursor = 0;
			ClearSelection();
			break;
		case SDLK_END:
			StopTextEditing();
			cursor = backingText.length();
			ClearSelection();
			break;
		case SDLK_LEFT:
			StopTextEditing();
			if(cursor > 0)
				cursor--;
			ClearSelection();
			break;
		case SDLK_RIGHT:
			StopTextEditing();
			if (cursor < (int)backingText.length())
				cursor++;
			ClearSelection();
			break;
		case SDLK_DELETE:
			if(ReadOnly)
				break;
			StopTextEditing();
			if (HasSelection())
			{
				if (getLowerSelectionBound() < 0 || getHigherSelectionBound() > (int)backingText.length())
					return;
				backingText.Erase(getLowerSelectionBound(), getHigherSelectionBound());
				cursor = getLowerSelectionBound();
				changed = true;
			}
			else if (backingText.length() && cursor < (int)backingText.length())
			{
				if (ctrl)
				{
					size_t stopChar;
					stopChar = backingText.SplitByNot(" .,!?\n", cursor).PositionBefore();
					stopChar = backingText.SplitByAny(" .,!?\n", stopChar).PositionBefore();
					backingText.EraseBetween(cursor, stopChar);
				}
				else
					backingText.erase(cursor, 1);
				changed = true;
			}
			ClearSelection();
			break;
		case SDLK_BACKSPACE:
			if (ReadOnly)
				break;
			StopTextEditing();
			if (HasSelection())
			{
				if (getLowerSelectionBound() < 0 || getHigherSelectionBound() > (int)backingText.length())
					return;
				backingText.erase(backingText.begin()+getLowerSelectionBound(), backingText.begin()+getHigherSelectionBound());
				cursor = getLowerSelectionBound();
				changed = true;
			}
			else if (backingText.length() && cursor > 0)
			{
				if (ctrl)
				{
					size_t stopChar;
					stopChar = backingText.SplitFromEndByNot(" .,!?\n", cursor).PositionBefore();
					if (stopChar == backingText.npos)
						stopChar = -1;
					else
						stopChar = backingText.SplitFromEndByAny(" .,!?\n", stopChar).PositionBefore();
					backingText.EraseBetween(stopChar+1, cursor);
					cursor = stopChar+1;
				}
				else
				{
					backingText.erase(cursor-1, 1);
					cursor--;
				}
				changed = true;
			}
			ClearSelection();
			break;
		case SDLK_RETURN:
			OnTextInput("\n");
			break;
		}
	}
	catch (std::out_of_range &e)
	{
		cursor = 0;
		backingText = "";
	}
	AfterTextChange(changed);
}

void Textbox::AfterTextChange(bool changed)
{
	if (cursor > (int)backingText.length())
		cursor = backingText.length();

	if (changed)
	{
		if (inputType == Number)
		{
			//Remove extra preceding 0's
			while(backingText[0] == '0' && backingText.length()>1)
				backingText.erase(backingText.begin());
		}

		if (masked)
		{
			String maskedText = backingText;
			std::fill(maskedText.begin(), maskedText.end(), 0xE00D);
			Label::SetText(maskedText);
		}
		else
		{
			text = backingText;
		}
	}

	updateTextWrapper();
	updateSelection();
	TextPosition(displayTextWrapper.WrappedText());

	resetCursorPosition();
	if (changed && actionCallback.change)
		actionCallback.change();
}

void Textbox::OnTextInput(String text)
{
	StopTextEditing();
	InsertText(text);
}

void Textbox::InsertText(String text)
{
	if (StringValid(text) && !ReadOnly)
	{
		if (HasSelection())
		{
			if (getLowerSelectionBound() < 0 || getHigherSelectionBound() > (int)backingText.length())
				return;
			backingText.erase(backingText.begin()+getLowerSelectionBound(), backingText.begin()+getHigherSelectionBound());
			cursor = getLowerSelectionBound();
		}

		int regionWidth = Size.X;
		if (Appearance.icon)
			regionWidth -= 13;
		regionWidth -= Appearance.Margin.Left;
		regionWidth -= Appearance.Margin.Right;
		if ((limit==String::npos || backingText.length() < limit) && (Graphics::textwidth(backingText + text) <= regionWidth || multiline))
		{
			if (cursor == (int)backingText.length())
			{
				backingText += text;
			}
			else
			{
				backingText.Insert(cursor, text);
			}
			cursor += text.length();
		}
		ClearSelection();
		AfterTextChange(true);
	}
}

void Textbox::StartTextEditing()
{
	if (ReadOnly || textEditing)
	{
		return;
	}
	textEditing = true;
	selectionIndexLSave1 = selectionIndexL.clear_index;
	selectionIndexHSave1 = selectionIndexH.clear_index;
	backingTextSave1 = backingText;
	cursorSave1 = cursor;
	InsertText(String(""));
	selectionIndexLSave2 = selectionIndexL.clear_index;
	selectionIndexHSave2 = selectionIndexH.clear_index;
	backingTextSave2 = backingText;
	cursorSave2 = cursor;
	inputRectPosition.X = cursorPositionX;
	inputRectPosition.Y = cursorPositionY;
}

void Textbox::StopTextEditing()
{
	if (ReadOnly || !textEditing)
	{
		return;
	}
	textEditing = false;
	backingText = backingTextSave1;
	AfterTextChange(true);
	selectionIndexL = textWrapper.Clear2Index(selectionIndexLSave1);
	selectionIndexH = textWrapper.Clear2Index(selectionIndexHSave1);
	selectionIndex0 = selectionIndexL;
	selectionIndex1 = selectionIndexH;
	cursor = cursorSave1;
	updateSelection();
}

void Textbox::OnTextEditing(String text)
{
	if (!StringValid(text) || ReadOnly)
	{
		return;
	}
	if (!text.size())
	{
		StopTextEditing();
		return;
	}
	StartTextEditing();
	backingText = backingTextSave2;
	AfterTextChange(true);
	selectionIndexL = textWrapper.Clear2Index(selectionIndexLSave2);
	selectionIndexH = textWrapper.Clear2Index(selectionIndexHSave2);
	selectionIndex0 = selectionIndexL;
	selectionIndex1 = selectionIndexH;
	cursor = cursorSave2;
	updateSelection();
	InsertText(text);
	selectionIndex1 = textWrapper.Clear2Index(cursor);
	selectionIndex0 = textWrapper.Clear2Index(cursor - int(text.size()));
	selectionIndexL = selectionIndex0;
	selectionIndexH = selectionIndex1;
	updateSelection();
}

void Textbox::OnMouseClick(int x, int y, unsigned button)
{
	if (button != SDL_BUTTON_RIGHT)
	{
		StopTextEditing();
		mouseDown = true;
		auto index = textWrapper.Point2Index(x-textPosition.X, y-textPosition.Y);
		cursor = index.raw_index;
		resetCursorPosition();
	}
	Label::OnMouseClick(x, y, button);
}

void Textbox::OnMouseUp(int x, int y, unsigned button)
{
	mouseDown = false;
	Label::OnMouseUp(x, y, button);
}

void Textbox::OnMouseMoved(int localx, int localy, int dx, int dy)
{
	if(mouseDown)
	{
		auto index = textWrapper.Point2Index(localx-textPosition.X, localy-textPosition.Y);
		cursor = index.raw_index;
		resetCursorPosition();
	}
	Label::OnMouseMoved(localx, localy, dx, dy);
}

void Textbox::OnDefocus()
{
	if (defocusCallback.callback)
		defocusCallback.callback();
}

void Textbox::Draw(const Point& screenPos)
{
	Label::Draw(screenPos);

	Graphics * g = GetGraphics();
	if(IsFocused())
	{
		if(border) g->drawrect(screenPos.X, screenPos.Y, Size.X, Size.Y, 255, 255, 255, 255);
		g->draw_line(screenPos.X+textPosition.X+cursorPositionX, screenPos.Y-2+textPosition.Y+cursorPositionY, screenPos.X+textPosition.X+cursorPositionX, screenPos.Y+9+textPosition.Y+cursorPositionY, 255, 255, 255, 255);
	}
	else
	{
		if(!text.length())
		{
			g->drawtext(screenPos.X+textPosition.X, screenPos.Y+textPosition.Y, placeHolder, textColour.Red, textColour.Green, textColour.Blue, 170);
		}
		if(border) g->drawrect(screenPos.X, screenPos.Y, Size.X, Size.Y, 160, 160, 160, 255);
	}
	if(Appearance.icon)
		g->draw_icon(screenPos.X+iconPosition.X, screenPos.Y+iconPosition.Y, Appearance.icon);
}
