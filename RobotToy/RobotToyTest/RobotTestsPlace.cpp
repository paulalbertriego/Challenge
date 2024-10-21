#include "pch.h"
#include "../RobotToyLib/Robot.h"

class RobotTestsPlace : public ::testing::Test {
protected:
	Robot testRobot;
};

TEST_F(RobotTestsPlace, Origin)
{
	testRobot.place(0, 0, Direction::NORTH);
	EXPECT_EQ(0, testRobot.getCoordinateX());
	EXPECT_EQ(0, testRobot.getCoordinateY());
	EXPECT_EQ(Direction::NORTH, testRobot.getFacingDirection());
	EXPECT_TRUE(testRobot.getIsPlaced());
}
TEST_F(RobotTestsPlace, Edge)
{
	testRobot.place(4, 4, Direction::NORTH);
	EXPECT_EQ(4, testRobot.getCoordinateX());
	EXPECT_EQ(4, testRobot.getCoordinateY());
	EXPECT_EQ(Direction::NORTH, testRobot.getFacingDirection());
	EXPECT_TRUE(testRobot.getIsPlaced());
}
TEST_F(RobotTestsPlace, Center)
{
	testRobot.place(2, 2, Direction::NORTH);
	EXPECT_EQ(2, testRobot.getCoordinateX());
	EXPECT_EQ(2, testRobot.getCoordinateY());
	EXPECT_EQ(Direction::NORTH, testRobot.getFacingDirection());
	EXPECT_TRUE(testRobot.getIsPlaced());
}
TEST_F(RobotTestsPlace, Random)
{
	testRobot.place(3, 2, Direction::NORTH);
	EXPECT_EQ(3, testRobot.getCoordinateX());
	EXPECT_EQ(2, testRobot.getCoordinateY());
	EXPECT_EQ(Direction::NORTH, testRobot.getFacingDirection());
	EXPECT_TRUE(testRobot.getIsPlaced());
}
TEST_F(RobotTestsPlace, Facingg_EAST)
{
	testRobot.place(0, 0, Direction::EAST);
	EXPECT_EQ(0, testRobot.getCoordinateX());
	EXPECT_EQ(0, testRobot.getCoordinateY());
	EXPECT_EQ(Direction::EAST, testRobot.getFacingDirection());
	EXPECT_TRUE(testRobot.getIsPlaced());
}
TEST_F(RobotTestsPlace, Facing_SOUTH)
{
	testRobot.place(0, 0, Direction::SOUTH);
	EXPECT_EQ(0, testRobot.getCoordinateX());
	EXPECT_EQ(0, testRobot.getCoordinateY());
	EXPECT_EQ(Direction::SOUTH, testRobot.getFacingDirection());
	EXPECT_TRUE(testRobot.getIsPlaced());
}
TEST_F(RobotTestsPlace, Facing_WEST)
{
	testRobot.place(0, 0, Direction::WEST);
	EXPECT_EQ(0, testRobot.getCoordinateX());
	EXPECT_EQ(0, testRobot.getCoordinateY());
	EXPECT_EQ(Direction::WEST, testRobot.getFacingDirection());
	EXPECT_TRUE(testRobot.getIsPlaced());
}
TEST_F(RobotTestsPlace, OutSide_Left)
{
	EXPECT_THROW(testRobot.place(-1, 2, Direction::NORTH), std::out_of_range);
}
TEST_F(RobotTestsPlace, OutSide_Right)
{
	EXPECT_THROW(testRobot.place(5, 2, Direction::NORTH), std::out_of_range);
}
TEST_F(RobotTestsPlace, OutSide_Bottom)
{
	EXPECT_THROW(testRobot.place(2, -1, Direction::NORTH), std::out_of_range);
}
TEST_F(RobotTestsPlace, OutSide_Top)
{
	EXPECT_THROW(testRobot.place(2, 5, Direction::NORTH), std::out_of_range);
}
TEST_F(RobotTestsPlace, OutSide_TopCorner_Left)
{
	EXPECT_THROW(testRobot.place(0, 5, Direction::NORTH), std::out_of_range);
}
TEST_F(RobotTestsPlace, OutSide_BottomCorner_Left)
{
	EXPECT_THROW(testRobot.place(-1, 0, Direction::NORTH), std::out_of_range);
}
TEST_F(RobotTestsPlace, TopCorner_Right)
{
	EXPECT_THROW(testRobot.place(4, 20, Direction::NORTH), std::out_of_range);
}
TEST_F(RobotTestsPlace, BottomCorner_Right)
{
	EXPECT_THROW(testRobot.place(4, -1, Direction::NORTH), std::out_of_range);
}






