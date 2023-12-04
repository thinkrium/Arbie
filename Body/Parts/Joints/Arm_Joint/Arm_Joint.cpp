//
// Created by thome on 12/4/2023.
//

#include "Arm_Joint.h"

namespace Body {
    namespace Parts {
        namespace Joints {
            Arm_Joint::Arm_Joint() {}

            Arm_Joint::~Arm_Joint() {

            }

            const Arm_Pinout &Arm_Joint::getArmPinout() const {
                return armPinout;
            }

            void Arm_Joint::setArmPinout(const Arm_Pinout &armPinout) {
                Arm_Joint::armPinout = armPinout;
            }
        } // Body
    } // Parts
} // Joints