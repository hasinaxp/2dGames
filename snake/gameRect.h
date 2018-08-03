#pragma once
#include <SFML/Graphics.hpp>
class GameRect
{
public:
	GameRect();
	~GameRect();
	
	sf::RectangleShape draw();
private:
	sf::RectangleShape m_gameRect;
};

