#include <SFML/Graphics.hpp>
#include "constants.h"
#include "gameEngine.h"

int main()
{
	sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), "SnakeGame 2.0.1", sf::Style::Close);

	gameEngine game;
	game.gameLoop(window);
	


	return EXIT_SUCCESS;
}

