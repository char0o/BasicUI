#include "BasePanel.h"
#include "SFML/Graphics.hpp"

void BasePanel::AddChild(std::shared_ptr<BasePanel> child)
{
	children.push_back(child);
}

void BasePanel::RemoveChild(std::shared_ptr<BasePanel> child)
{
	int i = 0;
	for (int i = 0; i < children.size(); i++)
	{
		if (children[i] == child)
		{
			children.erase(children.begin() + i);
			break;
		}
	}
}
void BasePanel::Init(const sf::Vector2f pos,
	const sf::Vector2f size,
	const sf::Color color,
	const std::shared_ptr<BasePanel> parent,
	std::string id)
{
	if (parent != nullptr)
	{
		this->SetParent(parent);
	}
	this->SetId(id);
	this->SetPos(pos);
	this->SetSize(size);
	this->SetColor(color);
	panel = std::make_unique<sf::RectangleShape>();
	panel->setPosition(GetPos());
	panel->setSize(GetSize());
	panel->setFillColor(GetColor());
	panelOutline = std::make_unique<sf::RectangleShape>();
	panelOutline->setPosition(GetPos() + sf::Vector2f(3, 3));
	panelOutline->setSize(GetSize());
	panelOutline->setFillColor(sf::Color(0, 0, 0, 125));
}
void BasePanel::SetParent(std::shared_ptr<BasePanel> parent)
{
	this->parent = parent;
}
void BasePanel::SetPos(sf::Vector2f pos)
{
	if (parent != nullptr)
	{
		this->pos = parent->GetPos() + pos;
	}
	else
	{
		this->pos = pos;
	}
}
std::shared_ptr<BasePanel> BasePanel::GetParent()
{
	return parent;
}
std::vector<std::shared_ptr<BasePanel>>& BasePanel::GetChildren()
{
	return children;
}
void BasePanel::Draw(sf::RenderWindow& window)
{
	window.draw(*panelOutline);
	window.draw(*panel);
	
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->Draw(window);
	}
}

bool BasePanel::CheckMouseOver(sf::Vector2i mousePos)
{
	if (!enabled)
	{
		return false;
	}
	bool childrenOver = false;
	for (int i = 0; i < children.size(); i++)
	{
		childrenOver = children[i]->CheckMouseOver(mousePos) || childrenOver;
	}
	if (this->panel->getGlobalBounds().contains(mousePos.x, mousePos.y) && !childrenOver)
	{
		OnMouseOver();
		return true;
	}
	else
	{
		OnMouseExit();
		return false;
	}
}
bool BasePanel::CheckMouseClick(sf::Vector2i mousePos, bool isClicked)
{
	if (!enabled)
	{
		return false;
	}
	bool childrenClicked = false;
	for (int i = 0; i < children.size(); i++)
	{
		childrenClicked = children[i]->CheckMouseClick(mousePos, isClicked) || childrenClicked;
	}
	if (this->panel->getGlobalBounds().contains(mousePos.x, mousePos.y) && isClicked && !childrenClicked)
	{
		OnMouseClick();
		return true;
	}
	else
	{
		return false;
	}
}