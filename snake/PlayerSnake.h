#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "food.h"
#include "Score.h"

enum class Direction{UP, DOWN, LEFT, RIGHT};
class PlayerSnake
{
public:
	PlayerSnake();
	~PlayerSnake();

protected://variables
	std::vector<sf::Vector2f> bodyPos;
	//sf::Texture snakeSheet;
private:
	sf::RectangleShape bodyBox;
	sf::RectangleShape headBox;

	Direction direction;

	float frameTime;
	float lostTime;
	float displacement;
	sf::Clock clock;
	Food food;
	Score score;

private: //methods
	void move();
	void addBody(int x, int y);
	void renderScore(sf::RenderWindow &window);
public://methods
	
	void inputEvent(sf::Event ev);
	void render(sf::RenderWindow &window);
	void logicSnake();
	void initSnake();
	

public: //variable
	int numberOfpieces;

};

