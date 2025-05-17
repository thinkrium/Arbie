//
// Created by thom on 5/10/25.
//

#include "Pipe.h"

#include <opencv2/imgproc.hpp>

namespace Arbie {
namespace Senses {
namespace Sight {
namespace Base {
namespace Processing {
namespace Tensorflow {
namespace Pipeline {


    void Pipe::preprocess_pipeline() {

        int input_index = this->get_interpreter()->inputs()[0];
        TfLiteIntArray* pipe_dims = this->get_interpreter()->tensor(input_index)->dims;
        this->get_ai_model().get_model_details().height = pipe_dims->data[1];
        this->get_ai_model().get_model_details().width = pipe_dims->data[2];
        this->get_ai_model().get_model_details().channels = pipe_dims->data[3];


    }

    void Pipe::process_pipeline() {
    }

    void Pipe::post_process_pipeline() {
    }

    Model Pipe::get_ai_model() const {
        return ai_model;
    }

    void Pipe::set_ai_model(const Model &ai_model) {
        this->ai_model = ai_model;
    }

    Pipe::Pipe(Pipe &&other) {
        this->interpreter = std::move(other.interpreter);
        this->ai_model = other.ai_model;
        this->number_of_detections = other.number_of_detections;
    }

    Pipe & Pipe::operator=(Pipe & other) {
        this->interpreter = std::move(other.interpreter);
        this->ai_model = other.ai_model;
        this->number_of_detections = other.number_of_detections;
        return *this;
    }

    Pipe::Pipe() {
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

    cv::Mat Pipe::resizeImage(cv::Mat input_frame, cv::Mat  resized_image) {
        cv::resize(input_frame, resized_image, cv::Size(
            this->get_ai_model().get_model_details().width,
            this->get_ai_model().get_model_details().height)
            );
        return  resized_image;
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