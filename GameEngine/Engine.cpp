#include "Engine.h"

Engine::Engine()
{
	State = EngineState::MainMenu;
}
Engine::Engine(int width, int height)
{
	this->font.loadFromFile("arial.ttf");
	this->WindowWidth = width;
	this->WindowHeight = height;
	this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), "Game Engine");
	this->window->setFramerateLimit(60);
	State = EngineState::MainMenu;
	uiManager = std::make_unique<UIManager>();
}
Engine::~Engine()
{
}
void Engine::Initialize()
{

}
void Engine::Run()
{
	sf::Event event;
	bool mainMenuCreated = false;
	std::shared_ptr<MainMenu> mainMenu = nullptr;
	while (State != EngineState::Quit)
	{
		if (State == EngineState::MainMenu)
		{
			if (!mainMenuCreated)
			{
				mainMenu = std::make_shared<MainMenu>(this);
				mainMenuCreated = true;
			}
			window->clear(sf::Color(100, 100, 100, 255));
			uiManager->DrawPanels(*window);
			uiManager->CheckMouseOver(*window);
			uiManager->CheckMouseClick(*window);
			PollEvents();
			window->display();
			//[this, button]()
			//	{
			//		std::shared_ptr<BasePanel> parent = button->GetParent();
			//		std::shared_ptr<BasePanel> current = button;
			//		while (parent != nullptr)
			//		{
			//			current = parent;
			//			parent = current->GetParent();
			//		}
			//		this->RemovePanel(current);

			//	}
		}
		else if (State == EngineState::Game)
		{
			PollEvents();
		}
	}
	window->close();
}

void Engine::PollEvents()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window->close();
			State = EngineState::Quit;
		}
	}
}