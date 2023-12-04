//
// Created by thome on 12/2/2023.
//

#ifndef ARBIE_WRIST_H
#define ARBIE_WRIST_H

#include "../Joints/Arm_Joint/Arm_Joint.h"

#include "../../../Utilities/Pinouts/Arm_Pinout/Arm_Pinout.h"

using namespace Utilities::Pinouts;

namespace Body {
    namespace Parts {

        namespace Joints {
            class Wrist : public Arm_Joint {
            public:
                Wrist(Arm_Pinout armPinout);

                Wrist();

                ~Wrist() override;

            };
        }
    } // Body
} // Parts

#endif //ARBIE_WRIST_H
