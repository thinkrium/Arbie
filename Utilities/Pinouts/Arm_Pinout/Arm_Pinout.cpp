//
// Created by thome on 12/3/2023.
//

#include "Arm_Pinout.h"
namespace Utilities {
    namespace Pinouts {
        Arm_Pinout::Arm_Pinout() {}

        Arm_Pinout::~Arm_Pinout() {

        }

        int Arm_Pinout::getShoulderXAxis() const {
            return shoulder_x_axis;
        }

        void Arm_Pinout::setShoulderXAxis(int shoulderXAxis) {
            shoulder_x_axis = shoulderXAxis;
        }

        int Arm_Pinout::getShoulderYAxis() const {
            return shoulder_y_axis;
        }

        Arm_Pinout::Arm_Pinout(int shoulderXAxis, int shoulderYAxis, int shoulderZAxis, int elbow, int wrist)
                : shoulder_x_axis(shoulderXAxis), shoulder_y_axis(shoulderYAxis), shoulder_z_axis(shoulderZAxis),
                  elbow(elbow), wrist(wrist) {}

        void Arm_Pinout::setShoulderYAxis(int shoulderYAxis) {
            shoulder_y_axis = shoulderYAxis;
        }

        int Arm_Pinout::getShoulderZAxis() const {
            return shoulder_z_axis;
        }

        void Arm_Pinout::setShoulderZAxis(int shoulderZAxis) {
            shoulder_z_axis = shoulderZAxis;
        }

        int Arm_Pinout::getElbow() const {
            return elbow;
        }

        void Arm_Pinout::setElbow(int elbow) {
            Arm_Pinout::elbow = elbow;
        }

        int Arm_Pinout::getWrist() const {
            return wrist;
        }

        void Arm_Pinout::setWrist(int wrist) {
            Arm_Pinout::wrist = wrist;
        }
    } // Pinouts
}