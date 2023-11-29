//
// Created by thome on 11/28/2023.
//

#include "Shoulder.h"

namespace Body {
    namespace Parts {


        Axis Shoulder::getOrientationAxis()  {
            Axis a;
            return a ;
        }
        void Shoulder::setOrientationAxes(map<Orientation_Axes, Axis> axes) {
            this->axes = axes;
        }

        void Shoulder::addOrientationAxis(Orientation_Axes orientationAxes, Axis axis) {
//            this->axes.insert( )
        }

        map<Orientation_Axes, Axis> Shoulder::getOrientationAxes() {
            return map<Orientation_Axes, Axis>();
        }

    } // Body
} // Parts