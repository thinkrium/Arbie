//
// Created by thome on 11/30/2023.
//

#include "Elbow.h"

namespace Body {
    namespace Parts {
        namespace Joints {
            Elbow::~Elbow() {

            }

//        Elbow::Elbow(const map<Relative_Axes, Axis> &axes) : Joint(axes) {}

            Elbow::Elbow(Arm_Pinout armPinout) {

            }

            Elbow::Elbow() {}

            void Elbow::setAxisMotor() {
                try {
                    Servo_Motor_Profile profile;
                    Servo_Motor
                            xAxisServoMotor(getArmPinout().getElbowPinNumber(), 0, profile);

                    this->getAxes()[Relative_Axes::x].setMotor(xAxisServoMotor);


                    Logger::Success("Elbow", "setAxisMotor", Error_Messaging::Object_Initiated_Successfully);

                }
                catch (exception e) {
                    Logger::Error("Elbow", "setAxisMotor", Error_Messaging::Object_Failed_To_Initiated);
                }

            }
        }

    } // Body
} // Parts