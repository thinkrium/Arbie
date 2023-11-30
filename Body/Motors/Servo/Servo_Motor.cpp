//
// Created by thome on 11/9/2023.
//

#include <unistd.h>
#include "Servo_Motor.h"
#include "../Base/Base_Motor.h"
#include "../../Libraries/PCA9685/PCA9685.h"
#include "../../../Utilities/Logger/Logger.h"

using namespace Utilities;

Motors::Servo_Motor::Servo_Motor() {}

void Motors::Servo_Motor::Turn_Motor(Rotation_Direction rotationDirection, int degrees, float speed) {
    int pulseWidth = this->convertDegreesToPulseWidth(degrees);

    int pulseWidthAdjustment;

    try {



        if (rotationDirection == Rotation_Direction::Counter_Clockwise) {

            pulseWidthAdjustment = this->getNeutralPulseWidth() - pulseWidth;
        } else {
            pulseWidthAdjustment = this->getNeutralPulseWidth() + pulseWidth;
        }


        if(
                pulseWidthAdjustment < this->getMinimumPulseWidth()
                ||
                pulseWidthAdjustment > this->getMaximumPulseWidth()
                )
        {
            throw exception(  );
        }

        pwm.setPWM(this->getPinNumber(), 0, pulseWidthAdjustment);

    }
    catch (exception ex) {
        Logger::Warn( "Servo_Motor","TurnMotor", Error_Messaging::Outside_Servo_PWM_Range);
    }


}

Motors::Servo_Motor::Servo_Motor(int pinNumber, int initialDegreeOfRotation, Servo_Motor_Profile servoMotorProfile) : Base_Motor(pinNumber) {

    try {

        this->setPinNumber(pinNumber);
        this->setDegreeOfRotation(  initialDegreeOfRotation );
        this->setAbsoluteRangeOfDegrees(servoMotorProfile.absoluteDegreeRange);
        this->setMinimumPulseWidth(servoMotorProfile.minimumPulseWidth);
        this->setMaximumPulseWidth(servoMotorProfile.maximumPulseWidth);
        this->setNeutralPulseWidth(servoMotorProfile.neutralPulseWidth);
        this->setMotorFrequency(servoMotorProfile.motorFrequency);
        this->determinePulseWidthDegreeStep();

        // the 1 here '/ below is a bus number which is different than pin number
        pwm.init(1,0x40);
        usleep(1000 * 100);

        pwm.setPWMFreq (this->getMotorFrequency());

        Logger::Success("Servo","Servo", Error_Messaging::Servo_Motor_Init_Succeeded);
    }
    catch (exception ex) {
        Logger::Error("Servo","Servo",Error_Messaging::Servo_Motor_General_Failure);
    }
}

Motors::Servo_Motor::~Servo_Motor() {


}


/**
 * The
 * @param degrees
 * @return
 */
int Motors::Servo_Motor::convertDegreesToPulseWidth(int degrees) {

    int pulse_width = 0;

    try {
       pulse_width = this->getPulseWidthFromDegreeStep() * degrees;
       return pulse_width;
    }
    catch (exception ex) {
       Logger::Error( "Servo","convertDegreesToPulseWidth",  Error_Messaging::Outside_Servo_PWM_Range );
    }
    return -1;
}

/**
 * The definition of pulse width is % of on time / frequency
 * @return
 */
int Motors::Servo_Motor::determinePulseWidth(float onTimePercentage) {

    return (int) (onTimePercentage / this->getMotorFrequency());

}

Motors::Servo_Motor::Servo_Motor(int motorFrequency) {
   this->motor_frequency =  motorFrequency;
}

int Motors::Servo_Motor::getPulseWidth() const {
    return pulse_width;
}

void Motors::Servo_Motor::setPulseWidth(int pulseWidth) {
    pulse_width = pulseWidth;
}

int Motors::Servo_Motor::getMaximumPulseWidth() const {
    return maximum_pulse_width;
}

void Motors::Servo_Motor::setMaximumPulseWidth(int maximumPulseWidth) {
    maximum_pulse_width = maximumPulseWidth;
}

int Motors::Servo_Motor::getMotorFrequency() const {
    return motor_frequency;
}

void Motors::Servo_Motor::setMotorFrequency(int motorFrequency) {
    motor_frequency = motorFrequency;
}

int Motors::Servo_Motor::getMinimumPulseWidth() const {

    return minimum_pulse_width;
}


Motors::Servo_Motor::Servo_Motor(int pinNumber, int degreeOfRotation, int absoluteRangeOfDegrees, int minimumPulseWidth, int maximumPulseWidth,
                                 int motorFrequency) : Base_Motor(pinNumber) {
    try {

        this->setPinNumber(pinNumber);
        this->setDegreeOfRotation(degreeOfRotation);
        this->setAbsoluteRangeOfDegrees(absoluteRangeOfDegrees);
        this->setMinimumPulseWidth(minimumPulseWidth);
        this->setMaximumPulseWidth(maximumPulseWidth);
        this->setNeutralPulseWidth(
                this->determineNeutralPulseWidth( this->getMaximumPulseWidth(), this->getMinimumPulseWidth())
        );
        this->setMotorFrequency(motorFrequency);
        this->determinePulseWidthDegreeStep();


        // the 1 here '/ below is a bus number which is different then pin number
        pwm.init(1,0x40);
        usleep(1000 * 100);
        pwm.setPWMFreq (this->getMotorFrequency());

        Logger::Success("Servo_Motor" , "Servo_Motor", Error_Messaging::Servo_Motor_Init_Succeeded);
    }
    catch (exception ex) {
       Logger::Error("Servo_Motor" , "Servo_Motor", Error_Messaging::Servo_Motor_General_Failure);
    }
}

void Motors::Servo_Motor::setMinimumPulseWidth(int minimumPulseWidth) {
    minimum_pulse_width = minimumPulseWidth;
}

float Motors::Servo_Motor::getPulseWidthFromDegreeStep() const {
    return pulse_width_from_degree_step;
}

void Motors::Servo_Motor::setPulseWidthFromDegreeStep(float pulseWidthFromDegreeStep) {
    pulse_width_from_degree_step = pulseWidthFromDegreeStep;
}

void Motors::Servo_Motor::determinePulseWidthDegreeStep() {
    float neutral_position_pulse_width_range = ((this->getMaximumPulseWidth() - this->getMinimumPulseWidth()) / 2) ;
    float step =  (neutral_position_pulse_width_range / this->getAbsoluteRangeOfDegrees());
    this->setPulseWidthFromDegreeStep(step);
}

int Motors::Servo_Motor::getAbsoluteRangeOfDegrees() const {
    return absolute_range_of_degrees;
}

void Motors::Servo_Motor::setAbsoluteRangeOfDegrees(int absoluteRangeOfDegrees) {
    absolute_range_of_degrees = absoluteRangeOfDegrees;
}

int Motors::Servo_Motor::getNeutralPulseWidth() const {
    return neutral_pulse_width;
}

void Motors::Servo_Motor::setNeutralPulseWidth(int neutralPulseWidth) {
    neutral_pulse_width = neutralPulseWidth;
}

int Motors::Servo_Motor::determineNeutralPulseWidth(int maximumPulseWidth, int minimumPulseWidth) {
    return ((maximumPulseWidth - minimumPulseWidth) / 2) + minimumPulseWidth;
}



