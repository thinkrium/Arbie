//
// Created by thom on 5/16/25.
//

#include "SenseOfSight.h"

namespace Arbie {
namespace Senses {
    SenseOfSight::SenseOfSight() {
        Pipeline::Pipe face_detection_pipe("../../Sight/Assets/TFliteModel/face_detection_short_range.tflite");
        face_detection_pipe.PreparePipeLineInterpreter();


    }
} // Senses
} // Arbie