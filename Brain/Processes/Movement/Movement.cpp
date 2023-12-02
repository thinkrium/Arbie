//
// Created by thome on 12/1/2023.
//

#include "Movement.h"

namespace Brain {
    namespace Processes {


        const Whole_Body &Movement::getWholeBody() const {
            return whole_body;
        }

        void Movement::setWholeBody(const Whole_Body &wholeBody) {
            whole_body = wholeBody;
        }

        void Movement::Start() {

        }

        Movement::~Movement() {

        }

        Movement::Movement() {}
    } // Brain
} // Processes