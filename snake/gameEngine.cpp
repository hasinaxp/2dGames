#include "gameEngine.h"


gameEngine::gameEngine()
{
	gameState = GameState::MENU;
}


gameEngine::~gameEngine()
{
}

void init();
void gameEngine::gameLoop(sf::RenderWindow &window)
{
	while (gameState != GameState::EXIT)
	{
		while (window.pollEvent(ev))
		{
			userInput();
		}
		update();
		draw(window);
	}
}
void gameEngine::userInput()
{
	if (ev.type == sf::Event::Closed)
		gameState = GameState::EXIT;

	switch (gameState)
	{
	case GameState::CLASSIC:
		
		playerSnake.inputEvent(ev);
		break;
	case GameState::MENU:
		switch (menu.inputEvent(ev))
		{
		case 100:
			gameState = GameState::CLASSIC;
			break;
		}
	default:
		break;
	}
}

void gameEngine::update()
{
	playerSnake.logicSnake();
}
void gameEngine::draw(sf::RenderWindow &window)
{
	switch (gameState)
	{
	case GameState::CLASSIC:
		window.clear(sf::Color(200, 200, 250, 255));
		window.draw(gameRect.draw());
		playerSnake.render(window);
		window.display();
		break;
	case GameState::MENU:
		window.clear(sf::Color(200, 200, 250, 255));
		menu.render(window);
		window.display();
		break;
	default:
		break;
	}
}