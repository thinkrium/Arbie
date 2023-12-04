//
// Created by thome on 12/1/2023.
//

#ifndef ARBIE_WHOLE_BODY_H
#define ARBIE_WHOLE_BODY_H

#include "../../Body/Parts/Arm/Arm.h"
#include "../../Body/Parts/Leg/Leg.h"
#include "map"
#include "../../Utilities/Logger/Logger.h"
#include "../../Utilities/Enumerations.h"
#include "../../Utilities/Error_Messaging.h"


using namespace Utilities;
using namespace Utilities::Enumerations;
using namespace Body::Parts;
using namespace std;

namespace Body {

    class Whole_Body {

    private:

        map<Side_Of_Body, Arm> arms;
        // TODO : This line causes an error ??? why ???
        map<Side_Of_Body, Leg> legs;

    public:
        Whole_Body();

        Arm getArmBySideOfBody(Side_Of_Body sideOfBody);

        Leg getLegBySideOfBody(Side_Of_Body sideOfBody);

        const map<Side_Of_Body, Arm> &getArms() const;

        void setArms(const map<Side_Of_Body, Arm> &arms);

        const map<Side_Of_Body, Leg> &getLegs() const;

        void setLegs(const map<Side_Of_Body, Leg> &legs);

        virtual ~Whole_Body();

    };

} // Body

#endif //ARBIE_WHOLE_BODY_H
