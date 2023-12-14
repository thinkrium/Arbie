//
// Created by thome on 12/8/2023.
//

#ifndef ARBIE_CONSOLE_INPUT_H
#define ARBIE_CONSOLE_INPUT_H

#include "../../../Brain/Processes/Base/Base_Process.h"
#include "iostream"

using namespace std;
using namespace Brain::Processes;


namespace Brain {
    namespace Senses {

        class Console_Input : public Base_Process {
        private:
            int axis;
            int deg;
            bool consoleInputComplete;

        public:
            int getAxis() const;

            void setAxis(int axis);

            int getDeg() const;

            void setDeg(int deg);

            bool isConsoleInputComplete() const;

            void setConsoleInputComplete(bool consoleInputComplete);

            Console_Input();

            ~Console_Input() override;

            void Start() override;

        };

    } // Brain
} // Senses

#endif //ARBIE_CONSOLE_INPUT_H
