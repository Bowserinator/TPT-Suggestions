#pragma once
#include "gui/interface/Window.h"

#include <functional>

class ConfirmPrompt : public ui::Window
{
	struct ResultCallback
	{
		std::function<void ()> okay, cancel;
	};

	ResultCallback callback;

public:
	ConfirmPrompt(String title, String message, ResultCallback callback_ = {}, String buttonText = String("Confirm"));
	virtual ~ConfirmPrompt() = default;

	static bool Blocking(String title, String message, String buttonText = String("Confirm"));
	void OnDraw() override;
};
