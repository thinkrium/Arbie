//
// Created by thome on 11/28/2023.
//

#include "Axis.h"
#include "../../Utilities/Enumerations.h"
#include "../Motors/Servo/Servo_Motor.h"

using namespace Motors;

namespace Body {
    namespace Axes {


        Axis::Axis(const Servo_Motor &motor, Relative_Axes orientationAxes) : motor(motor),
                                                                              orientation_axes(orientationAxes) {
            this->setMotor(motor);
            this->setOrientationAxes(orientationAxes);
        }

        Axis::Axis() {}

        const Servo_Motor &Axis::getMotor() const {
            return motor;
        }

        void Axis::setMotor(const Servo_Motor &motor) {
            Axis::motor = motor;
        }

        Relative_Axes Axis::getOrientationAxes() const {
            return orientation_axes;
        }

        void Axis::setOrientationAxes(Relative_Axes orientationAxes) {
            orientation_axes = orientationAxes;
        }

        Axis::Axis(const Servo_Motor &motor) : motor(motor) {
            this->setMotor(motor);

        }

        void Axis::turnMotor(Rotation_Direction direction, int degrees) {
            // TODO: Upgrade servo motors so i can control speed
            float dummySpeed = 0;
            motor.Turn_Motor(direction, degrees, dummySpeed);

        }
    } // Body
} // Axes