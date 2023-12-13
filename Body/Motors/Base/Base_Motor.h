//
// Created by thome on 11/9/2023.
//

#ifndef ARBIE_BASE_MOTOR_H
#define ARBIE_BASE_MOTOR_H

#include "../../../Utilities/Enumerations.h"
#include "iostream"

using namespace std;

using namespace Utilities::Enumerations;


namespace Motors {

    class Base_Motor {

    public:

        Base_Motor();

        Base_Motor(int pinNumber);

        /**
         * Gets the current degree of rotation for this motor
         * @return
         */
        int getDegreeOfRotation() const;


        /**
         * Sets the current degree of rotation for this motor
         * @return
         */
        void setDegreeOfRotation(int degreeOfRotation);

        /**
         * Base function to implement for any axis motor turning functionality
         * @param rotationDirection
         * @param degrees
         * @param speed
         */
        virtual void Turn_Motor(Rotation_Direction rotationDirection, int degrees, float speed) = 0;

        virtual ~Base_Motor();

        /**
         * Gets the current pin number for this motor
         * @return
         */
         int getPinNumber() const;

        /**
         * Sets the current pin number for this motor
         * @return
         */
        void setPinNumber(int pinNumber);

        /**
         * Gets the current name for this motor
         * @return
         */
        const string &getMotorName() const;

        /**
         * Sets the current name for this motor
         * @return
         */
        void setMotorName(const string &motorName);

        /**
         * name of the motor - for debugging and identification
         */
        string motor_name;

    private:

        /**
         * Current degree of rotation for this motor
         */
        int degree_of_rotation;

        /**
         * pin number for this motor
         */
        int pin_number;
      };
}

#endif //ARBIE_BASE_MOTOR_H
