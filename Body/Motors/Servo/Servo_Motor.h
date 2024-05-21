#ifndef _WINDOWS
//
// Created by thome on 11/9/2023.
//
#ifndef ARBIE_SERVO_MOTOR_H

#define ARBIE_SERVO_MOTOR_H

#include "../Base/Base_Motor.h"

#include "../../../Utilities/Enumerations.h"
#include "../../../Utilities/Error_Messaging.h"
#include "../../Libraries/PCA9685/PCA9685.h"

using namespace Utilities::Enumerations;

namespace Motors {
    class Servo_Motor : public Base_Motor {

    public:
        Servo_Motor();

        Servo_Motor(int motorFrequency);

        Servo_Motor( int pinNumber, int degreeOfRotation,  int absoluteRangeOfDegrees, int minimumPulseWidth, int maximumPulseWidth,
                    int motorFrequency);

        explicit Servo_Motor(int pinNumber, int initialDegreeOfRotation, Servo_Motor_Profile servoMotorProfile);

        void Turn_Motor( Rotation_Direction rotationDirection, int degrees, float speed) override;

        ~Servo_Motor() override;

        int getPulseWidth() const;

        void setPulseWidth(int pulseWidth);

        int getMaximumPulseWidth() const;

        void setMaximumPulseWidth(int maximumPulseWidth);

        int getMotorFrequency() const;

        void setMotorFrequency(int motorFrequency);

        int getAbsoluteRangeOfDegrees() const;

        void setAbsoluteRangeOfDegrees(int absoluteRangeOfDegrees);

        int getNeutralPulseWidth() const;

        void setNeutralPulseWidth(int neutralPulseWidth);

        int determineNeutralPulseWidth(int maximumPulseWidth, int minimumPulseWidth);
    private:

        PCA9685 pwm;

        // TODO: CHECK IF THESE FUNCTIONS ARE SUPPOSE TO BE PRIVATE

        float getPulseWidthFromDegreeStep() const;

        void setPulseWidthFromDegreeStep(float pulseWidthFromDegreeStep);

        int getMinimumPulseWidth() const;

        void setMinimumPulseWidth(int minimumPulseWidth);

        void  determinePulseWidthDegreeStep();

        int convertDegreesToPulseWidth(int degrees);

        int determinePulseWidth(float onTimePercentage);

        int pulse_width;

        int maximum_pulse_width;

        int minimum_pulse_width;

        float pulse_width_from_degree_step;

        int neutral_pulse_width;

    private:
        int absolute_range_of_degrees;

        int motor_frequency;
    };
}

#endif //ARBIE_SERVO_MOTOR_H
#endif
