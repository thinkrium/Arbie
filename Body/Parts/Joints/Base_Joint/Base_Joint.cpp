//
// Created by thome on 12/4/2023.
//

#include "Base_Joint.h"

#include "../../../../Utilities/Logger/Logger.h"
#include "../../../../Utilities/Error_Messaging.h"
#include "../../../../Utilities/Enumerations.h"

using namespace Utilities;
using namespace Utilities::Enumerations;



namespace Body {
    namespace Parts {
        namespace Joints {
            Base_Joint::Base_Joint() {}


            Axis Base_Joint::getAxis(Relative_Axes orientationAxis) {

                try {
                    return this->axes[orientationAxis];
                }
                catch (exception e) {
                    Logger::Error("Joint", "getAxis", Error_Messaging::Generic_Error);
                }

                // TODO: How to fix this it should return something but the try prevents it
                //       but i want the try;
            }

            void Base_Joint::setAxes(map<Relative_Axes, Axis> axes) {
                this->axes = axes;
            }

            void Base_Joint::addAxis(Relative_Axes orientationAxis, Axis axis) {
                try {
                    this->axes.insert({orientationAxis, axis});
                }
                catch (exception e) {
                    Logger::Error("Joint", "getAxis", Error_Messaging::Generic_Error);
                }
            }

            map<Relative_Axes, Axis> Base_Joint::getAxes() {
                return map<Relative_Axes, Axis>();
            }


            void Base_Joint::turnOnAxis(Relative_Axes orientationAxis, Rotation_Direction direction, int degrees) {
                try {

                    this->axes[orientationAxis].turnMotor(direction, degrees);

                }
                catch (exception e) {
                    Logger::Error("Joint", "getAxis", Error_Messaging::Generic_Error);
                }
            }

            Base_Joint::Base_Joint(const map<Relative_Axes, Axis> &axes) : axes(axes) {
                this->setAxes(axes);
            }

            Base_Joint::~Base_Joint() {

            }
        } // Body
    } // Parts
} // Joints