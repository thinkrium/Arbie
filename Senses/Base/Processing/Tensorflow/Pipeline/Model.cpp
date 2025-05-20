//
// Created by thom on 5/13/25.
//

#include "Model.h"

#include <opencv2/imgproc.hpp>

#include "BoundingBox.h"

namespace Arbie {
namespace Senses {
namespace Sight {
namespace Base {
namespace Processing {
namespace Tensorflow {
namespace Pipeline {
    Model::~Model() {
    }

    Model::Model(Model &&other) {
        this->interpreter = std::move(other.interpreter);
        this->model_details_ = other.model_details_;
        this->model_path = other.model_path;
    }

    Model & Model::operator=(Model &other) {

        this->interpreter = std::move(other.interpreter);
        this->model_details_ = other.model_details_;
        this->model_path = other.model_path;

        return *this;


    }

    void Model::Preprocess() {
    }

    void Model::Process(int loop_index) {
    }

    void Model::Postprocess() {
    }

    Model::Model() {
        this->set_model_path("");
        ModelDetails details;

        details.channels = 0;
        details.width = 0;
        details.height = 0;

        this->set_model_details(details);
    }

    void Model::DrawDetection(cv::Mat &image , std::vector<Senses::Base::Processing::Tensorflow::Pipeline::BoundingBox> & bounding_boxes) {


        if (
                bounding_boxes.at(0).x <= 0 || bounding_boxes.at(0).y <= 0 ||
               bounding_boxes.at(0).x + bounding_boxes.at(0).width >= image.cols ||
               bounding_boxes.at(0).y + bounding_boxes.at(0).height >= image.rows ||
               bounding_boxes.at(0).width <= 0 || bounding_boxes.at(0).height <= 0) {
              // this-pfalse; // Reset if out of bounds
            exit(33);
   }

         // Draw bounding box
        cv::rectangle(image, cv::Point(bounding_boxes.at(0).x, bounding_boxes.at(0).y),
        cv::Point(bounding_boxes.at(0).x + bounding_boxes.at(0).width, bounding_boxes.at(0).y + bounding_boxes.at(0).height),
        cv::Scalar(255, 0, 0), 2);



    }

    tflite::Interpreter * Model::get_interpreter() {
        return interpreter;
    }

    void Model::set_interpreter( tflite::Interpreter * interpreter) {


        this->interpreter = interpreter ;//
    }

    ModelDetails & Model::get_model_details() {
        return model_details_;
    }

    void Model::set_model_details(const ModelDetails &model_details) {
        model_details_ = model_details;
    }

    char * Model::get_model_path() const {
        return model_path;
    }

    void Model::set_model_path(char *model_path) {
        this->model_path = model_path;
    }
} // Pipeline
} // Tensorflow
} // Processing
} // Base
} // Sight
} // Senses
} // Arbie