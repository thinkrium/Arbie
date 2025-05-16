//
// Created by thom on 5/16/25.
//

#include "SenseOfSight.h"

namespace Arbie {
namespace Senses {
    std::vector<Pipeline::Pipe> SenseOfSight::get_pipes()  {
        return pipes;
    }

    void SenseOfSight::set_pipes(std::vector<Pipeline::Pipe> pipes) {
        this->pipes = pipes;
    }

    SenseOfSight::SenseOfSight() {
        Pipeline::Pipe face_detection_pipe("../../Sight/Assets/TFliteModel/face_detection_short_range.tflite");
        face_detection_pipe.PreparePipeLineInterpreter();

         // this->set_pipes({face_detection_pipe});
    }
} // Senses
} // Arbie