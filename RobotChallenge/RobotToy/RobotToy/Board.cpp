#include <memory>
#include "Board.h"

using namespace std;
void Board::addBot(const string& t_botname, unique_ptr<IRobot> t_botPtr)
{
	robots[t_botname] = move(t_botPtr);
}
unique_ptr<IRobot>& Board::GetBot(const string& t_botname)
{
	return robots[t_botname];
}