//
// Created by thom on 5/13/25.
//

#ifndef OBJECTDETECTIONMODEL_H
#define OBJECTDETECTIONMODEL_H
#include "../../../../../../Base/Processing/Tensorflow/Pipeline/Model.h"

namespace Arbie {
namespace Senses {
namespace Sight {
namespace Base {
namespace Processing {
namespace Tensorflow {
namespace Pipeline {

class ObjectDetectionModel : public Model {
public:
ObjectDetectionModel() = default;

    void Preprocess() override;

    void Process(int loop_index) override;

    void Postprocess() override;

~ObjectDetectionModel() override  = default;
};

} // Pipeline
} // Tensorflow
} // Processing
} // Base
} // Sight
} // Senses
} // Arbie

#endif //OBJECTDETECTIONMODEL_H
