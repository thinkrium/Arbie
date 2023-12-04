//
// Created by thome on 12/3/2023.
//

#include "Arm_Pinout.h"
namespace Utilities {
    namespace Pinouts {
        Arm_Pinout::Arm_Pinout() {}

        Arm_Pinout::~Arm_Pinout() {

        }

        int Arm_Pinout::getShoulderXAxisPinNumber() const {
            return shoulder_x_axis_pin_number;
        }

        void Arm_Pinout::setShoulderXAxisPinNumber(int shoulderXAxis) {
            shoulder_x_axis_pin_number = shoulderXAxis;
        }

        int Arm_Pinout::getShoulderYAxisPinNumber() const {
            return shoulder_y_axis_pin_number;
        }

        Arm_Pinout::Arm_Pinout(int shoulderXAxis, int shoulderYAxis, int shoulderZAxis, int elbow, int wrist)
                : shoulder_x_axis_pin_number(shoulderXAxis), shoulder_y_axis_pin_number(shoulderYAxis), shoulder_z_axis_pin_number(shoulderZAxis),
                  elbow_pin_number(elbow), wrist_pin_number(wrist) {}

        void Arm_Pinout::setShoulderYAxisPinNumber(int shoulderYAxis) {
            shoulder_y_axis_pin_number = shoulderYAxis;
        }

        int Arm_Pinout::getShoulderZAxisPinNumber() const {
            return shoulder_z_axis_pin_number;
        }

        void Arm_Pinout::setShoulderZAxisPinNumber(int shoulderZAxis) {
            shoulder_z_axis_pin_number = shoulderZAxis;
        }

        int Arm_Pinout::getElbowPinNumber() const {
            return elbow_pin_number;
        }

        void Arm_Pinout::setElbowPinNumber(int elbow) {
            Arm_Pinout::elbow_pin_number = elbow;
        }

        int Arm_Pinout::getWristPinNumber() const {
            return wrist_pin_number;
        }

        void Arm_Pinout::setWristPinNumber(int wrist) {
            Arm_Pinout::wrist_pin_number = wrist;
        }
    } // Pinouts
}