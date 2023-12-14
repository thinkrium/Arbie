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

                bool shouldMove = true;

                Shoulder rightShoulder = this->whole_body.getArmBySideOfBody(Side_Of_Body::right).getShoulder();

                int degrees = NULL;
                int axis = NULL;

                while (!this->getConsoleInput().isConsoleInputComplete()) {
                    if(axis == NULL || axis != this->getConsoleInput().getAxis()) {

                        if (degrees == NULL || degrees != this->getConsoleInput().getDeg()) {
                            degrees = this->getConsoleInput().getDeg();
                            rightShoulder.getAxis(Relative_Axes::x).turnMotor(Rotation_Direction::Clockwise, 30);
                        }
                    }


                }
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

        const Brain::Senses::Console_Input &Movement::getConsoleInput() const {
            return consoleInput;
        }

        void Movement::setConsoleInput(const Brain::Senses::Console_Input &consoleInput) {
            Movement::consoleInput = consoleInput;
        }

        void Movement::setInputProcessMap(Brain::Senses::Console_Input consoleInput) {
             this->setConsoleInput(consoleInput);
        }

    } // Brain
} // Processes