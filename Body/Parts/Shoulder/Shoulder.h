//
// Created by thome on 11/28/2023.
//

#ifndef ARBIE_SHOULDER_H
#define ARBIE_SHOULDER_H

#include "../Joint/Joint.h"
#include "map"
#include "../../Axes/Axis.h"

using namespace Body::Axes;

namespace Body {
    namespace Parts {

        class Shoulder : public Joint {

        private:

            map<Relative_Axes, Axis> axes;

        public:

            Shoulder();

            explicit Shoulder(const map<Relative_Axes, Axis> &axes);

            Axis getAxis(Relative_Axes orientationAxis);
            map<Relative_Axes, Axis> getAxes();
            void setAxes(map<Relative_Axes, Axis> axes);
            void addAxis(Relative_Axes orientationAxis, Axis axis);

            void turnShoulderOnAxis(Relative_Axes orientationAxis, Rotation_Direction direction, int degrees);
            ~Shoulder() override;

        };

    } // Body
} // Parts

#endif //ARBIE_SHOULDER_H
