#include "Utilities/Error_Messaging.h"
#include "Body/Parts/Shoulder/Shoulder.h"
#include "Utilities/Logger/Logger.h"
#include "Body/Axes/Axis.h"

using namespace Utilities::Enumerations;
using namespace Utilities;
using namespace Body::Parts;
using namespace Body::Axes;


int main() {


    Servo_Motor
        pitchServoMotor(Servo_Motor_Profile),
        yawServoMotor( Servo_Motor_Profile),
        rollServoMotor(Servo_Motor_Profile) ;

    Axis pitchAxis(pitchServoMotor),
         yawAxis(yawServoMotor),
         rollAxis(rollServoMotor);

    map<Orientation_Axes, Axis> axes = {
            {Orientation_Axes::pitch,   pitchAxis},
            {Orientation_Axes::yaw,     yawAxis  },
            {Orientation_Axes::roll,    rollAxis }
    };

    Shoulder shoulder(
                  axes
            );

    Logger::Success(Error_Messaging::No_Error);

    return 0;
}
