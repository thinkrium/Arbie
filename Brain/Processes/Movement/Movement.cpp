//
// Created by thome on 12/1/2023.
//

#include "Movement.h"

namespace Brain {
    namespace Processes {


        const Whole_Body &Movement::getWholeBody() const {
            return whole_body;
        }

        void Movement::Start() {
            try {

                Shoulder rightShoulder = this->whole_body.getArmBySideOfBody(Side_Of_Body::right).getShoulder();

                rightShoulder.getAxis(Relative_Axes::x).turnMotor(Rotation_Direction::Clockwise, 30);

                Logger::Success("Brain::Activity", "Run", Error_Messaging::No_Error);
            }
            catch (exception e) {
                Logger::Success("Brain::Activity", "Run", Error_Messaging::Generic_Error);

            }

        }

        Movement::~Movement() {

        }

        Movement::Movement() {}

        void Movement::moveBodyPartBySide(Body_Part bodyPart, Side_Of_Body sideOfBody,
                                          map<Relative_Axes, int> degreesByAxis) {

            switch (bodyPart) {
                case Body_Part::shoulder :

                    break;
                case Body_Part::elbow :

                    break;
                case Body_Part::wrist :

                    break;
                default:
                    Logger::Error("Movement", "moveBodyPartBySide", Error_Messaging::Generic_Error);

            }
        }

        void Movement::moveShoulderBySide(Side_Of_Body sideOfBody, map<Relative_Axes, int> degreesByAxis) {


        }

        void Movement::moveWristBySide(Side_Of_Body sideOfBody, map<Relative_Axes, int> degreesByAxis) {

        }

        void Movement::moveElbowBySide(Side_Of_Body sideOfBody, map<Relative_Axes, int> degreesByAxis) {

        }

    } // Brain
} // Processes