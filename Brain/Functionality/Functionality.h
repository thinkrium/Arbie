//
// Created by thome on 11/30/2023.
//

#ifndef ARBIE_FUNCTIONALITY_H
#define ARBIE_FUNCTIONALITY_H

#include "../../Utilities/Error_Messaging.h"
#include "../../Body/Parts/Shoulder/Shoulder.h"
#include "../../Utilities/Logger/Logger.h"
#include "../../Body/Axes/Axis.h"

using namespace Utilities::Enumerations;
using namespace Utilities;
using namespace Body::Parts;
using namespace Body::Axes;

namespace Brain {
    namespace Functionality {

        class Functionality {
        public:
            static void Run();
        };

    } // Brain
} // Functionality

#endif //ARBIE_FUNCTIONALITY_H
