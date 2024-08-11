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
	void InitText(std::string text, sf::Font& font, int fontSize, sf::Color color);
	void OnMouseOver() override;
	void OnMouseExit() override;
	void OnMouseClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	ClickCallBack clickCallBack;
	sf::Text text;
};