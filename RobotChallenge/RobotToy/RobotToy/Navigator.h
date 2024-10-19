#pragma once
#include <algorithm>
#include <string>
#include <map>
#include "Constants.h"


using namespace std;

class Navigator
{
private:
	int m_moveDirection;
	Direction m_direction;
	map<int, Direction> directions = {
		{0, Direction::NORTH},
		{1, Direction::EAST},
		{2, Direction::SOUTH},
		{3, Direction::WEST},
	};
	int getDirectionIntValue();
public:
	Navigator(Direction, int);
	void rotate();
	Direction getDirection() const;
};

