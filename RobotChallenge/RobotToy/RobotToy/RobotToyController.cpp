#include "RobotToyController.h"

string COMMAND_PLACE_KEYWORD = "PLACE";
string COMMAND_PLACE = "PLACE X,Y,F";
string COMMAND_MOVE = "MOVE";
string COMMAND_LEFT = "LEFT";
string COMMAND_RIGHT = "RIGHT";
string COMMAND_REPORT = "REPORT";
string COMMAND_QUIT = "QUIT";

void RobotToyController::display()
{
    cout << "Accepted Commands" << endl;
    displayRobotData();
    cout << "----------------------" << endl;
    displayMenu();
}

void RobotToyController::displayMenu()
{
    cout << "INPUT COMMAND" << endl;
    cout << COMMAND_PLACE_KEYWORD << endl;
    cout << COMMAND_MOVE << endl;
    cout << COMMAND_LEFT << endl;
    cout << COMMAND_RIGHT << endl;
    cout << COMMAND_REPORT << endl;
    cout << COMMAND_QUIT << endl;
}

void RobotToyController::displayRobotData()
{
    cout << m_RobotData << endl;
}

vector<string> RobotToyController::splitString(const string& t_words, char t_delim)
{
    istringstream  stream(t_words);
    string item;
    vector<string> elem;
    while (getline(stream, item, t_delim))
        elem.push_back(item);

    return elem;
}

RobotToyController::RobotToyController()
    : m_BotName(string()), m_RobotData(string())
{
}

void RobotToyController::addBot(const string& t_botname)
{
    unique_ptr<Robot> bot = make_unique<Robot>();
    m_Board.addBot(t_botname, move(bot));
    m_BotName = t_botname;
}



void RobotToyController::start()
{
    string commandInput;
    while (1)
    {
        system("cls");
        display();
        cout << "Enter Command: " ;
        getline(cin, commandInput);

        vector<string> commandString;
        commandString = splitString(commandInput, ' ');

        if (commandString.empty())
        {
            handleError("Command not found");
            continue;
        }

        try
        {
            executeCommand(commandString);
            if (commandInput != COMMAND_REPORT)
            {
                m_RobotData += commandInput + "\n";
            }
        }
        catch (...)
        {
            handleError("Incorrect Command");
        }
    }
}

void RobotToyController::executeRotate(const string& t_rotationCommand)
{
    try
    {
        if (t_rotationCommand == COMMAND_LEFT)
        {
            m_Board.GetBot(m_BotName)->rotateLeft();
        }
        else if (t_rotationCommand == COMMAND_RIGHT)
        {
            m_Board.GetBot(m_BotName)->rotateRight();
        }
        else
        {
            throw exception("InvalidRotateCommand");
        }
    }
    catch (...)
    {
        throw exception("InvalidRotateCommand");
    }
}

void RobotToyController::executeMove()
{
    try
    {
        m_Board.GetBot(m_BotName)->move();
    }
    catch (...)
    {
        throw exception("InvalidMoveCommand");
    }
}

string RobotToyController::executeReport()
{
    try
    {
        return m_Board.GetBot(m_BotName)->report();
    }
    catch (...)
    {
        throw exception("InvalidReportCommand");
    }
}

void RobotToyController::executePlace(const string& t_placeCommand)
{
    vector<string> placeCommand = splitString(t_placeCommand, ',');

    if (placeCommand.size() != 3)
    {
        throw exception("InvalidPlaceCommand");
    }

    Direction facingDirection;
    if (placeCommand[2] == "NORTH")
        facingDirection = Direction::NORTH;
    else if (placeCommand[2] == "EAST")
        facingDirection = Direction::EAST;
    else if (placeCommand[2] == "SOUTH")
        facingDirection = Direction::SOUTH;
    else if (placeCommand[2] == "WEST")
        facingDirection = Direction::WEST;
    else
    {
        throw exception("InvalidPlaceCommand");
    }
    int coordx;
    int coordy;
    try
    {
        coordx = stoi(placeCommand[0]);
        coordy = stoi(placeCommand[1]);
    }
    catch (...)
    {
        throw exception("InvalidPlaceCommand");
    }
    m_Board.GetBot(m_BotName)->place(coordx, coordy, facingDirection);
}

void RobotToyController::handleError(const string& t_error)
{
    cerr << t_error << endl;
    system("pause");
}

void RobotToyController::executeCommand(const vector<string>& t_command)
{
    if (t_command[0] == COMMAND_PLACE_KEYWORD)
    {
        if (t_command.size() != 2)
        {
            throw exception("InvalidPlaceCommand");
        }

        executePlace(t_command[1]);
    }
    else if (t_command[0] == COMMAND_MOVE)
    {
        executeMove();
    }
    else if (t_command[0] == COMMAND_LEFT || t_command[0] == COMMAND_RIGHT)
    {
        executeRotate(t_command[0]);
    }
    else if (t_command[0] == COMMAND_REPORT)
    {
        m_RobotData += executeReport() + "\n";
    }
    else if (t_command[0] == COMMAND_QUIT)
    {
        exit(0);
    }
    else
    {
        throw exception("CommandNotFound");
    }
}
