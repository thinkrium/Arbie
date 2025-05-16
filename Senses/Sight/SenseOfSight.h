//
// Created by thom on 5/16/25.
//

#include "../Base/Processing/Tensorflow/Pipeline/Pipe.h"
using namespace Arbie::Senses::Sight::Base::Processing::Tensorflow;

#ifndef SIGHT_H
#define SIGHT_H

namespace Arbie {
namespace Senses {

class SenseOfSight {

private:
    std::vector<Pipeline::Pipe> pipes;

public:
    std::vector<Pipeline::Pipe> get_pipes() ;

    void set_pipes(std::vector<Pipeline::Pipe> pipes);

    SenseOfSight();

    ~SenseOfSight() = default;
};

} // Senses
} // Arbie

#endif //SIGHT_H
