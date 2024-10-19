#pragma once
#include <map>
#include <string>
#include "Navigator.h"
#include "Constants.h"

using namespace std;
class Robot
{
private:
	int m_CoordinateX;
	int m_CoordinateY;
	Direction m_FacingDirection = Direction::NORTH;
	bool m_isPlaced;
	bool canPlace(int, int);
	bool canMove();
	string getDirectionString();
	void rotate(int);
public:
	Robot();
	void place(int, int, Direction);
	void rotateLeft();
	void rotateRight();
	void move();
	string report();
};