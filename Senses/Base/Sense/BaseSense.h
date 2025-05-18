//
// Created by thom on 5/9/25.
//

#ifndef BASESENSE_H
#define BASESENSE_H

namespace Arbie {
namespace Senses {
namespace Sight {

class BaseSense {
public:
    BaseSense();

    virtual void process();

    virtual ~BaseSense() = default;
};

} // Sight
} // Senses
} // Arbie

#endif //BASESENSE_H
