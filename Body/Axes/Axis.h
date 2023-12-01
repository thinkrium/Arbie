//
// Created by thome on 11/28/2023.
//

#ifndef ARBIE_AXIS_H
#define ARBIE_AXIS_H

#include "../Motors/Servo/Servo_Motor.h"
#include "../../Utilities/Enumerations.h"
#include "../../Utilities/Error_Messaging.h"

using namespace Motors;
using namespace Utilities::Enumerations;

namespace Body {
    namespace Axes {

        class Axis {

         public:
            /**
             * Sets the motor and axes
             * @param motor
             * @param orientationAxes
             */
            Axis(const Servo_Motor &motor, Relative_Axes orientationAxes);

            /**
             * Default constructor
             */
            Axis();

            /**
             * sets the motor
             * @param motor
             */
            explicit Axis(const Servo_Motor &motor);

            /**
             * Gets the motor
             * @return
             */
            const Servo_Motor &getMotor() const;

            /**
             * Sets the motor
             * @param motor
             */
            void setMotor(const Servo_Motor &motor);

            /**
             * Gets teh relative axis (found in enumerations.h)
             * @return
             */
            Relative_Axes getOrientationAxes() const;

            /**
             * sets the orientation axis
             * @param orientationAxes
             */
            void setOrientationAxes(Relative_Axes orientationAxes);

            /**
             * Turns the motor by calling the motor turning function in the motor object
             * to a specific rotation_direction ( found in enumeration.h )
             * to a specific degree
             * @param direction
             * @param degrees
             */
            void turnMotor(Rotation_Direction direction, int degrees);

        private:
            Relative_Axes orientation_axes;
            Servo_Motor motor;

        };

    } // Body
} // Axes

#endif //ARBIE_AXIS_H
