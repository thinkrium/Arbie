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


    void Pipe::preprocess_pipeline() {
        ;
    }

    Model Pipe::get_ai_model() const {
        return ai_model;
    }

    void Pipe::set_ai_model(const Model &ai_model) {
        this->ai_model = ai_model;
    }

    Pipe::Pipe(char *model_path_parameter) {
        Model ai_model;
        ai_model.set_model_path(model_path_parameter);
        this->set_ai_model(ai_model);
    }

    int Pipe::get_number_of_detections() const {
        return number_of_detections;
    }

    void Pipe::set_number_of_detections(int number_of_detections) {
        this->number_of_detections = number_of_detections;
    }

    void Pipe::PreparePipeLineInterpreter() {


        if (this->get_ai_model().get_model_path() == "") { exit(7); }
        // const char* landmark_model_path = "../face_landmark_small.tflite";

        // Load TFLite model
        auto model = tflite::FlatBufferModel::BuildFromFile(this->get_ai_model().get_model_path());
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

    TfLiteTensor * Pipe::get_input_tensor(int input_tensor_index){
        return this->get_interpreter()->input_tensor(input_tensor_index);

    };

    TfLiteTensor * Pipe::get_output_tensor(int output_tensor_index){
        return this->get_interpreter()->input_tensor(output_tensor_index);

    };



} // Pipeline
} // Tensorflow
} // Processing
} // Base
} // Sight
} // Senses
} // Arbe