//
// Created by thome on 12/1/2023.
//

#ifndef ARBIE_MOVEMENT_H
#define ARBIE_MOVEMENT_H


#include "../../../Body/Whole_Body/Whole_Body.h"
#include "../Base/Base_Process.h"

#include "../../../Utilities/Error_Messaging.h"
#include "../../../Body/Parts/Shoulder/Shoulder.h"
#include "../../../Utilities/Logger/Logger.h"
#include "../../../Body/Axes/Axis.h"


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
            Whole_Body whole_body;
        public:
            Movement();

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
