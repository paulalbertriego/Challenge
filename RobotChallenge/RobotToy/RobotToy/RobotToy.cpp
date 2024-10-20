#include <iostream>
#include "RobotToyController.h"

using namespace std;

int main()
{
    RobotToyController controller;
    controller.addBot("robotroll");
    controller.start();
}
