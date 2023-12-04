//
// Created by thome on 11/30/2023.
//

#include "Elbow.h"

namespace Body {
    namespace Parts {

        Elbow::~Elbow() {

        }

        Elbow::Elbow(const map<Relative_Axes, Axis> &axes) : Joint(axes) {}

        Elbow::Elbow() {

        }


    } // Body
} // Parts