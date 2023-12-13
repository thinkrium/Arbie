//
// Created by thome on 11/30/2023.
//

#ifndef ARBIE_ARM_H
#define ARBIE_ARM_H

#include "../Base/Base_Body_Part.h"
#include "../../../Body/Parts/Shoulder/Shoulder.h"
#include "../../../Body/Parts/Elbow/Elbow.h"
#include "../../../Body/Parts/Wrist/Wrist.h"
#include "../../../Utilities/Logger/Logger.h"
#include "../../../Utilities/Error_Messaging.h"
#include "../../../Utilities/Enumerations.h"
#include "../../../Utilities/Pinouts/Arm_Pinout/Arm_Pinout.h"
#include "../../Parts/Shoulder/Shoulder.h"
#include "../../Parts/Elbow/Elbow.h"
#include "../../Parts/Wrist/Wrist.h"
#include "../../Parts/Bones/Bone.h"

#include "map"

using namespace Utilities::Pinouts;
using namespace std;
using namespace Utilities::Enumerations;
using namespace Utilities;
using namespace Body::Parts::Joints;
using namespace Body::Parts::Bones;

namespace Body {
    namespace Parts {

        class Arm : public Base_Body_Part {


        private:

            Arm_Pinout armPinout;

            Shoulder shoulder;
            Elbow elbow;
            Wrist wrist;
            Bone upper_arm_bone;
            Bone fore_arm_bone;

        public:
            Arm();


            /**
             * calls the constructor for the shoulder, elbow and writs using
             * using the arm pinout constructor for each
             * @param armPinout
             */
            Arm(Arm_Pinout armPinout);

            const Bone &getUpperArmBone() const;

            void setUpperArmBone(const Bone &upperArmBone);

            const Bone &getForeArmBone() const;

            void setForeArmBone(const Bone &foreArmBone);

            ~Arm() override;

            const Shoulder &getShoulder() const;

            void setShoulder(const Shoulder &shoulder);

            const Elbow &getElbow() const;

            void setElbow(const Elbow &elbow);

            const Wrist &getWrist() const;

            void setWrist(const Wrist &wrist);

            const Arm_Pinout &getArmPinout() const;

            void setArmPinout(const Arm_Pinout &armPinout);


        };

    } // Body
} // Parts

#endif //ARBIE_ARM_H
