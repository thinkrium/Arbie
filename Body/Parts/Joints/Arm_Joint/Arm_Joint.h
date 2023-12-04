//
// Created by thome on 12/4/2023.
//

#ifndef ARBIE_ARM_JOINT_H
#define ARBIE_ARM_JOINT_H

#include "../Base_Joint/Base_Joint.h"
#include "../../../../Utilities/Pinouts/Arm_Pinout/Arm_Pinout.h"

using namespace Utilities::Pinouts;

namespace Body {
    namespace Parts {
        namespace Joints {


            class Arm_Joint : Base_Joint {

            private:
                Arm_Pinout armPinout;

            };

        } // Body
    } // Parts
} // Joints

#endif //ARBIE_ARM_JOINT_H
