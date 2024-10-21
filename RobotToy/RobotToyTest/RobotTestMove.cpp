#include "pch.h"
#include "../RobotToyLib/Robot.h"

class RobotTestsMove : public ::testing::Test {
protected:
	Robot testRobot;
};


TEST_F(RobotTestsMove, Not_Placed)
{
	EXPECT_THROW(testRobot.move(), std::exception);
}

TEST_F(RobotTestsMove, North)
{
	testRobot.place(2, 2, Direction::NORTH);
	EXPECT_NO_THROW(testRobot.move());
	EXPECT_EQ(2, testRobot.getCoordinateX());
	EXPECT_EQ(3, testRobot.getCoordinateY());
}
TEST_F(RobotTestsMove, South)
{
	testRobot.place(2, 2, Direction::SOUTH);
	EXPECT_NO_THROW(testRobot.move());
	EXPECT_EQ(2, testRobot.getCoordinateX());
	EXPECT_EQ(1, testRobot.getCoordinateY());
}
TEST_F(RobotTestsMove, East)
{
	testRobot.place(2, 2, Direction::EAST);
	EXPECT_NO_THROW(testRobot.move());
	EXPECT_EQ(3, testRobot.getCoordinateX());
	EXPECT_EQ(2, testRobot.getCoordinateY());
}
TEST_F(RobotTestsMove, West)
{
	testRobot.place(2, 2, Direction::WEST);
	EXPECT_NO_THROW(testRobot.move());
	EXPECT_EQ(1, testRobot.getCoordinateX());
	EXPECT_EQ(2, testRobot.getCoordinateY());
}

TEST_F(RobotTestsMove, Bottom_West)
{
	testRobot.place(1, 0, Direction::WEST);
	EXPECT_NO_THROW(testRobot.move());
	EXPECT_EQ(0, testRobot.getCoordinateX());
	EXPECT_EQ(0, testRobot.getCoordinateY());
}
TEST_F(RobotTestsMove, Top_West)
{
	testRobot.place(1, 4, Direction::WEST);
	EXPECT_NO_THROW(testRobot.move());
	EXPECT_EQ(0, testRobot.getCoordinateX());
	EXPECT_EQ(4, testRobot.getCoordinateY());
}

TEST_F(RobotTestsMove, Bottom_East)
{
	testRobot.place(3, 0, Direction::EAST);
	EXPECT_NO_THROW(testRobot.move());
	EXPECT_EQ(4, testRobot.getCoordinateX());
	EXPECT_EQ(0, testRobot.getCoordinateY());
}
TEST_F(RobotTestsMove, Top_East)
{
	testRobot.place(3, 4, Direction::EAST);
	EXPECT_NO_THROW(testRobot.move());
	EXPECT_EQ(4, testRobot.getCoordinateX());
	EXPECT_EQ(4, testRobot.getCoordinateY());
}

TEST_F(RobotTestsMove, OutSide_West)
{
	testRobot.place(0, 2, Direction::WEST);
	EXPECT_THROW(testRobot.move(), std::out_of_range);
}
TEST_F(RobotTestsMove, OutSide_East)
{
	testRobot.place(4, 2, Direction::EAST);
	EXPECT_THROW(testRobot.move(), std::out_of_range);
}
TEST_F(RobotTestsMove, OutSide_South)
{
	testRobot.place(2, 0, Direction::SOUTH);
	EXPECT_THROW(testRobot.move(), std::out_of_range);
}
TEST_F(RobotTestsMove, OutSide_North)
{
	testRobot.place(2, 4, Direction::NORTH);
	EXPECT_THROW(testRobot.move(), std::out_of_range);
}
TEST_F(RobotTestsMove, OutSide_TopCorner_West)
{
	testRobot.place(0, 4, Direction::WEST);
	EXPECT_THROW(testRobot.move(), std::out_of_range);
}
TEST_F(RobotTestsMove, OutSide_BottomCorner_West)
{
	testRobot.place(0, 0, Direction::WEST);
	EXPECT_THROW(testRobot.move(), std::out_of_range);
}
TEST_F(RobotTestsMove, TopCorner_East)
{
	testRobot.place(4, 4, Direction::EAST);
	EXPECT_THROW(testRobot.move(), std::out_of_range);
}
TEST_F(RobotTestsMove, BottomCorner_East)
{
	testRobot.place(4, 0, Direction::EAST);
	EXPECT_THROW(testRobot.move(), std::out_of_range);
}