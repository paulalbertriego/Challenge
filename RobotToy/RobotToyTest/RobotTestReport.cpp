#include "pch.h"
#include "../RobotToyLib/Robot.h"

class RobotTestReport : public ::testing::Test {
protected:
	Robot testRobot;
};


TEST_F(RobotTestReport, Not_Placed)
{
	EXPECT_THROW(testRobot.report(), std::exception);
}

TEST_F(RobotTestReport, Report)
{
	testRobot.place(0, 0, Direction::NORTH);
	std::string output = "Output: 0, 0, NORTH";
	EXPECT_EQ(output, testRobot.report());
}
TEST_F(RobotTestReport, Move)
{
	testRobot.place(0, 0, Direction::NORTH);
	testRobot.move();
	std::string output = "Output: 0, 1, NORTH";
	EXPECT_EQ(output, testRobot.report());
}

TEST_F(RobotTestReport, Rotate_Left)
{
	testRobot.place(0, 0, Direction::NORTH);
	testRobot.rotateLeft();
	std::string output = "Output: 0, 0, WEST";
	EXPECT_EQ(output, testRobot.report());
}

TEST_F(RobotTestReport, Rotate_Right)
{
	testRobot.place(0, 0, Direction::NORTH);
	testRobot.rotateRight();
	std::string output = "Output: 0, 0, EAST";
	EXPECT_EQ(output, testRobot.report());
}