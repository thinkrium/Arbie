//
// Created by thome on 11/30/2023.
//

#include "Arm.h"

namespace Body {
    namespace Parts {
        Arm::Arm() {

        }

        Arm::Arm(Arm_Pinout armPinout) {
            try {

                shoulder = Shoulder(armPinout);
//                shoulder.setAxisMotor();

                elbow = Elbow (armPinout);
//                elbow.setAxisMotor();

                wrist = Wrist(armPinout);
//                wrist.setAxisMotor();
                
                Logger::Success("Arm", "Arm", Error_Messaging::Object_Initiated_Successfully);
            }
            catch (exception ex) {
                Logger::Error("Arm", "Arm", Error_Messaging::Object_Failed_To_Initiated);
            }
        }

        Arm::~Arm() {

        }

        const Shoulder &Arm::getShoulder() const {
            return shoulder;
        }

        void Arm::setShoulder(const Shoulder &shoulder) {
            Arm::shoulder = shoulder;
        }

        const Elbow &Arm::getElbow() const {
            return elbow;
        }

        void Arm::setElbow(const Elbow &elbow) {
            Arm::elbow = elbow;
        }

        const Wrist &Arm::getWrist() const {
            return wrist;
        }

        void Arm::setWrist(const Wrist &wrist) {
            Arm::wrist = wrist;
        }

        const Arm_Pinout &Arm::getArmPinout() const {
            return armPinout;
        }

        void Arm::setArmPinout(const Arm_Pinout &armPinout) {
            Arm::armPinout = armPinout;
        }
    } // Body
} // Parts