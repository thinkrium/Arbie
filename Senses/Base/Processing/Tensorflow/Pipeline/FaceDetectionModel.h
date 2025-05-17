//
// Created by thom on 5/13/25.
//

#ifndef FACEDETECTIONMODEL_H
#define FACEDETECTIONMODEL_H
#include "Model.h"
#include "tensorflow/lite/c/common.h"

namespace Arbie {
namespace Senses {
namespace Sight {
namespace Base {
namespace Processing {
namespace Tensorflow {
namespace Pipeline {

class FaceDetectionModel : public Model {

    TfLiteTensor*  boxes_tensor ;
    TfLiteTensor*  scores_tensor;

    float* detection_scores;
    float* detection_boxes ;
public:
    float *& get_detection_scores();

    void set_detection_scores(float *detection_scores);

    float *& get_detection_boxes();

    void set_detection_boxes(float *detection_boxes);

    TfLiteTensor * get_boxes_tensor();

    void set_boxes_tensor(TfLiteTensor *boxes_tensor);

    TfLiteTensor * get_scores_tensor();

    void set_scores_tensor(TfLiteTensor *scores_tensor);

    FaceDetectionModel() = default;

    void Preprocess() override;

    void Process() override;

    void Postprocess() override;

    ~FaceDetectionModel() override  = default;
};

} // Pipeline
} // Tensorflow
} // Processing
} // Base
} // Sight
} // Senses
} // Arbie

#endif //FACEDETECTIONMODEL_H
