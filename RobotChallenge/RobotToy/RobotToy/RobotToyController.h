#pragma once
#include <memory>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Robot.h"
#include "Board.h"

using namespace std;
class RobotToyController
{
private:
	string m_BotName;
	string m_RobotData;
	Board m_Board;
	void displayMenu();
	void displayRobotData();
	vector<string> splitString(const string&, char);
	void displayError(const string&);
	void ExecutePlace(const string&);
	void executeRotate(const string&);
	void executeMove();
	string executeReport();
public:
	RobotToyController();
	void addBot(const string&);
	void start();
};

