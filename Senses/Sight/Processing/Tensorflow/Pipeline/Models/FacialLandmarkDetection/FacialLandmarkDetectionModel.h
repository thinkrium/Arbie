//
// Created by thom on 5/13/25.
//

#ifndef FACIALLANDMARKDETECTIONMODEL_H
#define FACIALLANDMARKDETECTIONMODEL_H
#include "../../../../../../Base/Processing/Tensorflow/Pipeline/Model.h"

namespace Arbie {
namespace Senses {
namespace Sight {
namespace Base {
namespace Processing {
namespace Tensorflow {
namespace Pipeline {

class FacialLandmarkDetectionModel : public Model {
public:
FacialLandmarkDetectionModel() = default;

~FacialLandmarkDetectionModel()  override = default;

void Preprocess() override;

    void Process(int loop_index) override;

    void Postprocess() override;
};

} // Pipeline
} // Tensorflow
} // Processing
} // Base
} // Sight
} // Senses
} // Arbie

#endif //FACIALLANDMARKDETECTIONMODEL_H
