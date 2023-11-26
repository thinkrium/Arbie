#include "Body/Motors/Utilities/Error_Messaging.h"
#include <iostream>
#include "Body/Motors/Servo/Servo_Motor.h"
#include "OS_Utilities/Logger.h"
//#include <pigpio


using namespace Utilities::Enumerations;
using namespace OS_Utilities;
using namespace Motor;
int main() {

    Servo_Motor servoMotor;

    Logger::Info(Error_Messaging::No_Error);

    servoMotor.Turn_Motor(Rotation_Direction::Counter_Clockwise, 3, 3);

    return 0;
}
