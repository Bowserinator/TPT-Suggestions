#pragma once
#include "LuaCompat.h"
#include <SDL.h>

#define SETCONST(L, NAME)\
	lua_pushinteger(L, NAME);\
	lua_setfield(L, -2, #NAME)

static void initLuaSDLKeys(lua_State *l)
{
	SETCONST(l, SDL_SCANCODE_UNKNOWN);
	SETCONST(l, SDL_SCANCODE_A);
	SETCONST(l, SDL_SCANCODE_B);
	SETCONST(l, SDL_SCANCODE_C);
	SETCONST(l, SDL_SCANCODE_D);
	SETCONST(l, SDL_SCANCODE_E);
	SETCONST(l, SDL_SCANCODE_F);
	SETCONST(l, SDL_SCANCODE_G);
	SETCONST(l, SDL_SCANCODE_H);
	SETCONST(l, SDL_SCANCODE_I);
	SETCONST(l, SDL_SCANCODE_J);
	SETCONST(l, SDL_SCANCODE_K);
	SETCONST(l, SDL_SCANCODE_L);
	SETCONST(l, SDL_SCANCODE_M);
	SETCONST(l, SDL_SCANCODE_N);
	SETCONST(l, SDL_SCANCODE_O);
	SETCONST(l, SDL_SCANCODE_P);
	SETCONST(l, SDL_SCANCODE_Q);
	SETCONST(l, SDL_SCANCODE_R);
	SETCONST(l, SDL_SCANCODE_S);
	SETCONST(l, SDL_SCANCODE_T);
	SETCONST(l, SDL_SCANCODE_U);
	SETCONST(l, SDL_SCANCODE_V);
	SETCONST(l, SDL_SCANCODE_W);
	SETCONST(l, SDL_SCANCODE_X);
	SETCONST(l, SDL_SCANCODE_Y);
	SETCONST(l, SDL_SCANCODE_Z);
	SETCONST(l, SDL_SCANCODE_1);
	SETCONST(l, SDL_SCANCODE_2);
	SETCONST(l, SDL_SCANCODE_3);
	SETCONST(l, SDL_SCANCODE_4);
	SETCONST(l, SDL_SCANCODE_5);
	SETCONST(l, SDL_SCANCODE_6);
	SETCONST(l, SDL_SCANCODE_7);
	SETCONST(l, SDL_SCANCODE_8);
	SETCONST(l, SDL_SCANCODE_9);
	SETCONST(l, SDL_SCANCODE_0);
	SETCONST(l, SDL_SCANCODE_RETURN);
	SETCONST(l, SDL_SCANCODE_ESCAPE);
	SETCONST(l, SDL_SCANCODE_BACKSPACE);
	SETCONST(l, SDL_SCANCODE_TAB);
	SETCONST(l, SDL_SCANCODE_SPACE);
	SETCONST(l, SDL_SCANCODE_MINUS);
	SETCONST(l, SDL_SCANCODE_EQUALS);
	SETCONST(l, SDL_SCANCODE_LEFTBRACKET);
	SETCONST(l, SDL_SCANCODE_RIGHTBRACKET);
	SETCONST(l, SDL_SCANCODE_BACKSLASH);
	SETCONST(l, SDL_SCANCODE_NONUSHASH);
	SETCONST(l, SDL_SCANCODE_SEMICOLON);
	SETCONST(l, SDL_SCANCODE_APOSTROPHE);
	SETCONST(l, SDL_SCANCODE_GRAVE);
	SETCONST(l, SDL_SCANCODE_COMMA);
	SETCONST(l, SDL_SCANCODE_PERIOD);
	SETCONST(l, SDL_SCANCODE_SLASH);
	SETCONST(l, SDL_SCANCODE_CAPSLOCK);
	SETCONST(l, SDL_SCANCODE_F1);
	SETCONST(l, SDL_SCANCODE_F2);
	SETCONST(l, SDL_SCANCODE_F3);
	SETCONST(l, SDL_SCANCODE_F4);
	SETCONST(l, SDL_SCANCODE_F5);
	SETCONST(l, SDL_SCANCODE_F6);
	SETCONST(l, SDL_SCANCODE_F7);
	SETCONST(l, SDL_SCANCODE_F8);
	SETCONST(l, SDL_SCANCODE_F9);
	SETCONST(l, SDL_SCANCODE_F10);
	SETCONST(l, SDL_SCANCODE_F11);
	SETCONST(l, SDL_SCANCODE_F12);
	SETCONST(l, SDL_SCANCODE_PRINTSCREEN);
	SETCONST(l, SDL_SCANCODE_SCROLLLOCK);
	SETCONST(l, SDL_SCANCODE_PAUSE);
	SETCONST(l, SDL_SCANCODE_INSERT);
	SETCONST(l, SDL_SCANCODE_HOME);
	SETCONST(l, SDL_SCANCODE_PAGEUP);
	SETCONST(l, SDL_SCANCODE_DELETE);
	SETCONST(l, SDL_SCANCODE_END);
	SETCONST(l, SDL_SCANCODE_PAGEDOWN);
	SETCONST(l, SDL_SCANCODE_RIGHT);
	SETCONST(l, SDL_SCANCODE_LEFT);
	SETCONST(l, SDL_SCANCODE_DOWN);
	SETCONST(l, SDL_SCANCODE_UP);
	SETCONST(l, SDL_SCANCODE_NUMLOCKCLEAR);
	SETCONST(l, SDL_SCANCODE_KP_DIVIDE);
	SETCONST(l, SDL_SCANCODE_KP_MULTIPLY);
	SETCONST(l, SDL_SCANCODE_KP_MINUS);
	SETCONST(l, SDL_SCANCODE_KP_PLUS);
	SETCONST(l, SDL_SCANCODE_KP_ENTER);
	SETCONST(l, SDL_SCANCODE_KP_1);
	SETCONST(l, SDL_SCANCODE_KP_2);
	SETCONST(l, SDL_SCANCODE_KP_3);
	SETCONST(l, SDL_SCANCODE_KP_4);
	SETCONST(l, SDL_SCANCODE_KP_5);
	SETCONST(l, SDL_SCANCODE_KP_6);
	SETCONST(l, SDL_SCANCODE_KP_7);
	SETCONST(l, SDL_SCANCODE_KP_8);
	SETCONST(l, SDL_SCANCODE_KP_9);
	SETCONST(l, SDL_SCANCODE_KP_0);
	SETCONST(l, SDL_SCANCODE_KP_PERIOD);
	SETCONST(l, SDL_SCANCODE_NONUSBACKSLASH);
	SETCONST(l, SDL_SCANCODE_APPLICATION);
	SETCONST(l, SDL_SCANCODE_POWER);
	SETCONST(l, SDL_SCANCODE_KP_EQUALS);
	SETCONST(l, SDL_SCANCODE_F13);
	SETCONST(l, SDL_SCANCODE_F14);
	SETCONST(l, SDL_SCANCODE_F15);
	SETCONST(l, SDL_SCANCODE_F16);
	SETCONST(l, SDL_SCANCODE_F17);
	SETCONST(l, SDL_SCANCODE_F18);
	SETCONST(l, SDL_SCANCODE_F19);
	SETCONST(l, SDL_SCANCODE_F20);
	SETCONST(l, SDL_SCANCODE_F21);
	SETCONST(l, SDL_SCANCODE_F22);
	SETCONST(l, SDL_SCANCODE_F23);
	SETCONST(l, SDL_SCANCODE_F24);
	SETCONST(l, SDL_SCANCODE_EXECUTE);
	SETCONST(l, SDL_SCANCODE_HELP);
	SETCONST(l, SDL_SCANCODE_MENU);
	SETCONST(l, SDL_SCANCODE_SELECT);
	SETCONST(l, SDL_SCANCODE_STOP);
	SETCONST(l, SDL_SCANCODE_AGAIN);
	SETCONST(l, SDL_SCANCODE_UNDO);
	SETCONST(l, SDL_SCANCODE_CUT);
	SETCONST(l, SDL_SCANCODE_COPY);
	SETCONST(l, SDL_SCANCODE_PASTE);
	SETCONST(l, SDL_SCANCODE_FIND);
	SETCONST(l, SDL_SCANCODE_MUTE);
	SETCONST(l, SDL_SCANCODE_VOLUMEUP);
	SETCONST(l, SDL_SCANCODE_VOLUMEDOWN);
	SETCONST(l, SDL_SCANCODE_KP_COMMA);
	SETCONST(l, SDL_SCANCODE_KP_EQUALSAS400);
	SETCONST(l, SDL_SCANCODE_INTERNATIONAL1);
	SETCONST(l, SDL_SCANCODE_INTERNATIONAL2);
	SETCONST(l, SDL_SCANCODE_INTERNATIONAL3);
	SETCONST(l, SDL_SCANCODE_INTERNATIONAL4);
	SETCONST(l, SDL_SCANCODE_INTERNATIONAL5);
	SETCONST(l, SDL_SCANCODE_INTERNATIONAL6);
	SETCONST(l, SDL_SCANCODE_INTERNATIONAL7);
	SETCONST(l, SDL_SCANCODE_INTERNATIONAL8);
	SETCONST(l, SDL_SCANCODE_INTERNATIONAL9);
	SETCONST(l, SDL_SCANCODE_LANG1);
	SETCONST(l, SDL_SCANCODE_LANG2);
	SETCONST(l, SDL_SCANCODE_LANG3);
	SETCONST(l, SDL_SCANCODE_LANG4);
	SETCONST(l, SDL_SCANCODE_LANG5);
	SETCONST(l, SDL_SCANCODE_LANG6);
	SETCONST(l, SDL_SCANCODE_LANG7);
	SETCONST(l, SDL_SCANCODE_LANG8);
	SETCONST(l, SDL_SCANCODE_LANG9);
	SETCONST(l, SDL_SCANCODE_ALTERASE);
	SETCONST(l, SDL_SCANCODE_SYSREQ);
	SETCONST(l, SDL_SCANCODE_CANCEL);
	SETCONST(l, SDL_SCANCODE_CLEAR);
	SETCONST(l, SDL_SCANCODE_PRIOR);
	SETCONST(l, SDL_SCANCODE_RETURN2);
	SETCONST(l, SDL_SCANCODE_SEPARATOR);
	SETCONST(l, SDL_SCANCODE_OUT);
	SETCONST(l, SDL_SCANCODE_OPER);
	SETCONST(l, SDL_SCANCODE_CLEARAGAIN);
	SETCONST(l, SDL_SCANCODE_CRSEL);
	SETCONST(l, SDL_SCANCODE_EXSEL);
	SETCONST(l, SDL_SCANCODE_KP_00);
	SETCONST(l, SDL_SCANCODE_KP_000);
	SETCONST(l, SDL_SCANCODE_THOUSANDSSEPARATOR);
	SETCONST(l, SDL_SCANCODE_DECIMALSEPARATOR);
	SETCONST(l, SDL_SCANCODE_CURRENCYUNIT);
	SETCONST(l, SDL_SCANCODE_CURRENCYSUBUNIT);
	SETCONST(l, SDL_SCANCODE_KP_LEFTPAREN);
	SETCONST(l, SDL_SCANCODE_KP_RIGHTPAREN);
	SETCONST(l, SDL_SCANCODE_KP_LEFTBRACE);
	SETCONST(l, SDL_SCANCODE_KP_RIGHTBRACE);
	SETCONST(l, SDL_SCANCODE_KP_TAB);
	SETCONST(l, SDL_SCANCODE_KP_BACKSPACE);
	SETCONST(l, SDL_SCANCODE_KP_A);
	SETCONST(l, SDL_SCANCODE_KP_B);
	SETCONST(l, SDL_SCANCODE_KP_C);
	SETCONST(l, SDL_SCANCODE_KP_D);
	SETCONST(l, SDL_SCANCODE_KP_E);
	SETCONST(l, SDL_SCANCODE_KP_F);
	SETCONST(l, SDL_SCANCODE_KP_XOR);
	SETCONST(l, SDL_SCANCODE_KP_POWER);
	SETCONST(l, SDL_SCANCODE_KP_PERCENT);
	SETCONST(l, SDL_SCANCODE_KP_LESS);
	SETCONST(l, SDL_SCANCODE_KP_GREATER);
	SETCONST(l, SDL_SCANCODE_KP_AMPERSAND);
	SETCONST(l, SDL_SCANCODE_KP_DBLAMPERSAND);
	SETCONST(l, SDL_SCANCODE_KP_VERTICALBAR);
	SETCONST(l, SDL_SCANCODE_KP_DBLVERTICALBAR);
	SETCONST(l, SDL_SCANCODE_KP_COLON);
	SETCONST(l, SDL_SCANCODE_KP_HASH);
	SETCONST(l, SDL_SCANCODE_KP_SPACE);
	SETCONST(l, SDL_SCANCODE_KP_AT);
	SETCONST(l, SDL_SCANCODE_KP_EXCLAM);
	SETCONST(l, SDL_SCANCODE_KP_MEMSTORE);
	SETCONST(l, SDL_SCANCODE_KP_MEMRECALL);
	SETCONST(l, SDL_SCANCODE_KP_MEMCLEAR);
	SETCONST(l, SDL_SCANCODE_KP_MEMADD);
	SETCONST(l, SDL_SCANCODE_KP_MEMSUBTRACT);
	SETCONST(l, SDL_SCANCODE_KP_MEMMULTIPLY);
	SETCONST(l, SDL_SCANCODE_KP_MEMDIVIDE);
	SETCONST(l, SDL_SCANCODE_KP_PLUSMINUS);
	SETCONST(l, SDL_SCANCODE_KP_CLEAR);
	SETCONST(l, SDL_SCANCODE_KP_CLEARENTRY);
	SETCONST(l, SDL_SCANCODE_KP_BINARY);
	SETCONST(l, SDL_SCANCODE_KP_OCTAL);
	SETCONST(l, SDL_SCANCODE_KP_DECIMAL);
	SETCONST(l, SDL_SCANCODE_KP_HEXADECIMAL);
	SETCONST(l, SDL_SCANCODE_LCTRL);
	SETCONST(l, SDL_SCANCODE_LSHIFT);
	SETCONST(l, SDL_SCANCODE_LALT);
	SETCONST(l, SDL_SCANCODE_LGUI);
	SETCONST(l, SDL_SCANCODE_RCTRL);
	SETCONST(l, SDL_SCANCODE_RSHIFT);
	SETCONST(l, SDL_SCANCODE_RALT);
	SETCONST(l, SDL_SCANCODE_RGUI);
	SETCONST(l, SDL_SCANCODE_MODE);
	SETCONST(l, SDL_SCANCODE_AUDIONEXT);
	SETCONST(l, SDL_SCANCODE_AUDIOPREV);
	SETCONST(l, SDL_SCANCODE_AUDIOSTOP);
	SETCONST(l, SDL_SCANCODE_AUDIOPLAY);
	SETCONST(l, SDL_SCANCODE_AUDIOMUTE);
	SETCONST(l, SDL_SCANCODE_MEDIASELECT);
	SETCONST(l, SDL_SCANCODE_WWW);
	SETCONST(l, SDL_SCANCODE_MAIL);
	SETCONST(l, SDL_SCANCODE_CALCULATOR);
	SETCONST(l, SDL_SCANCODE_COMPUTER);
	SETCONST(l, SDL_SCANCODE_AC_SEARCH);
	SETCONST(l, SDL_SCANCODE_AC_HOME);
	SETCONST(l, SDL_SCANCODE_AC_BACK);
	SETCONST(l, SDL_SCANCODE_AC_FORWARD);
	SETCONST(l, SDL_SCANCODE_AC_STOP);
	SETCONST(l, SDL_SCANCODE_AC_REFRESH);
	SETCONST(l, SDL_SCANCODE_AC_BOOKMARKS);
	SETCONST(l, SDL_SCANCODE_BRIGHTNESSDOWN);
	SETCONST(l, SDL_SCANCODE_BRIGHTNESSUP);
	SETCONST(l, SDL_SCANCODE_DISPLAYSWITCH);
	SETCONST(l, SDL_SCANCODE_KBDILLUMTOGGLE);
	SETCONST(l, SDL_SCANCODE_KBDILLUMDOWN);
	SETCONST(l, SDL_SCANCODE_KBDILLUMUP);
	SETCONST(l, SDL_SCANCODE_EJECT);
	SETCONST(l, SDL_SCANCODE_SLEEP);
	SETCONST(l, SDL_SCANCODE_APP1);
	SETCONST(l, SDL_SCANCODE_APP2);
	SETCONST(l, SDL_SCANCODE_AUDIOREWIND);
	SETCONST(l, SDL_SCANCODE_AUDIOFASTFORWARD);
	SETCONST(l, SDL_NUM_SCANCODES);
	SETCONST(l, SDLK_UNKNOWN);
	SETCONST(l, SDLK_RETURN);
	SETCONST(l, SDLK_ESCAPE);
	SETCONST(l, SDLK_BACKSPACE);
	SETCONST(l, SDLK_TAB);
	SETCONST(l, SDLK_SPACE);
	SETCONST(l, SDLK_EXCLAIM);
	SETCONST(l, SDLK_QUOTEDBL);
	SETCONST(l, SDLK_HASH);
	SETCONST(l, SDLK_PERCENT);
	SETCONST(l, SDLK_DOLLAR);
	SETCONST(l, SDLK_AMPERSAND);
	SETCONST(l, SDLK_QUOTE);
	SETCONST(l, SDLK_LEFTPAREN);
	SETCONST(l, SDLK_RIGHTPAREN);
	SETCONST(l, SDLK_ASTERISK);
	SETCONST(l, SDLK_PLUS);
	SETCONST(l, SDLK_COMMA);
	SETCONST(l, SDLK_MINUS);
	SETCONST(l, SDLK_PERIOD);
	SETCONST(l, SDLK_SLASH);
	SETCONST(l, SDLK_0);
	SETCONST(l, SDLK_1);
	SETCONST(l, SDLK_2);
	SETCONST(l, SDLK_3);
	SETCONST(l, SDLK_4);
	SETCONST(l, SDLK_5);
	SETCONST(l, SDLK_6);
	SETCONST(l, SDLK_7);
	SETCONST(l, SDLK_8);
	SETCONST(l, SDLK_9);
	SETCONST(l, SDLK_COLON);
	SETCONST(l, SDLK_SEMICOLON);
	SETCONST(l, SDLK_LESS);
	SETCONST(l, SDLK_EQUALS);
	SETCONST(l, SDLK_GREATER);
	SETCONST(l, SDLK_QUESTION);
	SETCONST(l, SDLK_AT);
	SETCONST(l, SDLK_LEFTBRACKET);
	SETCONST(l, SDLK_BACKSLASH);
	SETCONST(l, SDLK_RIGHTBRACKET);
	SETCONST(l, SDLK_CARET);
	SETCONST(l, SDLK_UNDERSCORE);
	SETCONST(l, SDLK_BACKQUOTE);
	SETCONST(l, SDLK_a);
	SETCONST(l, SDLK_b);
	SETCONST(l, SDLK_c);
	SETCONST(l, SDLK_d);
	SETCONST(l, SDLK_e);
	SETCONST(l, SDLK_f);
	SETCONST(l, SDLK_g);
	SETCONST(l, SDLK_h);
	SETCONST(l, SDLK_i);
	SETCONST(l, SDLK_j);
	SETCONST(l, SDLK_k);
	SETCONST(l, SDLK_l);
	SETCONST(l, SDLK_m);
	SETCONST(l, SDLK_n);
	SETCONST(l, SDLK_o);
	SETCONST(l, SDLK_p);
	SETCONST(l, SDLK_q);
	SETCONST(l, SDLK_r);
	SETCONST(l, SDLK_s);
	SETCONST(l, SDLK_t);
	SETCONST(l, SDLK_u);
	SETCONST(l, SDLK_v);
	SETCONST(l, SDLK_w);
	SETCONST(l, SDLK_x);
	SETCONST(l, SDLK_y);
	SETCONST(l, SDLK_z);
	SETCONST(l, SDLK_CAPSLOCK);
	SETCONST(l, SDLK_F1);
	SETCONST(l, SDLK_F2);
	SETCONST(l, SDLK_F3);
	SETCONST(l, SDLK_F4);
	SETCONST(l, SDLK_F5);
	SETCONST(l, SDLK_F6);
	SETCONST(l, SDLK_F7);
	SETCONST(l, SDLK_F8);
	SETCONST(l, SDLK_F9);
	SETCONST(l, SDLK_F10);
	SETCONST(l, SDLK_F11);
	SETCONST(l, SDLK_F12);
	SETCONST(l, SDLK_PRINTSCREEN);
	SETCONST(l, SDLK_SCROLLLOCK);
	SETCONST(l, SDLK_PAUSE);
	SETCONST(l, SDLK_INSERT);
	SETCONST(l, SDLK_HOME);
	SETCONST(l, SDLK_PAGEUP);
	SETCONST(l, SDLK_DELETE);
	SETCONST(l, SDLK_END);
	SETCONST(l, SDLK_PAGEDOWN);
	SETCONST(l, SDLK_RIGHT);
	SETCONST(l, SDLK_LEFT);
	SETCONST(l, SDLK_DOWN);
	SETCONST(l, SDLK_UP);
	SETCONST(l, SDLK_NUMLOCKCLEAR);
	SETCONST(l, SDLK_KP_DIVIDE);
	SETCONST(l, SDLK_KP_MULTIPLY);
	SETCONST(l, SDLK_KP_MINUS);
	SETCONST(l, SDLK_KP_PLUS);
	SETCONST(l, SDLK_KP_ENTER);
	SETCONST(l, SDLK_KP_1);
	SETCONST(l, SDLK_KP_2);
	SETCONST(l, SDLK_KP_3);
	SETCONST(l, SDLK_KP_4);
	SETCONST(l, SDLK_KP_5);
	SETCONST(l, SDLK_KP_6);
	SETCONST(l, SDLK_KP_7);
	SETCONST(l, SDLK_KP_8);
	SETCONST(l, SDLK_KP_9);
	SETCONST(l, SDLK_KP_0);
	SETCONST(l, SDLK_KP_PERIOD);
	SETCONST(l, SDLK_APPLICATION);
	SETCONST(l, SDLK_POWER);
	SETCONST(l, SDLK_KP_EQUALS);
	SETCONST(l, SDLK_F13);
	SETCONST(l, SDLK_F14);
	SETCONST(l, SDLK_F15);
	SETCONST(l, SDLK_F16);
	SETCONST(l, SDLK_F17);
	SETCONST(l, SDLK_F18);
	SETCONST(l, SDLK_F19);
	SETCONST(l, SDLK_F20);
	SETCONST(l, SDLK_F21);
	SETCONST(l, SDLK_F22);
	SETCONST(l, SDLK_F23);
	SETCONST(l, SDLK_F24);
	SETCONST(l, SDLK_EXECUTE);
	SETCONST(l, SDLK_HELP);
	SETCONST(l, SDLK_MENU);
	SETCONST(l, SDLK_SELECT);
	SETCONST(l, SDLK_STOP);
	SETCONST(l, SDLK_AGAIN);
	SETCONST(l, SDLK_UNDO);
	SETCONST(l, SDLK_CUT);
	SETCONST(l, SDLK_COPY);
	SETCONST(l, SDLK_PASTE);
	SETCONST(l, SDLK_FIND);
	SETCONST(l, SDLK_MUTE);
	SETCONST(l, SDLK_VOLUMEUP);
	SETCONST(l, SDLK_VOLUMEDOWN);
	SETCONST(l, SDLK_KP_COMMA);
	SETCONST(l, SDLK_KP_EQUALSAS400);
	SETCONST(l, SDLK_ALTERASE);
	SETCONST(l, SDLK_SYSREQ);
	SETCONST(l, SDLK_CANCEL);
	SETCONST(l, SDLK_CLEAR);
	SETCONST(l, SDLK_PRIOR);
	SETCONST(l, SDLK_RETURN2);
	SETCONST(l, SDLK_SEPARATOR);
	SETCONST(l, SDLK_OUT);
	SETCONST(l, SDLK_OPER);
	SETCONST(l, SDLK_CLEARAGAIN);
	SETCONST(l, SDLK_CRSEL);
	SETCONST(l, SDLK_EXSEL);
	SETCONST(l, SDLK_KP_00);
	SETCONST(l, SDLK_KP_000);
	SETCONST(l, SDLK_THOUSANDSSEPARATOR);
	SETCONST(l, SDLK_DECIMALSEPARATOR);
	SETCONST(l, SDLK_CURRENCYUNIT);
	SETCONST(l, SDLK_CURRENCYSUBUNIT);
	SETCONST(l, SDLK_KP_LEFTPAREN);
	SETCONST(l, SDLK_KP_RIGHTPAREN);
	SETCONST(l, SDLK_KP_LEFTBRACE);
	SETCONST(l, SDLK_KP_RIGHTBRACE);
	SETCONST(l, SDLK_KP_TAB);
	SETCONST(l, SDLK_KP_BACKSPACE);
	SETCONST(l, SDLK_KP_A);
	SETCONST(l, SDLK_KP_B);
	SETCONST(l, SDLK_KP_C);
	SETCONST(l, SDLK_KP_D);
	SETCONST(l, SDLK_KP_E);
	SETCONST(l, SDLK_KP_F);
	SETCONST(l, SDLK_KP_XOR);
	SETCONST(l, SDLK_KP_POWER);
	SETCONST(l, SDLK_KP_PERCENT);
	SETCONST(l, SDLK_KP_LESS);
	SETCONST(l, SDLK_KP_GREATER);
	SETCONST(l, SDLK_KP_AMPERSAND);
	SETCONST(l, SDLK_KP_DBLAMPERSAND);
	SETCONST(l, SDLK_KP_VERTICALBAR);
	SETCONST(l, SDLK_KP_DBLVERTICALBAR);
	SETCONST(l, SDLK_KP_COLON);
	SETCONST(l, SDLK_KP_HASH);
	SETCONST(l, SDLK_KP_SPACE);
	SETCONST(l, SDLK_KP_AT);
	SETCONST(l, SDLK_KP_EXCLAM);
	SETCONST(l, SDLK_KP_MEMSTORE);
	SETCONST(l, SDLK_KP_MEMRECALL);
	SETCONST(l, SDLK_KP_MEMCLEAR);
	SETCONST(l, SDLK_KP_MEMADD);
	SETCONST(l, SDLK_KP_MEMSUBTRACT);
	SETCONST(l, SDLK_KP_MEMMULTIPLY);
	SETCONST(l, SDLK_KP_MEMDIVIDE);
	SETCONST(l, SDLK_KP_PLUSMINUS);
	SETCONST(l, SDLK_KP_CLEAR);
	SETCONST(l, SDLK_KP_CLEARENTRY);
	SETCONST(l, SDLK_KP_BINARY);
	SETCONST(l, SDLK_KP_OCTAL);
	SETCONST(l, SDLK_KP_DECIMAL);
	SETCONST(l, SDLK_KP_HEXADECIMAL);
	SETCONST(l, SDLK_LCTRL);
	SETCONST(l, SDLK_LSHIFT);
	SETCONST(l, SDLK_LALT);
	SETCONST(l, SDLK_LGUI);
	SETCONST(l, SDLK_RCTRL);
	SETCONST(l, SDLK_RSHIFT);
	SETCONST(l, SDLK_RALT);
	SETCONST(l, SDLK_RGUI);
	SETCONST(l, SDLK_MODE);
	SETCONST(l, SDLK_AUDIONEXT);
	SETCONST(l, SDLK_AUDIOPREV);
	SETCONST(l, SDLK_AUDIOSTOP);
	SETCONST(l, SDLK_AUDIOPLAY);
	SETCONST(l, SDLK_AUDIOMUTE);
	SETCONST(l, SDLK_MEDIASELECT);
	SETCONST(l, SDLK_WWW);
	SETCONST(l, SDLK_MAIL);
	SETCONST(l, SDLK_CALCULATOR);
	SETCONST(l, SDLK_COMPUTER);
	SETCONST(l, SDLK_AC_SEARCH);
	SETCONST(l, SDLK_AC_HOME);
	SETCONST(l, SDLK_AC_BACK);
	SETCONST(l, SDLK_AC_FORWARD);
	SETCONST(l, SDLK_AC_STOP);
	SETCONST(l, SDLK_AC_REFRESH);
	SETCONST(l, SDLK_AC_BOOKMARKS);
	SETCONST(l, SDLK_BRIGHTNESSDOWN);
	SETCONST(l, SDLK_BRIGHTNESSUP);
	SETCONST(l, SDLK_DISPLAYSWITCH);
	SETCONST(l, SDLK_KBDILLUMTOGGLE);
	SETCONST(l, SDLK_KBDILLUMDOWN);
	SETCONST(l, SDLK_KBDILLUMUP);
	SETCONST(l, SDLK_EJECT);
	SETCONST(l, SDLK_SLEEP);
	SETCONST(l, SDLK_APP1);
	SETCONST(l, SDLK_APP2);
	SETCONST(l, SDLK_AUDIOREWIND);
	SETCONST(l, SDLK_AUDIOFASTFORWARD);
	SETCONST(l, KMOD_NONE);
	SETCONST(l, KMOD_LSHIFT);
	SETCONST(l, KMOD_RSHIFT);
	SETCONST(l, KMOD_LCTRL);
	SETCONST(l, KMOD_RCTRL);
	SETCONST(l, KMOD_LALT);
	SETCONST(l, KMOD_RALT);
	SETCONST(l, KMOD_LGUI);
	SETCONST(l, KMOD_RGUI);
	SETCONST(l, KMOD_NUM);
	SETCONST(l, KMOD_CAPS);
	SETCONST(l, KMOD_MODE);
	SETCONST(l, KMOD_CTRL);
	SETCONST(l, KMOD_SHIFT);
	SETCONST(l, KMOD_ALT);
	SETCONST(l, KMOD_GUI);
	SETCONST(l, SDL_BUTTON_LEFT);
	SETCONST(l, SDL_BUTTON_MIDDLE);
	SETCONST(l, SDL_BUTTON_RIGHT);
	SETCONST(l, SDL_BUTTON_X1);
	SETCONST(l, SDL_BUTTON_X2);
}

#undef SETCONST
