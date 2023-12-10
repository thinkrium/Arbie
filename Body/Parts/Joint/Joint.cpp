//
// Created by thome on 11/29/2023.
//

#include "Joint.h"
#include "../../../Utilities/Logger/Logger.h"
#include "../../../Utilities/Error_Messaging.h"
#include "../../../Utilities/Enumerations.h"

using namespace Utilities;
using namespace Utilities::Enumerations;


namespace Body {
    namespace Parts {
        Joint::Joint() {}


        Axis Joint::getAxis(Relative_Axes orientationAxis) {

            try {
                return this->axes[orientationAxis];
            }
            catch (exception e) {
                Logger::Error("Joint", "getAxis", Error_Messaging::Generic_Error);
            }

            // TODO: How to fix this it should return something but the try prevents it
            //       but i want the try;
        }

        void Joint::setAxes(map<Relative_Axes, Axis> axes) {
            this->axes = axes;
        }

        void Joint::addAxis(Relative_Axes orientationAxis, Axis axis) {
             try {
                this->axes.insert({orientationAxis, axis});
            }
            catch (exception e) {
                Logger::Error("Joint", "getAxis", Error_Messaging::Generic_Error);
            }
    }

        map<Relative_Axes, Axis> Joint::getAxes() {
            return this->axes;
        }


        void Joint::turnOnAxis(Relative_Axes orientationAxis, Rotation_Direction direction, int degrees) {
            try {

                this->axes[orientationAxis].turnMotor(direction, degrees);

            }
            catch (exception e) {
                Logger::Error("Joint", "getAxis", Error_Messaging::Generic_Error);
            }
        }

        Joint::Joint(const map<Relative_Axes, Axis> &axes) : axes(axes) {
            this->setAxes(axes);
        }

        Joint::~Joint() {

        }
    } // Body
} // Parts