//
// Created by thom on 5/10/25.
//

#include "Pipe.h"

namespace Arbe {
namespace Senses {
namespace Sight {
namespace Base {
namespace Processing {
namespace Tensorflow {
namespace Pipeline {

    const char * Pipe::get_model_path() const {
        return model_path;
    }

    void Pipe::set_model_path(const char *model_path) {
        this->model_path = model_path;
    }

    void Pipe::PreparePipeLine() {


        const char* landmark_model_path = "../face_landmark_small.tflite";

        // Load TFLite model
        auto landmark_model = tflite::FlatBufferModel::BuildFromFile(landmark_model_path);
        tflite::ops::builtin::BuiltinOpResolver landmark_resolver;
        std::unique_ptr<tflite::Interpreter> landmark_interpreter;

        tflite::InterpreterBuilder(*landmark_model, landmark_resolver)(&landmark_interpreter);
        landmark_interpreter->AllocateTensors();

    }


} // Pipeline
} // Tensorflow
} // Processing
} // Base
} // Sight
} // Senses
} // Arbe