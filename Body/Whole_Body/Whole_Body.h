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

        map<Side_Of_Body, Arm> arms;
        // TODO : This line causes an error ??? why ???
        map<Side_Of_Body, Leg> legs;
    public:
        const map<Side_Of_Body, Arm> &getArms() const;

        void setArms(const map<Side_Of_Body, Arm> &arms);

        const map<Side_Of_Body, Leg> &getLegs() const;

        void setLegs(const map<Side_Of_Body, Leg> &legs);

    };

} // Body

#endif //ARBIE_WHOLE_BODY_H
