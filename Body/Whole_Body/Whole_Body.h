//
// Created by thome on 12/1/2023.
//

#ifndef ARBIE_WHOLE_BODY_H
#define ARBIE_WHOLE_BODY_H

#include "../../Body/Parts/Arm/Arm.h"
#include "../../Body/Parts/Leg/Leg.h"
#include "map"

using namespace Body::Parts;
using namespace std;

namespace Body {

    class Whole_Body {

        map<Body_Side, Arm> arms;
        map<Body_Side, Leg> legs;

    };

} // Body

#endif //ARBIE_WHOLE_BODY_H
