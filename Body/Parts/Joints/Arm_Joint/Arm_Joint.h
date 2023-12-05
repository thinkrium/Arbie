//
// Created by thome on 12/4/2023.
//

#ifndef ARBIE_ARM_JOINT_H
#define ARBIE_ARM_JOINT_H

#include "../Base_Joint/Base_Joint.h"
#include "../../../../Utilities/Pinouts/Arm_Pinout/Arm_Pinout.h"
#include "../../../../Utilities/Logger/Logger.h"
#include "../../../../Utilities/Error_Messaging.h"

using namespace Utilities;
using namespace Utilities::Pinouts;

namespace Body {
    namespace Parts {
        namespace Joints {


            class Arm_Joint : public Base_Joint {

             public:
                Arm_Joint();

                ~Arm_Joint() override;

                const Arm_Pinout &getArmPinout() const;

                void setArmPinout(const Arm_Pinout &armPinout);

                virtual void setAxisMotor() = 0;
            private:
                Arm_Pinout armPinout;

            };

        } // Body
    } // Parts
} // Joints

#endif //ARBIE_ARM_JOINT_H
