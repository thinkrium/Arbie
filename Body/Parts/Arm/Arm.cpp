#ifndef _WINDOWS
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
                shoulder.setPartName(Body_Part::shoulder);

                elbow = Elbow (armPinout);
                elbow.setPartName(Body_Part::elbow);

                wrist = Wrist(armPinout);
                wrist.setPartName(Body_Part::wrist);

                upper_arm_bone = Bone(50);
                upper_arm_bone.setPartName(Body_Part::upper_arm_bone);

                fore_arm_bone = Bone(50);
                fore_arm_bone.setPartName(Body_Part::fore_arm_bone);

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

        const Bone &Arm::getUpperArmBone() const {
            return upper_arm_bone;
        }

        void Arm::setUpperArmBone(const Bone &upperArmBone) {
            upper_arm_bone = upperArmBone;
        }

        const Bone &Arm::getForeArmBone() const {
            return fore_arm_bone;
        }

        void Arm::setForeArmBone(const Bone &foreArmBone) {
            fore_arm_bone = foreArmBone;
        }
    } // Body
} // Parts

#endif
