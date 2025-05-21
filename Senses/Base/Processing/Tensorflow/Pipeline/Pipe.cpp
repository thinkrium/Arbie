//
// Created by thom on 5/10/25.
//

#include "Pipe.h"

#include <opencv2/imgproc.hpp>

#include "../../../../Sight/Processing/Tensorflow/Pipeline/Models/FaceDetection/FaceDetectionModel.h"

namespace Arbie {
namespace Senses {
namespace Sight {
namespace Base {
namespace Processing {
namespace Tensorflow {
namespace Pipeline {


    void Pipe::initialize_pipeline() {

        int input_index = this->get_interpreter()->inputs()[0];
        TfLiteIntArray* pipe_dims = this->get_interpreter()->tensor(input_index)->dims;

        this->get_ai_model()->set_interpreter( this->get_interpreter());
        this->get_ai_model()->get_model_details().height = pipe_dims->data[1];
        this->get_ai_model()->get_model_details().width = pipe_dims->data[2];
        this->get_ai_model()->get_model_details().channels = pipe_dims->data[3];


    }

    void Pipe::preprocess_pipeline() {
        // Copy to input tensor
        float* input_tensor_data = this->get_input_tensor_data(0);
        std::memcpy(
                         input_tensor_data,
                         this->get_float_image().data,
                        this->get_ai_model()->get_model_details().height
                              * this->get_ai_model()->get_model_details().width
                              * this->get_ai_model()->get_model_details().channels
                              * sizeof(float)
                    );

        // Run inference
        if (this->get_interpreter()->Invoke() != kTfLiteOk) {
            // std::cerr << "Failed to invoke\n";
            exit(11);
        }




    }

    void Pipe::process_pipeline(int loop_index) {
        this->get_ai_model()->Process(loop_index);
    }

    void Pipe::post_process_pipeline() {
        this->get_ai_model()->Preprocess();

    }

    cv::Mat & Pipe::get_float_image() {
        return float_image;
    }

    void Pipe::set_float_image(cv::Mat float_image) {
        this->float_image = std::move(float_image);
    }

    Model * Pipe::get_ai_model()   {
        return ai_model;
    }

    void Pipe::set_ai_model(  Model * ai_model) {
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
        this->set_ai_model(&ai_model);
    }

    int Pipe::get_number_of_detections() const {
        return number_of_detections;
    }

    void Pipe::set_number_of_detections(int number_of_detections) {
        this->number_of_detections = number_of_detections;
    }

    void Pipe::PreparePipeLineInterpreter() {


        if (this->get_ai_model()->get_model_path() == "") { exit(7); }
        // const char* landmark_model_path = "../face_landmark_small.tflite";

        // Load TFLite model
        auto model = tflite::FlatBufferModel::BuildFromFile(this->get_ai_model()->get_model_path());
        tflite::ops::builtin::BuiltinOpResolver resolver;
        std::unique_ptr<tflite::Interpreter> interpreter;

        tflite::InterpreterBuilder(*model, resolver)(&interpreter);
        this->set_interpreter( interpreter  );
        this->get_interpreter( )->AllocateTensors();

        // std::shared_ptr<tflite::Interpreter> shared_ptr(interpreter.get());

    }

    cv::Mat Pipe::resizeImage(cv::Mat input_frame, cv::Mat  resized_image) {
        cv::resize(input_frame, resized_image, cv::Size(
            this->get_ai_model()->get_model_details().width,
            this->get_ai_model()->get_model_details().height)
            );
        return  resized_image;
    }

    tflite::Interpreter * Pipe::get_interpreter() {
        return interpreter.get() ;
    }

    void Pipe::set_interpreter( std::unique_ptr < tflite::Interpreter > & interpreter) {
        this->interpreter = std::move(interpreter );
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