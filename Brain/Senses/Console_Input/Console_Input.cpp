//
// Created by thome on 12/8/2023.
//

#include "Console_Input.h"

namespace Brain {
    namespace Senses {
        Console_Input::Console_Input() {
            this->setConsoleInputComplete(false);
        }

        Console_Input::~Console_Input() {

        }

        void Console_Input::Start() {

            while(!this->isConsoleInputComplete()) {
                cout << "Enter an axis:" << endl;
                cin >> axis;
                cout << "Enter a degree:" << endl;
                cin >> deg;

                this->setAxis(axis);
                this->setDeg(deg);

                if (axis > 5) {this->setConsoleInputComplete(true);}
            }
        }

        int Console_Input::getAxis() const {
            return axis;
        }

        void Console_Input::setAxis(int axis) {
            Console_Input::axis = axis;
        }

        int Console_Input::getDeg() const {
            return deg;
        }

        void Console_Input::setDeg(int deg) {
            Console_Input::deg = deg;
        }

        bool Console_Input::isConsoleInputComplete() const {
            return consoleInputComplete;
        }

        void Console_Input::setConsoleInputComplete(bool consoleInputComplete) {
            Console_Input::consoleInputComplete = consoleInputComplete;
        }

    } // Brain
} // Senses