#pragma once
#include <vector>
#include "Robot.h"
#include "Constants.h"

class Board
{
private:
	map<string, unique_ptr<IRobot>> robots;
public:
	void addBot(const string&, unique_ptr<IRobot>);
	unique_ptr<IRobot>& GetBot(const string&);
};
