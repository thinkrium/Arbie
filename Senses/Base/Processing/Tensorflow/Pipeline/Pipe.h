//
// Created by thom on 5/10/25.
//
#include <opencv2/core/mat.hpp>

#include "Model.h"
#include "tensorflow/lite/interpreter.h"
#include "tensorflow/lite/kernels/register.h"
#include "tensorflow/lite/model.h"

#ifndef PIPE_H
#define PIPE_H

namespace Arbie {
namespace Senses {
namespace Sight {
namespace Base {
namespace Processing {
namespace Tensorflow {
namespace Pipeline {

class Pipe {

public:

    Pipe(Pipe && other);

    Pipe & operator=(Pipe & other);

    Pipe();

    Pipe(char * model_path_parameter)  ;

    [[nodiscard]] int get_number_of_detections() const;

    void set_number_of_detections(int number_of_detections);

    void PreparePipeLineInterpreter();

    cv::Mat resizeImage(cv::Mat input_frame, cv::Mat  resized_image);

    std::unique_ptr<tflite::Interpreter>& get_interpreter();

    void set_interpreter(std::unique_ptr<tflite::Interpreter> & interpreter);

    float * get_input_tensor_data(int input_tensor_index);

    float * get_output_tensor_data(int output_tensor_index);

    TfLiteTensor * get_input_tensor(int input_tensor_index);

    TfLiteTensor * get_output_tensor(int output_tensor_index);

    cv::Mat & get_float_image();

    void set_float_image(cv::Mat float_image);


    Model & get_ai_model()  ;

    void set_ai_model(  Model & ai_model);

    void preprocess_pipeline();

    void initialize_pipeline();

    void process_pipeline();

    void post_process_pipeline();

    ~Pipe() = default;

private:

    std::unique_ptr<tflite::Interpreter> interpreter;

    Model ai_model;

    cv::Mat float_image;


    int number_of_detections;



};

} // Pipeline
} // Tensorflow
} // Processing
} // Base
} // Sight
} // Senses
} // Arbe

#endif //PIPE_H
