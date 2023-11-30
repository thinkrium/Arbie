//
// Created by thome on 11/29/2023.
//

#include "Joint.h"

namespace Body {
    namespace Parts {
        Joint::Joint() {}


        Axis Joint::getAxis(Relative_Axes orientationAxis) {
            Axis a;
            return a ;
        }
        void Joint::setAxes(map<Relative_Axes, Axis> axes) {
            this->axes = axes;
        }

        void Joint::addAxis(Relative_Axes orientationAxis, Axis axis) {
            this->axes.insert({orientationAxis, axis});
        }

        map<Relative_Axes, Axis> Joint::getAxes() {
            return map<Relative_Axes, Axis>();
        }


        void Joint::turnOnAxis(Relative_Axes orientationAxis, Rotation_Direction direction, int degrees) {
            this->axes[orientationAxis].turnMotor(direction, degrees);
        }

        Joint::Joint(const map<Relative_Axes, Axis> &axes) : axes(axes) {
            this->setAxes(axes);
        }

        Joint::~Joint() {

        }
    } // Body
} // Parts