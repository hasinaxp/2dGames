#pragma once
#include "SFML/Graphics.hpp"

class Menu
{
private:
	sf::RectangleShape classicBox;
	sf::RectangleShape exitBox;
public:
	Menu();
	~Menu();

	int inputEvent(sf::Event ev);
	void render(sf::RenderWindow &window);

};

