#pragma once
#include "SFML/System.hpp"
#include <string>
#include "elements/BasePanel.h"
#include "elements/Button.h"
#include "elements/Menu.h"
#include "FontManager.h"
#include <vector>
#include <iostream>
#include <list>
class UIManager
{
public:
	UIManager();
	~UIManager();

	void DrawPanels(sf::RenderWindow& window);
	void AddPanel(std::shared_ptr<BasePanel> panel);
	void RemovePanel(std::shared_ptr<BasePanel> panel);
	void ClearPanels();
	void CheckMouseOver(sf::RenderWindow& window);
	void CheckMouseClick(sf::RenderWindow& window);
	void TogglePanel(std::string id, bool enabled);
	void LoadFonts();
	std::shared_ptr<Button> CreateButton(sf::Vector2f pos,
		sf::Vector2f size,
		sf::Color color,
		std::string text,
		std::shared_ptr<BasePanel> parent,
		std::string id,
		Button::ClickCallBack callback
		);
	std::vector<std::shared_ptr<BasePanel>>& GetPanels() { return panels; }
	std::shared_ptr<Menu> CreateMenu(sf::Vector2f pos,
		sf::Vector2f size,
		sf::Color color,
		std::shared_ptr<BasePanel> parent,
		std::string id);
	std::shared_ptr<BasePanel> GetPanelById(std::string id);
private:
	std::vector<std::shared_ptr<BasePanel>> panels;
	FontManager fontManager;
};