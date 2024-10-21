#include "pch.h"
#include "../RobotToyLib/Robot.h"

class RobotTestRotateLeft : public ::testing::Test {
protected:
	Robot testRobot;
};

TEST_F(RobotTestRotateLeft, Not_Placed)
{
	EXPECT_THROW(testRobot.rotateLeft(), std::exception);
}
TEST_F(RobotTestRotateLeft, North)
{
	testRobot.place(2, 2, Direction::NORTH);
	EXPECT_NO_THROW(testRobot.rotateLeft());
	EXPECT_EQ(Direction::WEST, testRobot.getFacingDirection());
}

TEST_F(RobotTestRotateLeft, West)
{
	testRobot.place(2, 2, Direction::WEST);
	EXPECT_NO_THROW(testRobot.rotateLeft());
	EXPECT_EQ(Direction::SOUTH, testRobot.getFacingDirection());
}
TEST_F(RobotTestRotateLeft, South)
{
	testRobot.place(2, 2, Direction::SOUTH);
	EXPECT_NO_THROW(testRobot.rotateLeft());
	EXPECT_EQ(Direction::EAST, testRobot.getFacingDirection());
}
TEST_F(RobotTestRotateLeft, East)
{
	testRobot.place(2, 2, Direction::EAST);
	EXPECT_NO_THROW(testRobot.rotateLeft());
	EXPECT_EQ(Direction::NORTH, testRobot.getFacingDirection());
}

