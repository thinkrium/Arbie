//
// Created by thome on 11/9/2023.
//

#ifndef ARBIE_BASE_MOTOR_H
#define ARBIE_BASE_MOTOR_H

#include "../Utilities/Enumerations.h"

using namespace Utilities::Enumerations;

namespace Motor {

    class Base_Motor {

    public:

        Base_Motor();

        Base_Motor(Pin_Number pinNumber);

        float getDegrees() const;

        void setDegrees(float degrees);

        virtual void Turn_Motor(Rotation_Direction rotationDirection, float degrees, float speed) = 0;

        virtual ~Base_Motor();

    private:
        float degrees;
        Pin_Number pin_number;


    public:
        Pin_Number getPinNumber() const;

        void setPinNumber(Pin_Number pinNumber);
    };
}

#endif //ARBIE_BASE_MOTOR_H
