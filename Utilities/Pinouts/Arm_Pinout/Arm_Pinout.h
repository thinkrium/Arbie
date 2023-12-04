//
// Created by thome on 12/3/2023.
//

#ifndef ARBIE_ARM_PINOUT_H
#define ARBIE_ARM_PINOUT_H
namespace Utilities {
    namespace Pinouts {

        class Arm_Pinout {
            int shoulder_x_axis_pin_number;
            int shoulder_y_axis_pin_number;
            int shoulder_z_axis_pin_number;
            int elbow_pin_number;
            int wrist_pin_number;
        public:
            Arm_Pinout();

            Arm_Pinout(int shoulderXAxis, int shoulderYAxis, int shoulderZAxis, int elbow, int wrist);

            virtual ~Arm_Pinout();

            int getShoulderXAxisPinNumber() const;

            void setShoulderXAxisPinNumber(int shoulderXAxis);

            int getShoulderYAxisPinNumber() const;

            void setShoulderYAxisPinNumber(int shoulderYAxis);

            int getShoulderZAxisPinNumber() const;

            void setShoulderZAxisPinNumber(int shoulderZAxis);

            int getElbowPinNumber() const;

            void setElbowPinNumber(int elbow);

            int getWristPinNumber() const;

            void setWristPinNumber(int wrist);
        };

    } // Pinouts
}
#endif //ARBIE_ARM_PINOUT_H
