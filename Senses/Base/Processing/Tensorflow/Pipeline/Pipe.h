//
// Created by thom on 5/10/25.
//
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


    Pipe();

    Pipe(char * model_path_parameter)  ;

    [[nodiscard]] int get_number_of_detections() const;

    void set_number_of_detections(int number_of_detections);

    void PreparePipeLineInterpreter();

    std::unique_ptr<tflite::Interpreter>& get_interpreter();

    void set_interpreter(std::unique_ptr<tflite::Interpreter> & interpreter);

    float * get_input_tensor_data(int input_tensor_index);

    float * get_output_tensor_data(int output_tensor_index);

    TfLiteTensor * get_input_tensor(int input_tensor_index);

    TfLiteTensor * get_output_tensor(int output_tensor_index);

    Model get_ai_model() const;

    void set_ai_model(const Model &ai_model);

    void preprocess_pipeline();

    void process_pipeline();

    void post_process_pipeline();

    ~Pipe() = default;

private:

    std::unique_ptr<tflite::Interpreter> interpreter;

    Model ai_model;


    int number_of_detections;

public:
};

} // Pipeline
} // Tensorflow
} // Processing
} // Base
} // Sight
} // Senses
} // Arbe

#endif //PIPE_H
