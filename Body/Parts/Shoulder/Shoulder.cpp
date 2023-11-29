//
// Created by thome on 11/28/2023.
//

#include "Shoulder.h"

namespace Body {
    namespace Parts {


        Axis Shoulder::getAxis(Orientation_Axes orientationAxis) {
            Axis a;
            return a ;
        }
        void Shoulder::setAxes(map<Orientation_Axes, Axis> axes) {
            this->axes = axes;
        }

        void Shoulder::addAxis(Orientation_Axes orientationAxes, Axis axis) {
            this->axes.insert({orientationAxes, axis});
        }

        map<Orientation_Axes, Axis> Shoulder::getAxes() {
            return map<Orientation_Axes, Axis>();
        }

        Shoulder::Shoulder(const map<Orientation_Axes, Axis> &axes) : axes(axes) {}

        Shoulder::~Shoulder() {

        }

    } // Body
} // Parts