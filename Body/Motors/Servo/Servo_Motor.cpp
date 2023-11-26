//
// Created by thome on 11/9/2023.
//

#include <unistd.h>
#include "Servo_Motor.h"
#include "../../Libraries/PCA9685/PCA9685.h"
#include "../../../OS_Utilities/Logger.h"

using namespace OS_Utilities;

Motor::Servo_Motor::Servo_Motor() {}

void Motor::Servo_Motor::Turn_Motor(Rotation_Direction rotationDirection, float degrees, float speed) {

    if(rotationDirection == Rotation_Direction::Clockwise) {

    }
    else if (rotationDirection == Rotation_Direction::Counter_Clockwise) {

    }

/*

    float percentage = 0;

    PCA9685 pwm;
    pwm.init(1,0x40);
    usleep(1000 * 100);
    std::cout << "frequency" << endl;
    pwm.setPWMFreq (200);
    usleep(2000 * 1000);
    std::cout << "min" << endl;

    pwm.setPWM(0, 0, 300); // down
    usleep(2000 * 1000);
    std::cout << "max" << endl;

    pwm.setPWM(0, 0, 2200); // down
    usleep(2000 * 1000);
    std::cout << "neutral" << endl;

    pwm.setPWM(0, 0, 1225); // down
    usleep(2000 * 1000);
*/

    Logger::Warn(  Error_Messaging::Outside_Servo_PWM_Range);

//   for (int i = 0; i <  2800 ; i+=100) {
//
//       pwm.setPWM(0, 0, i); // down
//       usleep(1000 * 1000);
//       float upTime = ((i / 4095) * 100);
//       cout << "The up "<< i << " time is " <<  upTime << endl;
//   }

//        pwm.setPWM(1,0, 1500); // around


}

Motor::Servo_Motor::~Servo_Motor() {

}

int Motor::Servo_Motor::Convert_Degrees_To_Pulse_Width(float degrees) {

    int pulse_width = 0;

    try {

    }
    catch (exception ex) {
       Logger::Error(  Error_Messaging::Outside_Servo_PWM_Range );
    }
    return 0;
}
