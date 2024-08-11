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
void Button::Draw(sf::RenderWindow& window)
{
	window.draw(*panelOutline);
	window.draw(*panel);
	window.draw(text);
	for (int i = 0; i < GetChildren().size(); i++)
	{
		GetChildren().at(i)->Draw(window);
	}
}
void Button::InitText(std::string text, sf::Font& font, int fontSize, sf::Color color)
{
	this->text.setFont(font);
	this->text.setString(text);
	this->text.setCharacterSize(fontSize);
	this->text.setFillColor(color);
	this->text.setOrigin(this->text.getGlobalBounds().getSize() / 2.0f + this->text.getLocalBounds().getPosition());
	this->text.setPosition(this->panel->getPosition() + this->panel->getSize() / 2.0f);
}
void Button::SetClickCallBack(ClickCallBack callBack)
{
	clickCallBack = callBack;
}