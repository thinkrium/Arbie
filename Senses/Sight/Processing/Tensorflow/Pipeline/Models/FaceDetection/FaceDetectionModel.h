//
// Created by thom on 5/13/25.
//

#ifndef FACEDETECTIONMODEL_H
#define FACEDETECTIONMODEL_H
#include "../../../../../../Base/Processing/Tensorflow/Pipeline/BoundingBox.h"
#include "../../../../../../Base/Processing/Tensorflow/Pipeline/Model.h"
#include "tensorflow/lite/c/common.h"

namespace Arbie {
namespace Senses {
namespace Sight {
namespace Base {
namespace Processing {
namespace Tensorflow {
namespace Pipeline {

using namespace Senses::Base::Processing::Tensorflow::Pipeline;

class FaceDetectionModel : public Model {

    TfLiteTensor*  boxes_tensor ;
    TfLiteTensor*  scores_tensor;

    float* detection_scores;
    float* detection_boxes ;

    std::vector<std::pair<float, float>> anchor_list;

    int number_of_detections;

    int image_width;

    int image_height;

    std::vector<BoundingBox> bounding_boxes_;

public:
    int & get_image_width();

    std::vector<BoundingBox> & get_bounding_boxes();

    void set_bounding_boxes(std::vector<BoundingBox> bounding_boxes);

    void set_image_width(int image_width);

    int & get_image_height();

    void set_image_height(int image_height);

    int & get_number_of_detections();

    void set_number_of_detections(int number_of_detections);

    void create_anchor_boxes( int width = 128, int height = 128);

    float *& get_detection_scores();

    void set_detection_scores(float *detection_scores);

    float *& get_detection_boxes();

    void set_detection_boxes(float *detection_boxes);

    TfLiteTensor * get_boxes_tensor();

    void set_boxes_tensor(TfLiteTensor *boxes_tensor);

    TfLiteTensor * get_scores_tensor();

    std::vector<std::pair<float, float>> & get_anchor_list();

    void set_anchor_list(std::vector<std::pair<float, float>> anchor_list);

    void set_scores_tensor(TfLiteTensor *scores_tensor);

    FaceDetectionModel();

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
