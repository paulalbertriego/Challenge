#pragma once
#include "INavigator.h"


using namespace std;

class Navigator : public INavigator
{
private:
	struct DirectionData
	{
		int IntValue;
		string StringValue;
		Direction Value;

		DirectionData(int t_intValue, const string& t_stringValue, Direction t_value)
			: IntValue(t_intValue), StringValue(t_stringValue), Value(t_value) {}
	};
	vector<DirectionData> directions =
	{
		{ 0, "NORTH", Direction::NORTH },
		{ 1, "EAST", Direction::EAST},
		{ 2, "SOUTH", Direction::SOUTH},
		{ 3, "WEST", Direction::WEST }
	};
public:
	Direction rotate(Direction, int) override;
	string toString(Direction) const override;
	int toInt(Direction) const override;
	Direction stringToDirection(const string&) override;
	Direction intToDirection(int t_intValue) const override;
};