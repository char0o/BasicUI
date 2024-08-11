#include "FontManager.h"
#include <iostream>
#include <filesystem>
FontManager::FontManager()
{

}

FontManager::~FontManager()
{

}

bool FontManager::LoadFont(const std::string& name, const std::string& fileName)
{
	sf::Font font;
	if (font.loadFromFile("fonts/" + fileName))
	{
		this->fonts[name] = font;
		return true;
	}
	return false;
}

sf::Font& FontManager::GetFont(const std::string& name)
{
	return this->fonts.at(name);
}