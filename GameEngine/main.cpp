#include "Engine.h"
#include "EngineState.h"
#include "ui/UIManager.h"
#include "ui/elements/BasePanel.h"
#include "ui/elements/Button.h"
#include "ui/MainMenu.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>
using namespace std;
void main()
{

	Engine engine(800, 600);
	while (engine.GetWindow()->isOpen())
	{
		engine.Run();
	}
}