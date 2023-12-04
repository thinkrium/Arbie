//
// Created by thome on 12/4/2023.
//

#ifndef ARBIE_BASE_JOINT_H
#define ARBIE_BASE_JOINT_H

#include "../../Base/Base_Body_Part.h"

#include "map"
#include "../../../Axes/Axis.h"

using namespace Body::Axes;

namespace Body {
    namespace Parts {
        namespace Joints {

            class Base_Joint : public Base_Body_Part {

            private:
                /**
                 * This defines the relative to the torso axis for Arbie
                 */
                map<Relative_Axes, Axis> axes;

            public:
                Base_Joint();

                /**
                 * Get a specific relative axis
                 * @param orientationAxis  (found in Enumerations.h )
                 * @return Axis object for which to manipulate
                 */
                Axis getAxis(Relative_Axes orientationAxis);

                explicit Base_Joint(const map <Relative_Axes, Axis> &axes);

                /**
                 * Gets all the relative axis
                 * @return a map of Axis objects with relative axis keys (found in Enumerations.h )
                 *
                 */
                map<Relative_Axes, Axis> getAxes();

                ~Base_Joint() override;

                /**
                 * Sets all the Axis object as a map of Axis with the key of relative axis ( found in Enumerations.h )
                 * @param axes
                 */
                void setAxes(map<Relative_Axes, Axis> axes);

                /**
                 * Adds an axis to the map of axis by the relative axis ( (found in Enumerations.h )
                 * @param orientationAxis
                 * @param axis
                 */
                void addAxis(Relative_Axes orientationAxis, Axis axis);

                /**
                 * Turns an axis on the specified relative orientation  (found in Enumerations.h )
                 * In the specified rotation direction  (found in Enumerations.h )
                 * By the specified degrees
                 *
                 * @param orientationAxis
                 * @param direction
                 * @param degrees
                 */
                void turnOnAxis(Relative_Axes orientationAxis, Rotation_Direction direction, int degrees);
            };

        } // Body
    } // Parts
} // Joints

#endif //ARBIE_BASE_JOINT_H
