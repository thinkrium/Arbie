#include <iostream>


#include "Movement/Motors/Base/BaseMotor.h"
#include "Movement/Motors/Stepper/StepperMotor.h"
#include "NervousSystem/NervousSystem.h"
#include "../Shared/MovementProfiles.h"

using namespace Arbie::Body;
using namespace Movement::Motors;
using namespace Shared::Profiles;

int main() {
    // float a = MovementProfiles::ForwardMovement.move.at( MovementProfiles::MovementStages::stage1)
    //         .relative_joint_movement.at(BodyPart.LeftKnee);

    StepperMotor stepper_motor;
    stepper_motor.set_motor_id(0x001);
     stepper_motor.initiate_controller_connection();
//    for (int i = 0 ; i < 5; i++) {
     // std::cout << "switch: " << i << endl;
     stepper_motor.send_controller_instructions(11,11, 11);
      // sleep(2);
     // }
    stepper_motor.close_controller_connection();
    std::cout << "done " << endl;
    // NervousSystem nervous_system;
    return 0;
}
