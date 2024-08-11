#pragma once
#include <memory>
#include "UIManager.h"
#include "../EngineState.h"
#include "../Engine.h"

class Engine;

class MainMenu
{
public:
	MainMenu();
	MainMenu(Engine* engine);
	~MainMenu();
	void CreateButtons();
private:
	Engine* engine;
	bool settingsMenuOpen = false;
};