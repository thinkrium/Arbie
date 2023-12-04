//
// Created by thome on 11/30/2023.
//

#ifndef ARBIE_ARM_H
#define ARBIE_ARM_H

#include "../Base/Base_Body_Part.h"
#include "../../../Body/Parts/Shoulder/Shoulder.h"
#include "../../../Body/Parts/Elbow/Elbow.h"
#include "../../../Body/Parts/Wrist/Wrist.h"

#include "../../../Utilities/Error_Messaging.h"
#include "../../../Utilities/Enumerations.h"
#include "../../../Utilities/Pinouts/Arm_Pinout/Arm_Pinout.h"
#include "../../Parts/Shoulder/Shoulder.h"
#include "../../Parts/Elbow/Elbow.h"
#include "../../Parts/Wrist/Wrist.h"

#include "map"

using namespace Utilities::Pinouts;
using namespace std;
using namespace Utilities::Enumerations;
using namespace Utilities;
using namespace Body::Parts::Joints;

namespace Body {
    namespace Parts {

        class Arm : public Base_Body_Part {

        private:
         public:
            Arm();

        private:
            map<Side_Of_Body, Shoulder> shoulders;

            map<Side_Of_Body, Elbow> elbows;

            map<Side_Of_Body, Wrist> wrists;

            Arm_Pinout armPinout;

        public:
            Arm(Arm_Pinout armPinout);

            ~Arm() override;

            Shoulder getShoulderBySideOfBody(Side_Of_Body sideOfBody);

            Elbow getElbowBySideOfBody(Side_Of_Body sideOfBody);

            Wrist getWristBySideOfBody(Side_Of_Body sideOfBody);

            void setShoulderBySideOfBody(Side_Of_Body sideOfBody, Shoulder shoulder);

            void setElbowBySideOfBody(Side_Of_Body sideOfBody, Elbow elbow);

            void setWristBySideOfBody(Side_Of_Body sideOfBody, Wrist wrist);

            const map<Side_Of_Body, Shoulder> &getShoulders() const;

            void setShoulders(const map<Side_Of_Body, Shoulder> &shoulders);

            const map<Side_Of_Body, Elbow> &getElbows() const;

            void setElbows(const map<Side_Of_Body, Elbow> &elbows);

            const map<Side_Of_Body, Wrist> &getWrists() const;

            void setWrists(const map<Side_Of_Body, Wrist> &wrists);
        };

    } // Body
} // Parts

#endif //ARBIE_ARM_H
