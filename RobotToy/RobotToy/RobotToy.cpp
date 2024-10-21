#include <iostream>
#include "../RobotToyLib/RobotController.h"

using namespace std;

int main()
{
    RobotController controller;
    controller.addBot("robotroll");
    controller.start(); 
}
