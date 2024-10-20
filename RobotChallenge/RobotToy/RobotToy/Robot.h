#pragma once
#include "IRobot.h"

using namespace std;
class Robot : public IRobot
{
private:
	int m_CoordinateX;
	int m_CoordinateY;
	Direction m_FacingDirection = Direction::NORTH;
	bool m_isPlaced;
	bool canPlace(int, int);
	bool canMove();
	void rotate(int);
public:
	Robot();
	void place(int, int, Direction) override;
	void rotateLeft() override;
	void rotateRight() override;
	void move() override;
	string report() override;
	int getCoordinateX() const override;
	int getCoordinateY() const override;
	Direction getFacingDirection() const override;
	bool getIsPlaced() const override;
};