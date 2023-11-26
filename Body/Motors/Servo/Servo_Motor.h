//
// Created by thome on 11/9/2023.
//

#ifndef ARBIE_SERVO_MOTOR_H
#define ARBIE_SERVO_MOTOR_H

#include "../Base/Base_Motor.h"

#include "../Utilities/Error_Messaging.h"

namespace Motor {
    class Servo_Motor : public Base_Motor {

    public:
        Servo_Motor();

        void Turn_Motor(Rotation_Direction rotationDirection, float degrees, float speed) override;


        ~Servo_Motor() override;

    private:

        int Convert_Degrees_To_Pulse_Width(float degrees);

        int pulseWidth;

        int maximum_pulse_width;

        int frequency;
    };
}

#endif //ARBIE_SERVO_MOTOR_H
