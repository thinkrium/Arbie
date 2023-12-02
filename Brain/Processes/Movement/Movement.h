//
// Created by thome on 12/1/2023.
//

#ifndef ARBIE_MOVEMENT_H
#define ARBIE_MOVEMENT_H


#include "../../../Body/Whole_Body/Whole_Body.h"
#include "../Base/Base_Process.h"


using namespace Body;

namespace Brain {
    namespace Processes {

        class Movement : public Base_Process {

        private:
            Whole_Body whole_body;
        public:
            Movement();

            const Whole_Body &getWholeBody() const;

            void setWholeBody(const Whole_Body &wholeBody);


            void Start() override;

            ~Movement() override;

        };

    } // Brain
} // Processes

#endif //ARBIE_MOVEMENT_H
