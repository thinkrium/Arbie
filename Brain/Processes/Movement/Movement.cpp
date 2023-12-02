//
// Created by thome on 12/1/2023.
//

#include "Movement.h"

namespace Brain {
    namespace Processes {


        const Whole_Body &Movement::getWholeBody() const {
            return whole_body;
        }

        void Movement::Start() {
            try {

                this->whole_body.getArms();

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

                Shoulder shoulder(
                        axes
                );

                shoulder.turnOnAxis(Relative_Axes::x, Rotation_Direction::Counter_Clockwise, 30);
                shoulder.turnOnAxis(Relative_Axes::y, Rotation_Direction::Counter_Clockwise, 30);
                shoulder.turnOnAxis(Relative_Axes::z, Rotation_Direction::Counter_Clockwise, 30);

                Logger::Success("Brain::Activity", "Run", Error_Messaging::No_Error);
            }
            catch (exception e) {
                Logger::Success("Brain::Activity", "Run", Error_Messaging::Generic_Error);

            }

        }

        Movement::~Movement() {

        }

        Movement::Movement() {}
    } // Brain
} // Processes