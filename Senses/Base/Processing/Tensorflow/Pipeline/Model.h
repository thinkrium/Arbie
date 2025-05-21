//
// Created by thom on 5/13/25.
//

#ifndef MODEL_H
#define MODEL_H
#include <opencv2/core/mat.hpp>

#include "ModelDetails.h"
#include "tensorflow/lite/interpreter.h"

namespace Arbie::Senses::Base::Processing::Tensorflow::Pipeline {
    struct BoundingBox;
}

namespace Arbie {
namespace Senses {
namespace Sight {
namespace Base {
namespace Processing {
namespace Tensorflow {
    namespace Pipeline {
        class Model {
        public:
            virtual ~Model();

            Model(Model && other);

            Model & operator=(Model & other);

            virtual void Preprocess();

            virtual void Process(int loop_index);

            virtual void Postprocess();

            char * get_model_path() const;

            void set_model_path(char *model_path);

            ModelDetails & get_model_details()  ;

            void set_model_details(const ModelDetails &model_details);

            Model();



            // virtual void DrawDetection(cv::Mat &image , std::vector<Senses::Base::Processing::Tensorflow::Pipeline::BoundingBox> & bounding_boxes) ;
        private:

            char * model_path;

            ModelDetails model_details_;

            tflite::Interpreter * interpreter;

        public:
            tflite::Interpreter * get_interpreter();

            void set_interpreter( tflite::Interpreter * interpreter);
        };
    }
} // Tensorflow
} // Processing
} // Base
} // Sight
} // Senses
} // Arbie

#endif //MODEL_H
