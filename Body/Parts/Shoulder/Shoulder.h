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

            /**
             * This defines the relative to the torso axis for Arbie
             */
            map<Relative_Axes, Axis> axes;

        public:

            Shoulder();

            /**
             * Constructor sets the relative axes
             * @param axes
             */
            explicit Shoulder(const map<Relative_Axes, Axis> &axes);

            /**
             * Get a specific relative axis
             * @param orientationAxis  (found in Enumerations.h )
             * @return Axis object for which to manipulate
             */
            Axis getAxis(Relative_Axes orientationAxis);

            /**
             * Gets all the relative axis
             * @return a map of Axis objects with relative axis keys (found in Enumerations.h )
             *
             */
            map<Relative_Axes, Axis> getAxes();

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
            ~Shoulder() override;

        };

    } // Body
} // Parts

#endif //ARBIE_SHOULDER_H
