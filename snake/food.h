#pragma once
#include <SFML/Graphics.hpp>
class Food
{
public:
	Food();
	~Food();
private:

	float rad;
	sf::Clock clock;
	float lostTime;
	int _r;
	int _g;
	int _b;
	sf::CircleShape smallcircle;
public: //variables
	sf::Vector2f smallfoodPos;
public: //methods
	void foodEaten();
	sf::CircleShape renderFood();
};

