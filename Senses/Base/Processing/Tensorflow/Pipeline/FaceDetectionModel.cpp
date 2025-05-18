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


    void FaceDetectionModel::create_anchor_boxes( std::vector<std::pair<float, float>>& anchor_list,int width = 128, int height = 128)
    {


        std::array<std::pair<int32_t, int32_t>, 2> kAnchorGridSize = { std::pair<int32_t, int32_t>(16, 16), std::pair < int32_t, int32_t>(8, 8) };
        std::array<int32_t, 2> kAnchorNum = { 2, 6 };



        for (size_t i = 0; i < kAnchorGridSize.size(); i++) {
            int32_t grid_cols = kAnchorGridSize[i].first;
            int32_t grid_rows = kAnchorGridSize[i].second;
            float  stride_x = static_cast<float>(width) / grid_cols;
            float  stride_y = static_cast<float>(height) / grid_rows;
            int anchor_num = kAnchorNum[i];

            std::pair<float, float> anchor;
            for (int grid_y = 0; grid_y < grid_rows; grid_y++) {
                anchor.second = stride_y * (grid_y + 0.5f);
                for (int grid_x = 0; grid_x < grid_cols; grid_x++) {
                    anchor.first = stride_x * (grid_x + 0.5f);
                    for (int n = 0; n < anchor_num; n++) {
                        anchor_list.push_back(anchor);
                    }
                }
            }
        }

    }


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