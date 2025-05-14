//
// Created by thom on 5/13/25.
//

#ifndef FACEDETECTIONMODEL_H
#define FACEDETECTIONMODEL_H
#include "Model.h"

namespace Arbie {
namespace Senses {
namespace Sight {
namespace Base {
namespace Processing {
namespace Tensorflow {
namespace Pipeline {

class FaceDetectionModel : public Model {
public:
    FaceDetectionModel() = default;

    void Preprocess() override;

    void Process() override;

    void Postprocess() override;

  ~FaceDetectionModel()   = default;
};

} // Pipeline
} // Tensorflow
} // Processing
} // Base
} // Sight
} // Senses
} // Arbie

#endif //FACEDETECTIONMODEL_H
