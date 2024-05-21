#ifndef _WINDOWS
//
// Created by thome on 11/30/2023.
//
#include "Elbow.h"

namespace Body {
    namespace Parts {
        namespace Joints {
            Elbow::~Elbow() {

            }

            Elbow::Elbow(Arm_Pinout armPinout) {
                Servo_Motor_Profile profile;
                Servo_Motor
                        singleAxisServoMotor(getArmPinout().getElbowPinNumber(), 0, profile);

                Axis singleAxis(singleAxisServoMotor);

                map<Relative_Axes, Axis> axes = {
                        {Relative_Axes::single, singleAxis}
                };

                this->setAxes(axes);



            }

            void Elbow::rotate(Joint_Turning_Instructions singleAxisJointTurningInstructions) {

            }


            Elbow::Elbow() {}

            void Elbow::setAxisMotor() {
                try {
                    Servo_Motor_Profile profile;
                    Servo_Motor
                            xAxisServoMotor(getArmPinout().getElbowPinNumber(), 0, profile);

                    this->getAxis( Relative_Axes::single).setMotor(xAxisServoMotor);


                    Logger::Success("Elbow", "setAxisMotor", Error_Messaging::Object_Initiated_Successfully);

                }
                catch (exception e) {
                    Logger::Error("Elbow", "setAxisMotor", Error_Messaging::Object_Failed_To_Initiated);
                }

            }
        }

    } // Body
} // Parts

#endif
