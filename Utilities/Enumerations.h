//
// Created by thome on 11/28/2023.
//

#ifndef ARBIE_ENUMERATIONS_H
#define ARBIE_ENUMERATIONS_H

namespace Utilities {
    namespace Enumerations {
        enum Rotation_Direction {Clockwise, Counter_Clockwise};
        enum Pin_Number {zero, one, two};
        enum Side_Of_Body {left, right};
        enum Relative_Axes {x, z, y, single};
        enum Processes {Movement, Console_Input};
        enum Body_Part {
            upper_arm_bone,
            fore_arm_bone,
            elbow,
            wrist,
            shoulder,
            neck,
            hip,
            upper_leg_bone,
            shin_bone,
            knee,
            ankle,
            instep,
            toes,
            head
        };

        struct Servo_Motor_Profile {
        public:
            inline static int motorFrequency = 200;
            inline static int minimumPulseWidth = 500;
            inline static int maximumPulseWidth = 2500;
            inline static int neutralPulseWidth = 1500;
            inline static int absoluteDegreeRange = 135;
        };

        // Might move this into its own file
        // I dont know semantically the best place for it yet
        class
        Joint_Turning_Instructions {
            Rotation_Direction rotation_direction;
            int degrees_of_rotation;
        public:
            Joint_Turning_Instructions(Rotation_Direction rotationDirection, int degreesOfRotation) {
                this->rotation_direction = rotationDirection;
                this->degrees_of_rotation = degreesOfRotation;
            }

            Rotation_Direction getRotationDirection() {return this->rotation_direction;}
            int getDegreesOfRotation() const {return  this->degrees_of_rotation;}

            ~Joint_Turning_Instructions() = default;
        };

    }
}
#endif //ARBIE_ENUMERATIONS_H
