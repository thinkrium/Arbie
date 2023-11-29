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
            Axis(const Servo_Motor &motor,  Orientation_Axes orientationAxes);

            Axis();

            const Servo_Motor &getMotor() const;

            void setMotor(const Servo_Motor &motor);

            Orientation_Axes getOrientationAxes() const;

            void setOrientationAxes( Orientation_Axes orientationAxes);

        private:
            Orientation_Axes orientation_axes;
            Servo_Motor motor;

        };

    } // Body
} // Axes

#endif //ARBIE_AXIS_H
