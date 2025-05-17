//
// Created by thomd on 5/13/25.
//

#include "FaceDetectionModel.h"

namespace Arbie {
namespace Senses {
namespace Sight {
namespace Base {
namespace Processing {
namespace Tensorflow {
namespace Pipeline {
    float *& FaceDetectionModel::get_detection_scores() {
        return detection_scores;
    }

    void FaceDetectionModel::set_detection_scores(float *detection_scores) {
        this->detection_scores = detection_scores;
    }

    float *& FaceDetectionModel::get_detection_boxes() {
        return detection_boxes;
    }

    void FaceDetectionModel::set_detection_boxes(float *detection_boxes) {
        this->detection_boxes = detection_boxes;
    }

    TfLiteTensor *  FaceDetectionModel::get_boxes_tensor() {
        return boxes_tensor;
    }

    void FaceDetectionModel::set_boxes_tensor(TfLiteTensor *boxes_tensor) {
        this->boxes_tensor = boxes_tensor;
    }

    TfLiteTensor *  FaceDetectionModel::get_scores_tensor() {
        return scores_tensor;
    }

    void FaceDetectionModel::set_scores_tensor(TfLiteTensor *scores_tensor) {
        this->scores_tensor = scores_tensor;
    }

    void FaceDetectionModel::Preprocess() {
    }

    void FaceDetectionModel::Process() {
        this->set_scores_tensor(  this->get_interpreter()->tensor(this->get_interpreter()->outputs()[1]) );
        this->set_boxes_tensor(  this->get_interpreter()->tensor(this->get_interpreter()->outputs()[0]) );



        this->set_detection_scores(this->get_scores_tensor()->data.f);
        this->set_detection_boxes(this->get_boxes_tensor()->data.f);
    }


    void FaceDetectionModel::Postprocess() {
    }
} // Pipeline
} // Tensorflow
} // Processing
} // Base
} // Sight
} // Senses
} // Arbie