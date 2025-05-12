//
// Created by thom on 5/10/25.
//

#include "Pipe.h"

namespace Arbie {
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

    void Pipe::preprocess_pipeline() {
        ;
    }

    int Pipe::get_number_of_detections() const {
        return number_of_detections;
    }

    void Pipe::set_number_of_detections(int number_of_detections) {
        this->number_of_detections = number_of_detections;
    }

    void Pipe::PreparePipeLineInterpreter() {


        // const char* landmark_model_path = "../face_landmark_small.tflite";

        // Load TFLite model
        auto model = tflite::FlatBufferModel::BuildFromFile(this->get_model_path());
        tflite::ops::builtin::BuiltinOpResolver resolver;
        std::unique_ptr<tflite::Interpreter> interpreter;

        tflite::InterpreterBuilder(*model, resolver)(&interpreter);
        interpreter->AllocateTensors();

        this->set_interpreter(interpreter);
    }

    std::unique_ptr<tflite::Interpreter>& Pipe::get_interpreter() {
        return interpreter;
    }

    void Pipe::set_interpreter(std::unique_ptr<tflite::Interpreter> & interpreter) {
        this->interpreter = std::move(interpreter);
    }

    float * Pipe::get_input_tensor_data(int input_tensor_index){
        return this->get_interpreter()->input_tensor(input_tensor_index)->data.f;

    };

    float * Pipe::get_output_tensor_data(int output_tensor_index){
        return this->get_interpreter()->input_tensor(output_tensor_index)->data.f;

    };
} // Pipeline
} // Tensorflow
} // Processing
} // Base
} // Sight
} // Senses
} // Arbe