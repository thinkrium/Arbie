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

    KalmanSmoothing & FaceDetectionModel::get_kalman_smoothing() {
        return kalman_smoothing_;
    }

    void FaceDetectionModel::set_kalman_smoothing(KalmanSmoothing kalman_smoothing) {
        kalman_smoothing_ = std::move(kalman_smoothing);
    }

    int & FaceDetectionModel::get_image_width() {
        return image_width;
    }

    std::vector<BoundingBox> & FaceDetectionModel::get_bounding_boxes() {
        return bounding_boxes_;
    }

    void FaceDetectionModel::set_bounding_boxes(std::vector<BoundingBox> bounding_boxes) {
        bounding_boxes_ = std::move(bounding_boxes);
    }

    void FaceDetectionModel::set_image_width(int image_width) {
        this->image_width = image_width;
    }

    int & FaceDetectionModel::get_image_height() {
        return image_height;
    }

    void FaceDetectionModel::set_image_height(int image_height) {
        this->image_height = image_height;
    }

    int & FaceDetectionModel::get_number_of_detections() {
        return number_of_detections;
    }

    void FaceDetectionModel::set_number_of_detections(int number_of_detections) {
        this->number_of_detections = number_of_detections;
    }

    void FaceDetectionModel::create_anchor_boxes(  int width, int height)
    {

        this->set_anchor_list({});


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
                        this->anchor_list.push_back(anchor);
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

    std::vector<std::pair<float, float>> & FaceDetectionModel::get_anchor_list() {
        return anchor_list;
    }

    void FaceDetectionModel::set_anchor_list(std::vector<std::pair<float, float>> anchor_list) {
        this->anchor_list = std::move(anchor_list);
    }

    void FaceDetectionModel::set_scores_tensor(TfLiteTensor *scores_tensor) {
        this->scores_tensor = scores_tensor;
    }

    FaceDetectionModel::FaceDetectionModel() {
        this->create_anchor_boxes();
        KalmanSmoothing temporarySmoothing;
        this->set_kalman_smoothing(temporarySmoothing);
    }

    void FaceDetectionModel::Preprocess() {
        this->set_scores_tensor(  this->get_interpreter()->tensor(this->get_interpreter()->outputs()[1]) );
        this->set_boxes_tensor(  this->get_interpreter()->tensor(this->get_interpreter()->outputs()[0]) );



        this->set_detection_scores(this->get_scores_tensor()->data.f);
        this->set_detection_boxes(this->get_boxes_tensor()->data.f);

        this->set_bounding_boxes({});

        this->set_number_of_detections( this->get_scores_tensor()->dims->data[1] );

    }

    void FaceDetectionModel::Process(int loop_index) {

        float scale ;


        if (loop_index >= this->get_number_of_detections()) return;

        float detection_score = this->get_detection_scores()[loop_index];

        if (detection_score > 0.85f) {



            int32_t detection_index = loop_index * 16;


            float cx0 = this->get_detection_boxes()[detection_index + 0];
            float cy0 = this->get_detection_boxes()[detection_index + 1];

            float cx = cx0 + this->get_anchor_list()[loop_index].first;
            float cy = cy0 + this->get_anchor_list()[loop_index].second;

            float w0 = this->get_detection_boxes()[detection_index + 2];
            float h0 = this->get_detection_boxes()[detection_index + 3];

            float relative_x_position = static_cast<float>(this->get_image_width()) / this->get_model_details().width;
            float relative_y_position = static_cast<float>(this->get_image_height()) / this->get_model_details().height;


            scale = 1.5; //std::max(scale_x, scale_y);


            int x = static_cast<int>((cx - w0 * scale   / 2 ) * relative_x_position);
            int y = static_cast<int>((cy - h0 * scale   / 2 ) * relative_y_position);
            int w = static_cast<int>(w0 * relative_x_position * scale);
            int h = static_cast<int>(h0 * relative_y_position  * scale);

            if (w > h) {h = w;}
            else if (w < h) {w = h;}


            BoundingBox pushable_bounding_box;
            pushable_bounding_box.center_x = cx;
            pushable_bounding_box.center_y = cy;
            pushable_bounding_box.x = x;
            pushable_bounding_box.y = y;
            pushable_bounding_box.width = w;
            pushable_bounding_box.height = h;
            pushable_bounding_box.detection_score = detection_score;
            pushable_bounding_box.detection_index = loop_index;

            this->get_bounding_boxes().push_back( pushable_bounding_box );


        }



    }


    void FaceDetectionModel::Postprocess() {
        if (this->get_bounding_boxes().empty()) {
            // std::cout << "No detection\n";
            exit(33);
        }

        std::sort(this->get_bounding_boxes().begin(), this->get_bounding_boxes().end(), [](const BoundingBox& a, const BoundingBox& b) {
              return a.detection_score > b.detection_score;
          });

        float prediction_x = this->get_kalman_smoothing().get_prediction_matrix().at<float>(0);
        float prediction_y = this->get_kalman_smoothing().get_prediction_matrix().at<float>(1);
        float prediction_w = this->get_kalman_smoothing().get_prediction_matrix().at<float>(2);
        float prediction_h = this->get_kalman_smoothing().get_prediction_matrix().at<float>(3);


        for ( BoundingBox looped_bounding_box: this->get_bounding_boxes() ) {
            if ( this->get_kalman_smoothing().is_initialized() && prediction_x > 0 && prediction_y > 0 && prediction_w > 0 && prediction_h > 0 ) {
                looped_bounding_box.x = static_cast<int>(prediction_x - prediction_w / 2);
                looped_bounding_box.y = static_cast<int>(prediction_y - prediction_h / 2);
                looped_bounding_box.width = static_cast<int>(prediction_w);
                looped_bounding_box.height = static_cast<int>(prediction_h);
            }
            // // //////////////////////////////////////////////////////////////////////////////////////////////////////
            // // ///////////////////////////////////////////////////////////////////////////////////////////////////

            if (
                looped_bounding_box.x <= 0 || looped_bounding_box.y <= 0 ||
                looped_bounding_box.x + looped_bounding_box.width >= this->get_image_width() ||
                looped_bounding_box.y + looped_bounding_box.height >= this->get_image_height() ||
                looped_bounding_box.width <= 0 || looped_bounding_box.height <= 0) {
                this->get_kalman_smoothing().set_initialized( false); // Reset if out of bounds
                return;
                }


        }


        }
        void FaceDetectionModel::DrawDetection(cv::Mat & image) {
            BoundingBox drawable_box = this->get_bounding_boxes().at(0);

            // Draw bounding box
            cv::rectangle(image, cv::Point( drawable_box.x, drawable_box.y),
            cv::Point(drawable_box.x + drawable_box.width, drawable_box.y + drawable_box.height),
            cv::Scalar(255, 0, 0), 2);
        }

} // Pipeline
} // Tensorflow
} // Processing
} // Base
} // Sight
} // Senses
} // Arbie