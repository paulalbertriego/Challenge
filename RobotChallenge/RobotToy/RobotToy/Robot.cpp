#include "Robot.h"
#include <iostream>

using namespace std;


Robot::Robot()
	: m_CoordinateX(0), m_CoordinateY(0), m_FacingDirection(Direction::NORTH), m_isPlaced(false) {}

bool Robot::canPlace(int t_x, int t_y)
{
	return t_x < BOARD_WIDTH && t_y < BOARD_HEIGHT;
}

bool Robot::canMove()
{
	int coordx = m_CoordinateX;
	int coordy = m_CoordinateY;
	switch (m_FacingDirection)
	{
		case Direction::NORTH:
			return ++coordy < BOARD_HEIGHT;
		case Direction::EAST:
			return ++coordx < BOARD_WIDTH;
		case Direction::SOUTH:
			return --coordy >= BOARD_Y_ORIGIN;
		case Direction::WEST:
			return --coordx >= BOARD_X_ORIGIN;
	}
	return false;
}

string Robot::getDirectionString()
{
	switch (m_FacingDirection)
	{
		case Direction::NORTH: return "NORTH";
		case Direction::EAST: return "EAST";
		case Direction::SOUTH: return "SOUTH";
		case Direction::WEST: return "WEST";
		default: return string();
	}
}

void Robot::place(int t_x, int t_y, Direction t_direction)
{
	if (!canPlace(t_x, t_y))
		throw out_of_range("Position out of bounds");

	m_CoordinateX = t_x;
	m_CoordinateY = t_y;
	m_FacingDirection = t_direction;
	m_isPlaced = true;
}

void Robot::rotate(int t_rotateDirection)
{
	if (!m_isPlaced)
		throw exception("Bot not found");

	Navigator navigator(m_FacingDirection, t_rotateDirection);
	navigator.rotate();
	m_FacingDirection = navigator.getDirection();

}

void Robot::rotateLeft()
{
	rotate(ROTATE_LEFT);
}
void Robot::rotateRight()
{
	rotate(ROTATE_RIGHT);
}
void Robot::move()
{
	if (!m_isPlaced)
		throw exception("Bot not found");

	if (!canMove())
		throw std::out_of_range("Position out of bounds");

	switch (m_FacingDirection)
	{
		case Direction::NORTH:
			m_CoordinateY++;
			break;
		case Direction::EAST:
			m_CoordinateX++;
			break;
		case Direction::SOUTH:
			m_CoordinateY--;
			break;
		case Direction::WEST:
			m_CoordinateX--;
			break;
	}
}
string Robot::report() 
{
	if (!m_isPlaced)
		throw exception("Bot not found");

	return "Output: " + 
		to_string(m_CoordinateX) +
		", " +
		to_string(m_CoordinateY) +
		", " +
		getDirectionString();
}