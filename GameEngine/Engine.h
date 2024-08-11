#pragma once
#include <memory>
#include "EngineState.h"
#include "SFML/Graphics.hpp"
#include "ui/UIManager.h"
#include "ui/elements/Button.h"
#include "ui/elements/BasePanel.h"
#include "ui/MainMenu.h"
#include "ui/FontManager.h"
#include "string"
class Engine
{
public:
	Engine();
	Engine(int width, int height);
	~Engine();

	std::shared_ptr<sf::RenderWindow> GetWindow() { return window; }
	void Initialize();
	void Run();
	void Shutdown();
	void PollEvents();
	std::unique_ptr<UIManager>& GetUIManager() { return uiManager; }
	void SetState(EngineState state);
	EngineState GetState();
	int WindowWidth;
	int WindowHeight;
private:
	EngineState State;
	sf::RenderWindow Window;
	std::shared_ptr<sf::RenderWindow> window;
	std::unique_ptr<UIManager> uiManager;

};