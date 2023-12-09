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
        public:
            Console_Input();

            ~Console_Input() override;

            void Start() override;
        private:
            int axis;
            int deg;
        public:
            int getAxis() const;

            void setAxis(int axis);

            int getDeg() const;

            void setDeg(int deg);

        };

    } // Brain
} // Senses

#endif //ARBIE_CONSOLE_INPUT_H
