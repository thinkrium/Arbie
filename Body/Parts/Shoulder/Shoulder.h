//
// Created by thome on 11/28/2023.
//

#ifndef ARBIE_SHOULDER_H
#define ARBIE_SHOULDER_H

#include "../Joint/Joint.h"

namespace Body {
    namespace Parts {

        class Shoulder : public Joint {

        public:

            Shoulder();

            ~Shoulder() override;

            explicit Shoulder(const map<Relative_Axes, Axis> &axes);

        };

    } // Body
} // Parts

#endif //ARBIE_SHOULDER_H
