//
// Created by thome on 12/3/2023.
//

#ifndef ARBIE_ARM_PINOUT_H
#define ARBIE_ARM_PINOUT_H

namespace Pinouts {

    class Arm_Pinout {
        int shoulder_x_axis;
        int shoulder_y_axis;
        int shoulder_z_axis;
        int elbow;
        int wrist;
    public:
        Arm_Pinout();

        Arm_Pinout(int shoulderXAxis, int shoulderYAxis, int shoulderZAxis, int elbow, int wrist);

        virtual ~Arm_Pinout();

        int getShoulderXAxis() const;

        void setShoulderXAxis(int shoulderXAxis);

        int getShoulderYAxis() const;

        void setShoulderYAxis(int shoulderYAxis);

        int getShoulderZAxis() const;

        void setShoulderZAxis(int shoulderZAxis);

        int getElbow() const;

        void setElbow(int elbow);

        int getWrist() const;

        void setWrist(int wrist);
    };

} // Pinouts

#endif //ARBIE_ARM_PINOUT_H
