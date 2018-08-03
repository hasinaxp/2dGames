#include "gameRect.h"

#include "constants.h"

GameRect::GameRect()
{
	m_gameRect.setOutlineColor(sf::Color(255,0,200,255));
	m_gameRect.setPosition(sf::Vector2f(gameRectX -3.0f, gameRectY -3.0f));
	m_gameRect.setSize(sf::Vector2f(gameRectWidth + 3.0f, gameRectHeight + 3.0f));
	m_gameRect.setOutlineThickness(1.0f);
	m_gameRect.setFillColor(sf::Color(255, 0, 100, 60));
}


GameRect::~GameRect()
{
}

sf::RectangleShape GameRect::draw()
{
	return m_gameRect;
}