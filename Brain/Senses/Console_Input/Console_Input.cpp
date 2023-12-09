//
// Created by thome on 12/8/2023.
//

#include "Console_Input.h"

namespace Brain {
    namespace Senses {
        Console_Input::Console_Input() {}

        Console_Input::~Console_Input() {

        }

        void Console_Input::Start() {

            cout << "Enter an axis:" << endl;
             cin >> axis;
            cout << "Enter a degree:" << endl;
             cin >> deg;

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

    } // Brain
} // Senses