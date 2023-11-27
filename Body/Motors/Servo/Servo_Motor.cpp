//
// Created by thome on 11/9/2023.
//

#include <unistd.h>
#include "Servo_Motor.h"
#include "../Base/Base_Motor.h"
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


/**
 * The
 * @param degrees
 * @return
 */
int Motor::Servo_Motor::convertDegreesToPulseWidth(float degrees) {

    int pulse_width = 0;

    try {

    }
    catch (exception ex) {
       Logger::Error(  Error_Messaging::Outside_Servo_PWM_Range );
    }
    return 0;
}

/**
 * The definition of pulse width is % of on time / frequency
 * @return
 */
int Motor::Servo_Motor::determinePulseWidth(float onTimePercentage) {

    return (int) (onTimePercentage / this->getMotorFrequency());

}

Motor::Servo_Motor::Servo_Motor(int motorFrequency) {
   this->motor_frequency =  motorFrequency;
}

int Motor::Servo_Motor::getPulseWidth() const {
    return pulse_width;
}

void Motor::Servo_Motor::setPulseWidth(int pulseWidth) {
    pulse_width = pulseWidth;
}

int Motor::Servo_Motor::getMaximumPulseWidth() const {
    return maximum_pulse_width;
}

void Motor::Servo_Motor::setMaximumPulseWidth(int maximumPulseWidth) {
    maximum_pulse_width = maximumPulseWidth;
}

int Motor::Servo_Motor::getMotorFrequency() const {
    return motor_frequency;
}

void Motor::Servo_Motor::setMotorFrequency(int motorFrequency) {
    motor_frequency = motorFrequency;
}

int Motor::Servo_Motor::getMinimumPulseWidth() const {

    return minimum_pulse_width;
}

Motor::Servo_Motor::Servo_Motor(int pinNumber,  int degreeOfRotation, int absoluteRangeOfDegrees,  int minimumPulseWidth, int maximumPulseWidth,
                                int motorFrequency) : Base_Motor(pinNumber) {
    try {

        this->setPinNumber(pinNumber);
        this->setDegreeOfRotation(degreeOfRotation);
        this->setAbsoluteRangeOfDegrees(absoluteRangeOfDegrees);
        this->setMinimumPulseWidth(minimumPulseWidth);
        this->setMaximumPulseWidth(maximumPulseWidth);
        this->setMotorFrequency(motorFrequency);
        this->determinePulseWidthDegreeStep();

        Logger::Success(Error_Messaging::Servo_Motor_Init_Succeeded);
    }
    catch (exception ex) {
       Logger::Error(Error_Messaging::Servo_Motor_General_Failure);
    }
}

void Motor::Servo_Motor::setMinimumPulseWidth(int minimumPulseWidth) {
    minimum_pulse_width = minimumPulseWidth;
}

float Motor::Servo_Motor::getPulseWidthDegreeStep() const {
    return pulse_width_degree_step;
}

void Motor::Servo_Motor::setPulseWidthDegreeStep(float pulseWidthDegreeStep) {
    pulse_width_degree_step = pulseWidthDegreeStep;
}

void Motor::Servo_Motor::determinePulseWidthDegreeStep() {
    float neutral_position_pulse_width_range = ((this->getMaximumPulseWidth() - this->getMinimumPulseWidth()) / 2) ;
    float step =  (neutral_position_pulse_width_range / this->getAbsoluteRangeOfDegrees());
    this->setPulseWidthDegreeStep(step);
    Logger::Info(to_string(step));
}

int Motor::Servo_Motor::getAbsoluteRangeOfDegrees() const {
    return absolute_range_of_degrees;
}

void Motor::Servo_Motor::setAbsoluteRangeOfDegrees(int absoluteRangeOfDegrees) {
    absolute_range_of_degrees = absoluteRangeOfDegrees;
}



