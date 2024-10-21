#include "pch.h"
#include "../RobotToyLib/Robot.h"

class RobotTestRotateRight : public ::testing::Test {
protected:
	Robot testRobot;
};

TEST_F(RobotTestRotateRight, Not_Placed)
{
	EXPECT_THROW(testRobot.rotateRight(), std::exception);
}
TEST_F(RobotTestRotateRight, North)
{
	testRobot.place(2, 2, Direction::NORTH);
	EXPECT_NO_THROW(testRobot.rotateRight());
	EXPECT_EQ(Direction::EAST, testRobot.getFacingDirection());
}

TEST_F(RobotTestRotateRight, West)
{
	testRobot.place(2, 2, Direction::WEST);
	EXPECT_NO_THROW(testRobot.rotateRight());
	EXPECT_EQ(Direction::NORTH, testRobot.getFacingDirection());
}
TEST_F(RobotTestRotateRight, South)
{
	testRobot.place(2, 2, Direction::SOUTH);
	EXPECT_NO_THROW(testRobot.rotateRight());
	EXPECT_EQ(Direction::WEST, testRobot.getFacingDirection());
}
TEST_F(RobotTestRotateRight, East)
{
	testRobot.place(2, 2, Direction::EAST);
	EXPECT_NO_THROW(testRobot.rotateRight());
	EXPECT_EQ(Direction::SOUTH, testRobot.getFacingDirection());
}

