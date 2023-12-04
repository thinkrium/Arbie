//
// Created by thome on 11/30/2023.
//

#ifndef ARBIE_ELBOW_H
#define ARBIE_ELBOW_H

#include "../Joint/Joint.h"

#include "../../../Utilities/Pinouts/Arm_Pinout/Arm_Pinout.h"

using namespace Utilities::Pinouts;

namespace Body {
    namespace Parts {
        class Elbow : public Joint {
        public:
            Elbow(Arm_Pinout armPinout);

            ~Elbow() override;

            explicit Elbow(const map<Relative_Axes, Axis> &axes);

        };

    }
}


#endif //ARBIE_ELBOW_H
