#include "UIManager.h"
UIManager::UIManager()
{
	LoadFonts();
}
UIManager::~UIManager()
{

}
void UIManager::LoadFonts()
{
	fontManager.LoadFont("arial", "arial.ttf");
	fontManager.LoadFont("vinque", "vinque.otf");
}
void UIManager::DrawPanels(sf::RenderWindow& window)
{
	for (auto& panel : panels)
	{
		panel->Draw(window);
	}
}
void UIManager::AddPanel(std::shared_ptr<BasePanel> panel)
{
	panels.push_back(panel);
}
void UIManager::RemovePanel(std::shared_ptr<BasePanel> panel)
{
	auto it = std::find(panels.begin(), panels.end(), panel);
	if (it != panels.end())
	{
		panels.erase(it);
	}
}
void UIManager::CheckMouseOver(sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	for (int i = 0; i < panels.size(); i++)
	{
		panels.at(i)->CheckMouseOver(mousePos);
	}
}
void UIManager::CheckMouseClick(sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	bool isClicked = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
	for (int i = 0; i < panels.size(); i++)
	{
		panels.at(i)->CheckMouseClick(mousePos, isClicked);
	}
}
std::shared_ptr<Button> UIManager::CreateButton(
	sf::Vector2f pos, 
	sf::Vector2f size, 
	sf::Color color, 
	std::string text, 
	std::shared_ptr<BasePanel> parent,
	std::string id,
	Button::ClickCallBack callback
	)
{
	std::shared_ptr<Button> button = std::make_shared<Button>();
	button->Init(pos, size, color, parent, id);
	button->SetClickCallBack(callback);
	button->InitText(text, fontManager.GetFont("vinque"), 26, sf::Color::Black);
	button->SetId(id);
	if (parent != nullptr)
	{
		parent->AddChild(button);
	}
	else
	{
		panels.push_back(button);
	}
	return button;
}
std::shared_ptr<BasePanel> UIManager::GetPanelById(std::string id)
{
	for (int i = 0; i < panels.size(); i++)
	{
		if (panels[i]->GetId() == id)
		{
			return panels[i];
		}
	}
	return nullptr;
}
void UIManager::TogglePanel(std::string id, bool enabled)
{
	std::shared_ptr<BasePanel> panel = GetPanelById(id);
	if (panel != nullptr)
	{
		panel->SetEnabled(enabled);
	}
}
std::shared_ptr<Menu> UIManager::CreateMenu(
	sf::Vector2f pos, 
	sf::Vector2f size, 
	sf::Color color, 
	std::shared_ptr<BasePanel> parent, 
	std::string id)
{
	std::shared_ptr<Menu> menu = std::make_shared<Menu>();
	menu->Init(pos, size, color, parent, id);
	if (parent != nullptr)
	{
		parent->AddChild(menu);
	}
	else
	{
		panels.push_back(menu);
	}
	return menu;
}	

void UIManager::ClearPanels()
{
	panels.clear();
}