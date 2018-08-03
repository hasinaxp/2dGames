#pragma once
#include <string>
class Score
{
public:
	Score();
	~Score();

private://variables
	int scoreNormal;
	int points;

public://method
	std::string scoreString();
	void incrementScore();
	void resetScore();
};

