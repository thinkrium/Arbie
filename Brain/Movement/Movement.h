//
// Created by thome on 12/1/2023.
//

#ifndef ARBIE_MOVEMENT_H
#define ARBIE_MOVEMENT_H

#include "../../Body/Whole_Body/Whole_Body.h"
#include "../../Utilities/Enumerations.h"
#include "../../Utilities/Error_Messaging.h"

using namespace Utilities::Enumerations;
using namespace Utilities;
using namespace Body;

namespace Brain {

    class Movement {

        Whole_Body whole_body;

        void moveWholeBody();

        void moveArm(Body_Side sideOfBody);



    };

} // Brain

#endif //ARBIE_MOVEMENT_H
