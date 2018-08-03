#include "Score.h"
#include <sstream>

Score::Score()
:points(10),
scoreNormal (0)
{
}


Score::~Score()
{
}

std::string Score::scoreString()
{
	std::stringstream ss;
	ss <<"score :  " << scoreNormal;
	return ss.str();
}
void Score::incrementScore()
{
	scoreNormal += points;
}

void Score::resetScore()
{
	scoreNormal = 0;
}