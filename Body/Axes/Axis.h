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
            Axis(const Servo_Motor &motor, Relative_Axes orientationAxes);

            Axis();

            explicit Axis(const Servo_Motor &motor);

            const Servo_Motor &getMotor() const;

            void setMotor(const Servo_Motor &motor);

            Relative_Axes getOrientationAxes() const;

            void setOrientationAxes(Relative_Axes orientationAxes);

            void turnMotor(Rotation_Direction direction, int degrees);

        private:
            Relative_Axes orientation_axes;
            Servo_Motor motor;

        };

    } // Body
} // Axes

#endif //ARBIE_AXIS_H
