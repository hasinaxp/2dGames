#include "food.h"
#include <cstdlib>
#include <ctime>
#include "constants.h"
#include <iostream>

Food::Food()
{
	std::srand(std::time(0));
	smallfoodPos.x = (rand() % (mapBlocCountX -2) + 2) * blocX;
	smallfoodPos.y = (rand() % (mapBlocCountY - 2) + 2) * blocY;
	_r = 200; _g = 20; _b = 155;
	rad = 1.0f;
	lostTime = clock.restart().asSeconds();
}


Food::~Food()
{
}

void Food::foodEaten()
{
	smallfoodPos.x = (rand() % (mapBlocCountX - 2) + 2) * blocX;
	smallfoodPos.y = (rand() % (mapBlocCountY - 2) + 2) * blocY;
}
sf::CircleShape Food::renderFood()
{
	lostTime = clock.getElapsedTime().asSeconds();
	if (lostTime > 0.02f)
	{
		rad += 0.5f;
		lostTime = clock.restart().asSeconds();
	}
	smallcircle.setPointCount(4);
	smallcircle.setPosition(smallfoodPos);
	smallcircle.setFillColor(sf::Color(_r, _g, _b, 200));
	smallcircle.setRadius(rad);
	//std::cout << "smallfoodPos : " << smallfoodPos.x << " " << smallfoodPos.y << std::endl;
	if (rad > 9.5f)
		rad = 1.0f;
	return smallcircle;
}