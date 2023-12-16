//
// Created by thome on 12/1/2023.
//

#ifndef ARBIE_MOVEMENT_H
#define ARBIE_MOVEMENT_H


#include "../../../Body/Whole_Body/Whole_Body.h"
#include "../Base/Base_Process.h"

#include "../../../Brain/Senses/Console_Input/Console_Input.h"
#include "../../../Utilities/Error_Messaging.h"
#include "../../../Body/Parts/Shoulder/Shoulder.h"
#include "../../../Utilities/Logger/Logger.h"
#include "../../../Body/Axes/Axis.h"

using namespace Brain::Senses;
using namespace Utilities::Enumerations;
using namespace Utilities;
using namespace Body::Parts;
using namespace Body::Axes;

using namespace Body;
using namespace Utilities::Enumerations;
using namespace Utilities;

namespace Brain {
    namespace Processes {

        class Movement : public Base_Process {

        private:
            Brain::Senses::Console_Input &consoleInput;
        public:
            const map<Utilities::Enumerations::Processes, Base_Process> &getInputProcessMap() const;

            // TODO: set this argument to a map it should not be so tightly coupled
            void setInputProcessMap(Brain::Senses::Console_Input &consoleInput);

            const Brain::Senses::Console_Input &getConsoleInput() const;

            void setConsoleInput(const Brain::Senses::Console_Input &consoleInput);

        private:
            Whole_Body whole_body;
        public:
            Movement(Senses::Console_Input & consoleInput);

            const Whole_Body &getWholeBody() const;

            void Start() override;

            void moveBodyPartBySide(Body_Part bodyPart, Side_Of_Body sideOfBody, map<Relative_Axes, int> degreesByAxis);

            void moveShoulderBySide(Side_Of_Body sideOfBody, map<Relative_Axes, int> degreesByAxis);

            void moveWristBySide(Side_Of_Body sideOfBody, map<Relative_Axes, int> degreesByAxis);

            void moveElbowBySide(Side_Of_Body sideOfBody, map<Relative_Axes, int> degreesByAxis);

            ~Movement() override;

        };

    } // Brain
} // Processes

#endif //ARBIE_MOVEMENT_H
