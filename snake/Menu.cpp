#include "Menu.h"
#include "constants.h"


Menu::Menu()
{
	
}


Menu::~Menu()
{
}

int Menu::inputEvent(sf::Event ev)
{

	return 0;
}
void Menu::render(sf::RenderWindow &window)
{
	sf::Font font;
	font.loadFromFile("assets/font.ttf");
	sf::Text playClassic;
	playClassic.setFont(font);
	playClassic.setCharacterSize(60);
	playClassic.setFillColor(sf::Color(230, 240, 250, 200));
	playClassic.setOutlineThickness(7.0f);
	playClassic.setOutlineColor(sf::Color(0, 200, 255, 255));
	playClassic.setPosition(sf::Vector2f((screenWidth / 2 - 50), (screenHeight * 1 / 4)));
	playClassic.setString("PLAY");
	window.draw(playClassic);
	playClassic.setPosition(sf::Vector2f((screenWidth / 2 - 50), (screenHeight * 2 / 4)));
	playClassic.setString("EXIT");
	window.draw(playClassic);
	window.draw(classicBox);
	window.draw(exitBox);
}
