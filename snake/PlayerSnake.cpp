#include "PlayerSnake.h"
#include "constants.h"
#include <iostream>
#include <cstdlib>


PlayerSnake::PlayerSnake()
{
	//snakeSheet.loadFromFile("assets/image/snake.png");
	//snakeSheet.setSmooth(true);
	
	initSnake();
}


PlayerSnake::~PlayerSnake()
{
}

void PlayerSnake::inputEvent(sf::Event ev)
{
	
	if ((ev.type == sf::Event::KeyPressed) && (ev.key.code == sf::Keyboard::Right))
	{
		if (direction != Direction::LEFT)
		direction = Direction::RIGHT;
		
	}
	else if ((ev.type == sf::Event::KeyPressed) && (ev.key.code == sf::Keyboard::Left))
	{
		if (direction != Direction::RIGHT)
		direction = Direction::LEFT;
		
	}
	else if ((ev.type == sf::Event::KeyPressed) && (ev.key.code == sf::Keyboard::Up))
	{
		if(direction != Direction::DOWN)
		direction = Direction::UP;
		
	}
	else if ((ev.type == sf::Event::KeyPressed) && (ev.key.code == sf::Keyboard::Down))
	{
		if (direction!= Direction::UP)
		direction = Direction::DOWN;
		
	}

	if ((ev.type == sf::Event::KeyPressed) && (ev.key.code == sf::Keyboard::E))
		frameTime = 0.07f;
	if ((ev.type == sf::Event::KeyPressed) && (ev.key.code == sf::Keyboard::R))
		frameTime = 0.5f;
	

}
void PlayerSnake::render(sf::RenderWindow &window)
{
	headBox.setPosition(bodyPos[0]);
	window.draw(headBox);
	for (int i = 1; i < numberOfpieces; i++)
	{
		if (i % 2 == 0)
		{
			bodyBox.setOutlineColor(sf::Color(0, 150, 255, 255));
			bodyBox.setFillColor(sf::Color(0, 150, 255, 100));
		}
		else
		{
			bodyBox.setOutlineColor(sf::Color(0, 250, 155, 255));
			bodyBox.setFillColor(sf::Color(0, 250, 155, 100));
		}
		bodyBox.setPosition(bodyPos[i]);
		window.draw(bodyBox);
	}
	window.draw(food.renderFood());

	renderScore(window);
	
}

void PlayerSnake::renderScore(sf::RenderWindow &window)
{
	sf::Font font;
	font.loadFromFile("assets/font.ttf");

	sf::Text scoreText;
	scoreText.setFont(font);
	scoreText.setString(score.scoreString());
	scoreText.setCharacterSize(30);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setOutlineThickness(5.0f);
	scoreText.setOutlineColor(sf::Color(0, 200, 255, 255));
	scoreText.setStyle(sf::Text::Bold);
	scoreText.setPosition(sf::Vector2f((screenWidth - 10 * blocX)/2 , gameRectY + gameRectHeight + blocY));
	window.draw(scoreText);
	
}

void PlayerSnake::logicSnake()
{
	move();
	if (bodyPos[0].x < gameRectX )
		bodyPos[0].x = gameRectX + gameRectWidth - blocX;
	if (bodyPos[0].x > gameRectX + gameRectWidth - blocX)
		bodyPos[0].x = gameRectX;
	if (bodyPos[0].y < gameRectY)
		bodyPos[0].y = gameRectY + gameRectHeight - blocY;
	if (bodyPos[0].y > gameRectY + gameRectHeight - blocY)
		bodyPos[0].y = gameRectY;

	if (bodyPos[0] == food.smallfoodPos)
	{
		food.foodEaten();
		addBody(bodyPos[numberOfpieces-1].x,bodyPos[numberOfpieces-1].y);
		score.incrementScore();
	}
	for (int i = 1; i < numberOfpieces; i++)
	{
		if (bodyPos[0] == bodyPos[i])
		{
			initSnake();
		}

	}
		

}
void PlayerSnake::addBody(int x, int y)
{
	numberOfpieces++;
	bodyPos.push_back(sf::Vector2f(x, y));
}

void PlayerSnake::move()
{
	sf::Vector2f previousPos;
	lostTime += clock.getElapsedTime().asSeconds();

	if (lostTime >= frameTime)
	{

		previousPos = bodyPos[0];

		if (direction == Direction::RIGHT)
		{
				bodyPos[0].x += displacement;
		}
		if (direction == Direction::LEFT)
		{
				bodyPos[0].x -= displacement;
		}
		if (direction == Direction::UP)
		{
				bodyPos[0].y -= displacement;
		}
		if (direction == Direction::DOWN)
		{
				bodyPos[0].y += displacement;
		}
		
		sf::Vector2f previouspos2;
		for (int i = 1; i < numberOfpieces; i++)
		{
			previouspos2 = bodyPos[i];
			bodyPos[i] = previousPos;
			previousPos = previouspos2;
		}

		/*
		 system("cls");
		 std::cout << "snake.x : " << bodyPos[0].x << " snake.y : " << bodyPos[0].y << std::endl;
		 std::cout << "number of body segments:" << numberOfpieces - 1 << std::endl;
		 std::cout << score.scoreString() << std::endl;
		 */
		lostTime = clock.restart().asSeconds();
	}
	
}

void PlayerSnake::initSnake()
{
	numberOfpieces = 0;
	lostTime = 0;
	displacement = blocX;

	frameTime = 0.5f;
	int startX = gameRectWidth / 2 + gameRectX;
	int startY = gameRectHeight / 2 + gameRectY;

	direction = Direction::RIGHT;

	//define the body piece shape
	bodyBox.setSize(sf::Vector2f(blockSize, blockSize));
	bodyBox.setOutlineColor(sf::Color(0, 150, 255, 255));
	bodyBox.setOutlineThickness(thikness);
	bodyBox.setFillColor(sf::Color(0, 150, 255, 100));

	headBox.setSize(sf::Vector2f(blockSize, blockSize));
	headBox.setOutlineColor(sf::Color(50, 100, 255, 255));
	headBox.setOutlineThickness(thikness);
	headBox.setFillColor(sf::Color(50, 100, 255, 200));

	bodyPos.clear();
	addBody(startX, startY);
	addBody(startX - blocX, startY);
	addBody(startX - 2 * blocX, startY);

	score.resetScore();
	lostTime = clock.restart().asSeconds();

}