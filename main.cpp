#include "Body/Motors/Utilities/Error_Messaging.h"
#include "Body/Motors/Servo/Servo_Motor.h"
#include "OS_Utilities/Logger.h"


using namespace Utilities::Enumerations;
using namespace OS_Utilities;
using namespace Motor;
int main() {

    Servo_Motor servoMotor(0,  0, 135, 500, 2500, 200);

    servoMotor.Turn_Motor(Rotation_Direction::Counter_Clockwise, 30, 3);

    Logger::Success(Error_Messaging::No_Error);

    return 0;
}
