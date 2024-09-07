//
// Created by thom on 9/3/24.
//

#ifndef STEPPERMOTOR_H
#define STEPPERMOTOR_H
#include "../Base/BaseMotor.h"

namespace Arbie {
namespace Body {
namespace Movement {
namespace Motors {

class StepperMotor : public BaseMotor {
public:


    StepperMotor(int motor_id);

    ~StepperMotor() = default;



    StepperMotor() = default;
};

} // Motors
} // Movement
} // Body
} // Arbie

#endif //STEPPERMOTOR_H
