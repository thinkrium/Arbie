//
// Created by thome on 11/28/2023.
//

#include "Shoulder.h"

namespace Body {
    namespace Parts {

        namespace Joints {
            Shoulder::~Shoulder() {

            }

//            Shoulder::Shoulder(const map<Relative_Axes, Axis> &axes) : Arm_Joint(axes) {}

            Shoulder::Shoulder(Arm_Pinout armPinout) {

                Servo_Motor_Profile profile;
                Servo_Motor
                        shoulderXServoMotor(armPinout.getShoulderXAxisPinNumber(), 0, profile),
                        shoulderYServoMotor(armPinout.getShoulderYAxisPinNumber(), 0, profile),
                        shoulderZServoMotor(armPinout.getShoulderZAxisPinNumber(), 0, profile);

                Axis xAxis(shoulderXServoMotor),
                        yAxis(shoulderYServoMotor),
                        zAxis(shoulderZServoMotor);

                map<Relative_Axes, Axis> axes = {
                        {Relative_Axes::x, xAxis},
                        {Relative_Axes::y, yAxis},
                        {Relative_Axes::z, zAxis}
                };
            }

            Shoulder::Shoulder() {}
        }


    } // Body
} // Parts