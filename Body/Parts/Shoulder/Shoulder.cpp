//
// Created by thome on 11/28/2023.
//

#include "Shoulder.h"

namespace Body {
    namespace Parts {

        Shoulder::~Shoulder() {

        }

        Shoulder::Shoulder(const map<Relative_Axes, Axis> &axes) : Joint(axes) {}


    } // Body
} // Parts