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
	virtual int getCoordinateX() const = 0;
	virtual int getCoordinateY() const = 0;
	virtual Direction getFacingDirection() const = 0;
	virtual bool getIsPlaced() const = 0;
};
