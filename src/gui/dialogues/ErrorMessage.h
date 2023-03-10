#pragma once
#include "gui/interface/Window.h"

#include <functional>

class ErrorMessage : public ui::Window
{
	struct DismissCallback
	{
		std::function<void ()> dismiss;
	};

	DismissCallback callback;

public:
	ErrorMessage(String title, String message, DismissCallback callback_ = {});
	virtual ~ErrorMessage() = default;

	static void Blocking(String title, String message);
	void OnDraw() override;
};
