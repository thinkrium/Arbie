//
// Created by thome on 11/28/2023.
//

#ifndef ARBIE_ENUMERATIONS_H
#define ARBIE_ENUMERATIONS_H

namespace Utilities {
    namespace Enumerations {
        enum Rotation_Direction {Clockwise, Counter_Clockwise};
        enum Pin_Number {zero, one, two};
        enum Body_Side {left, right};
        enum Relative_Axes {x, z, y};
        enum Body_Part {upper_arm, fore_arm, elbow, shoulder, neck, hip, upper_leg, lower_leg, knee, ankle, instep, toes, head};

        struct Servo_Motor_Profile {
        public:
            inline static int motorFrequency = 200;
            inline static int minimumPulseWidth = 500;
            inline static int maximumPulseWidth = 2500;
            inline static int absoluteDegreeRange = 135;
        };

    }
}
#endif //ARBIE_ENUMERATIONS_H
