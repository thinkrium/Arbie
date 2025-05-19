//
// Created by thom on 5/18/25.
//

#ifndef VISUALMODEL_H
#define VISUALMODEL_H
#include <opencv2/core/mat.hpp>

#include "../../../../../Base/Processing/Tensorflow/Pipeline/Model.h"

namespace Arbie {
namespace Senses {
namespace Sight {
namespace Processing {
namespace Tensorflow {
namespace Pipeline {
namespace Models {

class VisualModel : public Arbie::Senses::Sight::Base::Processing::Tensorflow::Pipeline::Model {
public:

    VisualModel( ) = default;


    virtual void DrawDetection(cv::Mat & image) ;

    virtual ~VisualModel()  = default;
};

} // Models
} // Pipeline
} // Tensorflow
} // Processing
} // Sight
} // Senses
} // Arbie

#endif //VISUALMODEL_H
