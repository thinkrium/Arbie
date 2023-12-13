//
// Created by thome on 11/30/2023.
//

#ifndef ARBIE_ELBOW_H
#define ARBIE_ELBOW_H

#include "../Joints/Arm_Joint/Arm_Joint.h"

#include "../../../Utilities/Pinouts/Arm_Pinout/Arm_Pinout.h"

using namespace Utilities::Pinouts;

namespace Body {
    namespace Parts {
        namespace Joints {
            class Elbow : public Arm_Joint {
            public:
                Elbow();

                /**
                 * Creates a motor profile and an axis and assigns the axis to the elbow
                 * @param armPinout
                 */
                Elbow(Arm_Pinout armPinout);

                ~Elbow() override;

                void rotate(
                        Joint_Turning_Instructions singleAxisJointTurningInstructions
                );

                void setAxisMotor() ;

            };
        }
    }
}


#endif //ARBIE_ELBOW_H
