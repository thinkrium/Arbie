//
// Created by thom on 5/16/25.
//

#include "../Base/Processing/Tensorflow/Pipeline/Pipe.h"
#include "../Base/Sense/BaseSense.h"

using namespace Arbie::Senses::Sight::Base::Processing::Tensorflow;

#ifndef SIGHT_H
#define SIGHT_H

namespace Arbie {
namespace Senses {

class SenseOfSight : public Sight::BaseSense {

    Pipeline::Pipe face_detection_pipe;

public:

    void process() override;

   SenseOfSight() ;

    ~SenseOfSight() override = default;
};

} // Senses
} // Arbie

#endif //SIGHT_H
