#pragma once
#include <memory>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Robot.h"
#include "Board.h"
#include "Navigator.h"

using namespace std;
class RobotToyController
{
private:
	string m_BotName;
	string m_RobotData;
	Board m_Board;
	void display();
	void displayMenu();
	void displayRobotData();
	vector<string> splitString(const string&, char);
	void handleError(const string&);
	void executeCommand(const vector<string>&);
	void executePlace(const string&);
	void executeRotate(const string&);
	void executeMove();
	string executeReport();
public:
	RobotToyController();
	void addBot(const string&);
	void start();
};

