//
// Created by thome on 11/30/2023.
//

#ifndef ARBIE_ELBOW_H
#define ARBIE_ELBOW_H

#include "../Joints/Arm_Joint/Arm_Joint.h"

#include "../../../Utilities/Pinouts/Arm_Pinout/Arm_Pinout.h"

using namespace Utilities::Pinouts;

namespace Body {
    namespace Parts {
        namespace Joints {
            class Elbow : public Arm_Joint {
            public:
                Elbow();

                Elbow(Arm_Pinout armPinout);

                ~Elbow() override;

//                explicit Elbow(const map<Relative_Axes, Axis> &axes);

            };
        }
    }
}


#endif //ARBIE_ELBOW_H
