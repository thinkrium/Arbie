//
// Created by thome on 11/30/2023.
//

#ifndef ARBIE_FUNCTIONALITY_H
#define ARBIE_FUNCTIONALITY_H

#include "../../Utilities/Error_Messaging.h"
#include "../../Body/Parts/Shoulder/Shoulder.h"
#include "../../Utilities/Logger/Logger.h"
#include "../../Body/Axes/Axis.h"

#include "../../Brain/CoreTechs/CoreTechs.h"

using namespace Brain::Processes;

using namespace Utilities::Enumerations;
using namespace Utilities;
using namespace Body::Parts;
using namespace Body::Axes;

namespace Brain {
    namespace Activity {

        class Activity  {

        private:

        public:
            static void Run();
        };

    } // Brain
} // Activity

#endif //ARBIE_FUNCTIONALITY_H
