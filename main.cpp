#include "Utilities/Error_Messaging.h"
#include "Body/Parts/Shoulder/Shoulder.h"
#include "Utilities/Logger/Logger.h"
#include "Body/Axes/Axis.h"

using namespace Utilities::Enumerations;
using namespace Utilities;
using namespace Body::Parts;
using namespace Body::Axes;


int main() {

 Servo_Motor_Profile profile;

    Servo_Motor
        pitchServoMotor(0,0, profile ),
        yawServoMotor(1, 0,profile ),
        rollServoMotor(2, 0,profile ) ;

    Axis xAxis(pitchServoMotor),
         yAxis(yawServoMotor),
         zAxis(rollServoMotor);

    map<Relative_Axes, Axis> axes = {
            {Relative_Axes::x, xAxis},
            {Relative_Axes::y, yAxis  },
            {Relative_Axes::z, zAxis }
    };

    Shoulder shoulder(
                  axes
            );

    shoulder.turnOnAxis(Relative_Axes::x, Rotation_Direction::Counter_Clockwise, 30);
    shoulder.turnOnAxis(Relative_Axes::y, Rotation_Direction::Counter_Clockwise, 30);
    shoulder.turnOnAxis(Relative_Axes::z, Rotation_Direction::Counter_Clockwise, 30);

    Logger::Success(Error_Messaging::No_Error);

    return 0;
}
