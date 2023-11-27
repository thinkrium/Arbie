//
// Created by thome on 11/9/2023.
//

#ifndef ARBIE_SERVO_MOTOR_H
#define ARBIE_SERVO_MOTOR_H

#include "../Base/Base_Motor.h"

#include "../Utilities/Error_Messaging.h"
#include "../../Libraries/PCA9685/PCA9685.h"

namespace Motor {
    class Servo_Motor : public Base_Motor {

    public:
        Servo_Motor();

        Servo_Motor(int motorFrequency);

        Servo_Motor( int pinNumber, int degreeOfRotation,  int absoluteRangeOfDegrees, int minimumPulseWidth, int maximumPulseWidth,
                    int motorFrequency);

        void Turn_Motor(Rotation_Direction rotationDirection, float degrees, float speed) override;

        ~Servo_Motor() override;

        int getPulseWidth() const;

        void setPulseWidth(int pulseWidth);

        int getMaximumPulseWidth() const;

        void setMaximumPulseWidth(int maximumPulseWidth);

        int getMotorFrequency() const;

        void setMotorFrequency(int motorFrequency);

    private:

        PCA9685 pwm;

        void  determinePulseWidthDegreeStep();

        int convertDegreesToPulseWidth(float degrees);

        int determinePulseWidth(float onTimePercentage);

        int pulse_width;

        int maximum_pulse_width;

        int minimum_pulse_width;

        float pulse_width_from_degree_step;


        float getPulseWidthFromDegreeStep() const;

        void setPulseWidthFromDegreeStep(float pulseWidthFromDegreeStep);

        int absolute_range_of_degrees;
    public:
        int getAbsoluteRangeOfDegrees() const;

        void setAbsoluteRangeOfDegrees(int absoluteRangeOfDegrees);

    private:
        int getMinimumPulseWidth() const;

        void setMinimumPulseWidth(int minimumPulseWidth);

        int motor_frequency;
    };
}

#endif //ARBIE_SERVO_MOTOR_H
