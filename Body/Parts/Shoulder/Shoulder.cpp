//
// Created by thome on 11/28/2023.
//

#include "Shoulder.h"

namespace Body {
    namespace Parts {


        Axis Shoulder::getAxis(Relative_Axes orientationAxis) {
            Axis a;
            return a ;
        }
        void Shoulder::setAxes(map<Relative_Axes, Axis> axes) {
            this->axes = axes;
        }

        void Shoulder::addAxis(Relative_Axes orientationAxis, Axis axis) {
            this->axes.insert({orientationAxis, axis});
        }

        map<Relative_Axes, Axis> Shoulder::getAxes() {
            return map<Relative_Axes, Axis>();
        }

        Shoulder::Shoulder(const map<Relative_Axes, Axis> &axes) : axes(axes) {}

        Shoulder::~Shoulder() {

        }

        void Shoulder::turnShoulderOnAxis(Relative_Axes orientationAxis, Rotation_Direction direction, int degrees) {
            this->axes[orientationAxis].turnMotor(direction, degrees);
        }

    } // Body
} // Parts