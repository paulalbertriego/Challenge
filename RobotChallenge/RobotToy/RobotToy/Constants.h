#pragma once
constexpr  int BOARD_WIDTH = 5;
constexpr  int BOARD_HEIGHT = 5;
constexpr  int BOARD_X_ORIGIN = 0;
constexpr  int BOARD_Y_ORIGIN = 0;

constexpr  int ROTATE_LEFT = 0;
constexpr  int ROTATE_RIGHT = 1;

enum class Direction
{
	NORTH = 0,
	EAST,
	SOUTH,
	WEST
};
