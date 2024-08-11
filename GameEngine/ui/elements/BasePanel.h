#pragma once
#include <vector>
#include <memory>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
class BasePanel
{
public:
	void AddChild(std::shared_ptr<BasePanel> child);
	void RemoveChild(std::shared_ptr<BasePanel> child);
	void SetParent(std::shared_ptr<BasePanel> parent);
	std::shared_ptr<BasePanel> GetParent();
	std::vector<std::shared_ptr<BasePanel>>& GetChildren();
	void SetId(std::string id) { this->id = id; }
	std::string GetId() { return id; }
	virtual void Draw(sf::RenderWindow& window);
	sf::Vector2f GetPos() { return pos; }
	sf::Vector2f GetSize() { return size; }
	sf::Color GetColor() { return color; }
	void SetPos(sf::Vector2f pos);
	void SetSize(sf::Vector2f size) { this->size = size; }
	void SetColor(sf::Color color) { this->color = color; }
	bool CheckMouseOver(sf::Vector2i mousePos);
	bool CheckMouseClick(sf::Vector2i mousePos, bool isClicked);
	void SetEnabled(bool enabled) { this->enabled = enabled; }
	bool GetEnabled() { return enabled; }
	void Init(const sf::Vector2f pos, 
		const sf::Vector2f size, 
		const sf::Color color, 
		const std::shared_ptr<BasePanel> parent,
		std::string id);
	virtual void OnMouseOver() = 0;
	virtual void OnMouseExit() = 0;
	virtual void OnMouseClick() = 0;
protected:
	std::unique_ptr<sf::RectangleShape> panel;
	std::unique_ptr<sf::RectangleShape> panelOutline;
	bool exited;
private:
	bool enabled = true;
	std::vector<std::shared_ptr<BasePanel>> children;
	std::shared_ptr<BasePanel> parent;
	sf::Vector2f pos;
	sf::Vector2f size;
	sf::Color color;
	std::string id;
};