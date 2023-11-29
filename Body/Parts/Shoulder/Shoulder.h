//
// Created by thome on 11/28/2023.
//

#ifndef ARBIE_SHOULDER_H
#define ARBIE_SHOULDER_H

#include "../Base/Base_Body_Part.h"
#include "map"
#include "../../Axes/Axis.h"

using namespace Body::Axes;

namespace Body {
    namespace Parts {

        class Shoulder : public Base_Body_Part {

        private:

            map<Orientation_Axes, Axis> axes;

        public:

            Shoulder();

            explicit Shoulder(const map<Orientation_Axes, Axis> &axes);

            Axis getAxis(Orientation_Axes orientationAxis);
            map<Orientation_Axes, Axis> getAxes();
            void setAxes(map<Orientation_Axes, Axis> axes);
            void addAxis(Orientation_Axes orientationAxes, Axis axis);

            ~Shoulder() override;

        };

    } // Body
} // Parts

#endif //ARBIE_SHOULDER_H
