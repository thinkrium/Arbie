//
// Created by thom on 5/10/25.
//
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


    Pipe() = default;

    void PreparePipeLineInterpreter();

    std::unique_ptr<tflite::Interpreter>& get_interpreter();

    void set_interpreter(std::unique_ptr<tflite::Interpreter> & interpreter);

    float * get_input_tensor_data(int input_tensor_index);

    float * get_output_tensor_data(int output_tensor_index);

    TfLiteTensor * get_input_tensor(int input_tensor_index);

    TfLiteTensor * get_output_tensor(int output_tensor_index);

    [[nodiscard]] const char * get_model_path() const;

    void set_model_path(const char *model_path);

    void preprocess_pipeline();

    ~Pipe() = default;

private:

    std::unique_ptr<tflite::Interpreter> interpreter;


    const char* model_path;

    int number_of_detections;

public:
    [[nodiscard]] int get_number_of_detections() const;

    void set_number_of_detections(int number_of_detections);
};

} // Pipeline
} // Tensorflow
} // Processing
} // Base
} // Sight
} // Senses
} // Arbe

#endif //PIPE_H
