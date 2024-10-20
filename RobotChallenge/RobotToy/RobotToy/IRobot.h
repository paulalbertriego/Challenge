#pragma once
#include <map>
#include <string>
#include "Navigator.h"
#include "Constants.h"

using namespace std;

class IRobot
{
public:
	virtual ~IRobot() = default;

	virtual void place(int, int, Direction) = 0;
	virtual void rotateLeft() = 0;
	virtual void rotateRight() = 0;
	virtual void move() = 0;
	virtual string report() = 0;
};
