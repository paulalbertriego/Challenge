#pragma once
#include <vector>
#include "Robot.h"
#include "Constants.h"

class Board
{
private:
	map<string, unique_ptr<Robot>> robots;
public:
	void addBot(const string&, unique_ptr<Robot>);
	unique_ptr<Robot>& GetBot(const string&);
};
