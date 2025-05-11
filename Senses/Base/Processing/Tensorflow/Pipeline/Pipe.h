//
// Created by thom on 5/10/25.
//
#include "tensorflow/lite/interpreter.h"
#include "tensorflow/lite/kernels/register.h"
#include "tensorflow/lite/model.h"

#ifndef PIPE_H
#define PIPE_H

namespace Arbe {
namespace Senses {
namespace Sight {
namespace Base {
namespace Processing {
namespace Tensorflow {
namespace Pipeline {

class Pipe {

public:
    [[nodiscard]] const char * get_model_path() const;

    void set_model_path(const char *model_path);

private:

    const char* model_path;

    Pipe() = default;

    void PreparePipeLine();

    ~Pipe() = default;
};

} // Pipeline
} // Tensorflow
} // Processing
} // Base
} // Sight
} // Senses
} // Arbe

#endif //PIPE_H
