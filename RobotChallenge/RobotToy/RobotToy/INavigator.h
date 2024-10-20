#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include "Constants.h"

using namespace std;

class INavigator
{
public:
	virtual ~INavigator() = default;

	virtual Direction rotate(Direction, int) = 0;
	virtual string toString(Direction) const = 0;
	virtual int toInt(Direction) const = 0;
	virtual Direction stringToDirection(const string&) = 0;
	virtual Direction intToDirection(int t_intValue) const = 0;
};
