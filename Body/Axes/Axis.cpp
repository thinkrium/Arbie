//
// Created by thome on 11/28/2023.
//

#include "Axis.h"
#include "../../Utilities/Enumerations.h"
#include "../Motors/Servo/Servo_Motor.h"

using namespace Motors;

namespace Body {
    namespace Axes {


        Axis::Axis(const Servo_Motor &motor, Orientation_Axes orientationAxes) : motor(motor),
                                                                                 orientation_axes(orientationAxes) {}

        Axis::Axis() {}

        const Servo_Motor &Axis::getMotor() const {
            return motor;
        }

        void Axis::setMotor(const Servo_Motor &motor) {
            Axis::motor = motor;
        }

        Orientation_Axes Axis::getOrientationAxes() const {
            return orientation_axes;
        }

        void Axis::setOrientationAxes(Orientation_Axes orientationAxes) {
            orientation_axes = orientationAxes;
        }
    } // Body
} // Axes