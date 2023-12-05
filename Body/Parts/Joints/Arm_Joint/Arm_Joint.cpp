//
// Created by thome on 12/4/2023.
//

#include "Arm_Joint.h"

namespace Body {
    namespace Parts {
        namespace Joints {
            Arm_Joint::Arm_Joint() : Base_Joint() {}

            Arm_Joint::~Arm_Joint() {

            }

            const Arm_Pinout &Arm_Joint::getArmPinout() const {
                return armPinout;
            }

            void Arm_Joint::setArmPinout(const Arm_Pinout &armPinout) {
                try {
                    Arm_Joint::armPinout = armPinout;
                    Logger::Success("Arm_Joint", "setArmPinout", Error_Messaging::Object_Initiated_Successfully);
                }
                catch (exception e) {
                    Logger::Error("Arm_Joint", "setArmPinout", Error_Messaging::Object_Failed_To_Initiated);
                }
            }
        } // Body
    } // Parts
} // Joints