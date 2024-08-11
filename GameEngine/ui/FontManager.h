#pragma once
#include <SFML/Graphics.hpp>
#include <map>
class FontManager
{
public:
	FontManager();
	~FontManager();

	bool LoadFont(const std::string& name,const std::string& fileName);
	sf::Font& GetFont(const std::string& name);
private:
	std::map<std::string, sf::Font> fonts;
};