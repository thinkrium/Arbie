#ifndef _WINDOWS
//
// Created by thome on 11/28/2023.
//
#include "Shoulder.h"

namespace Body {
    namespace Parts {

        namespace Joints {
            Shoulder::~Shoulder() {

            }

            Shoulder::Shoulder(Arm_Pinout armPinout) : Arm_Joint() {

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

                this->setAxes(axes);
            }

            Shoulder::Shoulder() {

                Logger::Success("Shoulder", "Shoulder", Error_Messaging::Object_Initiated_Successfully);
            }

            void Shoulder::setAxisMotor() {

                try {
                    Servo_Motor_Profile profile;
                    Servo_Motor
                            xAxisServoMotor(getArmPinout().getShoulderXAxisPinNumber(), 0, profile)
                            , yAxisServoMotor(getArmPinout().getShoulderYAxisPinNumber(), 0, profile)
                            , zAxisServoMotor(getArmPinout().getShoulderZAxisPinNumber(), 0, profile);

                    this->getAxis( Relative_Axes::x).setMotor(xAxisServoMotor);
                    this->getAxis( Relative_Axes::y).setMotor(yAxisServoMotor);
                    this->getAxis( Relative_Axes::z).setMotor(zAxisServoMotor);

                    Logger::Success("Shoulder", "setAxisMotor", Error_Messaging::Object_Initiated_Successfully);

                }
                catch (exception e) {
                    Logger::Error("Shoulder", "setAxisMotor", Error_Messaging::Object_Failed_To_Initiated);
                }

            }

            void Shoulder::rotate(Joint_Turning_Instructions xAxisJointTurningInstructions,
                                  Joint_Turning_Instructions yAxisJointTurningInstructions,
                                  Joint_Turning_Instructions zAxisJointTurningInstructions) {

                this->getAxis(Relative_Axes::x).turnMotor(
                        xAxisJointTurningInstructions.getRotationDirection(),
                        xAxisJointTurningInstructions.getDegreesOfRotation()
                        );

                this->getAxis(Relative_Axes::y).turnMotor(
                        yAxisJointTurningInstructions.getRotationDirection(),
                        yAxisJointTurningInstructions.getDegreesOfRotation()
                );

                this->getAxis(Relative_Axes::z).turnMotor(
                        zAxisJointTurningInstructions.getRotationDirection(),
                        zAxisJointTurningInstructions.getDegreesOfRotation()
                );

            }



        }


    } // Body
} // Parts

#endif
