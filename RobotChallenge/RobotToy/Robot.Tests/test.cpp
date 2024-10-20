#include "pch.h"
#include "../../RobotToy/RobotToy/Robot.cpp"
#include "../../RobotToy/RobotToy/Navigator.cpp"

TEST(RobotTests, Place_Origin)
{
	Robot testRobot;
	testRobot.place(0, 0, Direction::NORTH);
	EXPECT_EQ(0, testRobot.getCoordinateX());
	EXPECT_EQ(0, testRobot.getCoordinateY());
	EXPECT_EQ(Direction::NORTH, testRobot.getFacingDirection());
	EXPECT_TRUE(testRobot.getIsPlaced());
}
TEST(RobotTests, Place_Edge)
{
	Robot testRobot;
	testRobot.place(4, 4, Direction::NORTH);
	EXPECT_EQ(4, testRobot.getCoordinateX());
	EXPECT_EQ(4, testRobot.getCoordinateY());
	EXPECT_EQ(Direction::NORTH, testRobot.getFacingDirection());
	EXPECT_TRUE(testRobot.getIsPlaced());
}
TEST(RobotTests, Place_Center)
{
	Robot testRobot;
	testRobot.place(2, 2, Direction::NORTH);
	EXPECT_EQ(2, testRobot.getCoordinateX());
	EXPECT_EQ(2, testRobot.getCoordinateY());
	EXPECT_EQ(Direction::NORTH, testRobot.getFacingDirection());
	EXPECT_TRUE(testRobot.getIsPlaced());
}
TEST(RobotTests, Place_Random)
{
	Robot testRobot;
	testRobot.place(3, 2, Direction::NORTH);
	EXPECT_EQ(3, testRobot.getCoordinateX());
	EXPECT_EQ(2, testRobot.getCoordinateY());
	EXPECT_EQ(Direction::NORTH, testRobot.getFacingDirection());
	EXPECT_TRUE(testRobot.getIsPlaced());
}
TEST(RobotTests, Facing_EAST)
{
	Robot testRobot;
	testRobot.place(0, 0, Direction::EAST);
	EXPECT_EQ(0, testRobot.getCoordinateX());
	EXPECT_EQ(0, testRobot.getCoordinateY());
	EXPECT_EQ(Direction::EAST, testRobot.getFacingDirection());
	EXPECT_TRUE(testRobot.getIsPlaced());
}
TEST(RobotTests, Facing_SOUTH)
{
	Robot testRobot;
	testRobot.place(0, 0, Direction::SOUTH);
	EXPECT_EQ(0, testRobot.getCoordinateX());
	EXPECT_EQ(0, testRobot.getCoordinateY());
	EXPECT_EQ(Direction::SOUTH, testRobot.getFacingDirection());
	EXPECT_TRUE(testRobot.getIsPlaced());
}
TEST(RobotTests, Facing_WEST)
{
	Robot testRobot;
	testRobot.place(0, 0, Direction::WEST);
	EXPECT_EQ(0, testRobot.getCoordinateX());
	EXPECT_EQ(0, testRobot.getCoordinateY());
	EXPECT_EQ(Direction::WEST, testRobot.getFacingDirection());
	EXPECT_TRUE(testRobot.getIsPlaced());
}

TEST(RobotTests, Place_OutSideLeft)
{
	Robot testRobot;
	EXPECT_THROW(testRobot.place(-1, 2, Direction::NORTH), std::out_of_range);
}
TEST(RobotTests, Place_OutSideRight)
{
	Robot testRobot;
	EXPECT_THROW(testRobot.place(5, 2, Direction::NORTH), std::out_of_range);
}
TEST(RobotTests, Place_OutSideBottom)
{
	Robot testRobot;
	EXPECT_THROW(testRobot.place(2, -1, Direction::NORTH), std::out_of_range);
}
TEST(RobotTests, Place_OutSideTop)
{
	Robot testRobot;
	EXPECT_THROW(testRobot.place(2,5, Direction::NORTH), std::out_of_range);
}
TEST(RobotTests, Place_OutLeftTopCorner)
{
	Robot testRobot;
	EXPECT_THROW(testRobot.place(0, 5, Direction::NORTH), std::out_of_range);
}
TEST(RobotTests, Place_OutLeftBottomCorner)
{
	Robot testRobot;
	EXPECT_THROW(testRobot.place(-1, 0, Direction::NORTH), std::out_of_range);
}
TEST(RobotTests, Place_OutRightTopCorner)
{
	Robot testRobot;
	EXPECT_THROW(testRobot.place(4, 20, Direction::NORTH), std::out_of_range);
}
TEST(RobotTests, Place_OutRightBottomCorner)
{
	Robot testRobot;
	EXPECT_THROW(testRobot.place(4, -1, Direction::NORTH), std::out_of_range);
}


