//
// Created by thom on 5/13/25.
//

#ifndef POSEDETECTIONMODEL_H
#define POSEDETECTIONMODEL_H
#include "../../../../../../Base/Processing/Tensorflow/Pipeline/Model.h"

namespace Arbie {
namespace Senses {
namespace Sight {
namespace Base {
namespace Processing {
namespace Tensorflow {
namespace Pipeline {

class PoseDetectionModel : public Model {
public:
    void Preprocess() override;

    void Process() override;

    void Postprocess() override;

    PoseDetectionModel() = default;

    ~PoseDetectionModel() override = default;
};

} // Pipeline
} // Tensorflow
} // Processing
} // Base
} // Sight
} // Senses
} // Arbie

#endif //POSEDETECTIONMODEL_H
