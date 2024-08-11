#pragma once
#include "BasePanel.h"
#include "SFML/System.hpp"
#include <functional>
class Button : public BasePanel
{
public:
	Button();
	~Button();

	using ClickCallBack = std::function<void()>;
	void SetClickCallBack(ClickCallBack callBack);
	void OnMouseOver() override;
	void OnMouseExit() override;
	void OnMouseClick() override;

private:
	ClickCallBack clickCallBack;

};