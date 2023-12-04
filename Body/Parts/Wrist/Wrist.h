//
// Created by thome on 12/2/2023.
//

#ifndef ARBIE_WRIST_H
#define ARBIE_WRIST_H

#include "../../../Body/Parts/Base/Base_Body_Part.h"

#include "../../../Utilities/Pinouts/Arm_Pinout/Arm_Pinout.h"

using namespace Utilities::Pinouts;

namespace Body {
    namespace Parts {

        class Wrist : public Base_Body_Part {
        public:
            Wrist(Arm_Pinout armPinout);

            ~Wrist() override;

        };

    } // Body
} // Parts

#endif //ARBIE_WRIST_H
