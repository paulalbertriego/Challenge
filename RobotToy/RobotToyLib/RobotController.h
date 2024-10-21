#pragma once
#include "IRobotController.h"
#include "Board.h"
#include "Constants.h"
#include "Robot.h"
#include "StringHelper.h"

using namespace std;
class RobotController : public IRobotController
{
private:
	string m_BotName;
	string m_RobotData;
	Board m_Board;
	void display();
	void displayMenu();
	void displayRobotData();
	void handleError(const string&);
public:
	RobotController();
	void addBot(const string&) override;
	void start() override;
	void executeCommand(const vector<string>&) override;
	void executePlace(const string&) override;
	void executeRotate(const string&) override;
	void executeMove() override;
	string executeReport() override;
};

