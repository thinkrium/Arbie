//
// Created by thome on 11/28/2023.
//

#ifndef ARBIE_SHOULDER_H
#define ARBIE_SHOULDER_H

#include "../Joints/Arm_Joint/Arm_Joint.h"
#include "../../../Utilities/Pinouts/Arm_Pinout/Arm_Pinout.h"

using namespace Utilities::Pinouts;

namespace Body {
    namespace Parts {

        namespace Joints {
            class Shoulder : public Arm_Joint {

            public:

                Shoulder(Arm_Pinout armPinout);

                ~Shoulder() override;

//                explicit Shoulder(const map<Relative_Axes, Axis> &axes);

            };
        }
    } // Body
} // Parts

#endif //ARBIE_SHOULDER_H
