#include "MainMenu.h"
#include <iostream>
MainMenu::MainMenu()
{

}
MainMenu::MainMenu(Engine* engine)
{
	this->engine = engine;
	CreateButtons();
}
MainMenu::~MainMenu() 
{

}
void MainMenu::CreateButtons()
{
	int width = engine->WindowWidth / 2;
	int height = engine->WindowHeight / 2;
	std::shared_ptr<Button> playButton = engine->GetUIManager()->CreateButton(sf::Vector2f(width - 50, height), 
		sf::Vector2f(100, 50), 
		sf::Color::Green, 
		"Exit", 
		nullptr,
		"playButton",
		[this]()
		{
			engine->SetState(EngineState::Quit);
		});
	std::shared_ptr<Button> settingsButton = engine->GetUIManager()->CreateButton(sf::Vector2f(width - 50, height + 100), 
		sf::Vector2f(100, 50), 
		sf::Color::Yellow, 
		"Exit", 
		nullptr,
		"settingsButton",
		[this]()
		{
			if (!settingsMenuOpen)
			{
				engine->GetUIManager()->TogglePanel("playButton", false);
				engine->GetUIManager()->TogglePanel("settingsButton", false);
				engine->GetUIManager()->TogglePanel("exitButton", false);
				settingsMenuOpen = true;
				std::shared_ptr<Menu> settingsMenu = engine->GetUIManager()->CreateMenu(sf::Vector2f(200, 200), 
					sf::Vector2f(300, 300), 
					sf::Color::Blue, 
					nullptr,
					"settingsMenu");
				engine->GetUIManager()->CreateButton(sf::Vector2f(settingsMenu->GetSize().x - 55, 5), 
					sf::Vector2f(50, 50), 
					sf::Color::Red, 
					"Exit", 
					settingsMenu,
					"settingsMenuButton",
					[this, settingsMenu]()
					{
						engine->GetUIManager()->RemovePanel(settingsMenu);
						settingsMenuOpen = false;
						engine->GetUIManager()->TogglePanel("playButton", true);
						engine->GetUIManager()->TogglePanel("settingsButton", true);
						engine->GetUIManager()->TogglePanel("exitButton", true);
					});
			}
		});
	std::shared_ptr<Button> exitButton = engine->GetUIManager()->CreateButton(sf::Vector2f(width - 50, height + 200), 
		sf::Vector2f(100, 50), 
		sf::Color::Red, 
		"Exit", 
		nullptr,
		"exitButton",
		[this]()
		{
			engine->SetState(EngineState::Quit);
		});
}