//
// Created by thome on 11/28/2023.
//

#include "Shoulder.h"

namespace Body {
    namespace Parts {

        Shoulder::~Shoulder() {

        }

        Shoulder::Shoulder(const map<Relative_Axes, Axis> &axes) : Joint(axes) {}

        Shoulder::Shoulder() {

            Servo_Motor_Profile profile;
            Servo_Motor
                    shoulderPitchServoMotor(0, 0, profile),
                    shoulderYawServoMotor(1, 0, profile),
                    rollServoMotor(2, 0, profile);

            Axis xAxis(shoulderPitchServoMotor),
                    yAxis(shoulderYawServoMotor),
                    zAxis(rollServoMotor);

            map<Relative_Axes, Axis> axes = {
                    {Relative_Axes::x, xAxis},
                    {Relative_Axes::y, yAxis},
                    {Relative_Axes::z, zAxis}
            };
        }


    } // Body
} // Parts