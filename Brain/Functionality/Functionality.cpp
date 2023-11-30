//
// Created by thome on 11/30/2023.
//

#include "Functionality.h"

namespace Brain {
    namespace Functionality {
        void Functionality::Run() {

            Servo_Motor_Profile profile;

            Servo_Motor
                    pitchServoMotor(0,0, profile ),
                    yawServoMotor(1, 0,profile ),
                    rollServoMotor(2, 0,profile ) ;

            Axis xAxis(pitchServoMotor),
                    yAxis(yawServoMotor),
                    zAxis(rollServoMotor);

            map<Relative_Axes, Axis> axes = {
                    {Relative_Axes::x, xAxis},
                    {Relative_Axes::y, yAxis  },
                    {Relative_Axes::z, zAxis }
            };

            Shoulder shoulder(
                    axes
            );

            shoulder.turnOnAxis(Relative_Axes::x, Rotation_Direction::Counter_Clockwise, 30);
            shoulder.turnOnAxis(Relative_Axes::y, Rotation_Direction::Counter_Clockwise, 30);
            shoulder.turnOnAxis(Relative_Axes::z, Rotation_Direction::Counter_Clockwise, 30);

            Logger::Success("Main" , "Main", Error_Messaging::No_Error);

        }
    } // Brain
} // Functionality