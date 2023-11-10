//
// Created by thome on 11/9/2023.
//

#ifndef ARBIE_SERVO_H
#define ARBIE_SERVO_H

#include "../Base/Base.h"

#include "../Utilities/Error_Messaging.h"

namespace Motor {
    class Servo : public Base {

    public:
        Servo();

        void Turn_Motor(Rotation_Direction rotationDirection, float degrees, float speed) override;

        ~Servo() override;


    };
}

#endif //ARBIE_SERVO_H
