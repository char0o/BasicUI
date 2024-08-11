#include "Button.h"
#include <iostream>
Button::Button()
{

}
Button::~Button()
{

}
void Button::OnMouseOver()
{
	this->panel->setFillColor(sf::Color::Green);
}
void Button::OnMouseExit()
{
	this->panel->setFillColor(GetColor());
}
void Button::OnMouseClick()
{
	if (clickCallBack)
	{
		clickCallBack();
	}
}
void Button::SetClickCallBack(ClickCallBack callBack)
{
	clickCallBack = callBack;
}