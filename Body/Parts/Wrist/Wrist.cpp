//
// Created by thome on 12/2/2023.
//

#include "Wrist.h"

namespace Body {
    namespace Parts {
        namespace Joints {
            Wrist::Wrist(Arm_Pinout armPinout) {}

            Wrist::~Wrist() {
            }

            Wrist::Wrist() {

            }

            void Wrist::setAxisMotor() {
                try {
                    Servo_Motor_Profile profile;
                    Servo_Motor
                            xAxisServoMotor(getArmPinout().getWristPinNumber(), 0, profile);

                    this->getAxes()[Relative_Axes::x].setMotor(xAxisServoMotor);


                    Logger::Success("Wrist", "setAxisMotor", Error_Messaging::Object_Initiated_Successfully);

                }
                catch (exception e) {
                    Logger::Error("Wrist", "setAxisMotor", Error_Messaging::Object_Failed_To_Initiated);
                }

            }
        }
    } // Body
} // Parts