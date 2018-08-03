#pragma once
#include "SFML/Graphics.hpp"
#include "PlayerSnake.h"
#include "gameRect.h"
#include "Menu.h"

enum class GameState{ MENU, CLASSIC, EXIT };
class gameEngine
{
public:
	gameEngine();
	~gameEngine();
	void gameLoop(sf::RenderWindow &window);

private:
	void init();
	
	void userInput();
	void draw(sf::RenderWindow &window);
	void update();


private:
	GameState gameState;
	GameRect gameRect;
	PlayerSnake playerSnake;
	Menu menu;
	sf::Event ev;
};

