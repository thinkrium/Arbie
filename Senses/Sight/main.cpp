//
// Created by thom on 5/9/25.
//

#include "../Base/Processing/Tensorflow/Pipeline/Pipe.h"
using namespace Arbie::Senses::Sight::Base::Processing::Tensorflow;
int main( ) {

    Pipeline::Pipe face_detection_pipe("../../Sight/Assets/TFliteModel/face_detection_short_range.tflite");
    face_detection_pipe.PreparePipeLineInterpreter();


    return 0;
}
