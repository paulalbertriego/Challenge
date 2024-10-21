#pragma once
#include "pch.h"
#include "Constants.h"
#include "Navigator.h"

class IRobotController
{
public:
	virtual ~IRobotController() = default;

	virtual void addBot(const string&) = 0;
	virtual void start() = 0;
	virtual void executeCommand(const vector<string>&) =0;
	virtual void executePlace(const string&) = 0;
	virtual void executeRotate(const string&) = 0;
	virtual void executeMove() = 0;
	virtual string executeReport() = 0;
};
