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

        Base_Motor(int pinNumber);

        int getDegreeOfRotation() const;

        void setDegreeOfRotation(int degreeOfRotation);

        virtual void Turn_Motor(Rotation_Direction rotationDirection, float degrees, float speed) = 0;

        virtual ~Base_Motor();

         int getPinNumber() const;

        void setPinNumber(int pinNumber);

    private:
        int degree_of_rotation;
        int pin_number;
      };
}

#endif //ARBIE_BASE_MOTOR_H
