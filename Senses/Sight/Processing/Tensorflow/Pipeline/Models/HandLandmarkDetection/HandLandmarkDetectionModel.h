//
// Created by thom on 5/13/25.
//

#ifndef HANDLANDMARKDETECTIONMODEL_H
#define HANDLANDMARKDETECTIONMODEL_H
#include "../../../../../../Base/Processing/Tensorflow/Pipeline/Model.h"

namespace Arbie {
namespace Senses {
namespace Sight {
namespace Base {
namespace Processing {
namespace Tensorflow {
namespace Pipeline {

class HandLandmarkDetectionModel : public Model {
public:
    HandLandmarkDetectionModel() = default;
 void Preprocess(tflite::Interpreter * interpreter) override;

    void Process(int loop_index) override;

    void Postprocess() override;

      ~HandLandmarkDetectionModel() = default;
};

} // Pipeline
} // Tensorflow
} // Processing
} // Base
} // Sight
} // Senses
} // Arbie

#endif //HANDLANDMARKDETECTIONMODEL_H
