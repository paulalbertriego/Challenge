#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include "Constants.h"


using namespace std;

class Navigator
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
	Direction rotate(Direction, int);
	string toString(Direction) const;
	int toInt(Direction) const;
	Direction stringToDirection(const string&);
	Direction intToDirection(int t_intValue) const;
};