//
// Created by thom on 5/17/25.
//

#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

namespace Arbie {
namespace Senses {
namespace Base {
namespace Processing {
namespace Tensorflow {
namespace Pipeline {

struct  BoundingBox {

    int center_x;
    int center_y;
    int x;
    int y;
    int width;
    int height;
    float detection_score;
    int detection_index;

};

} // Pipeline
} // Tensorflow
} // Processing
} // Base
} // Senses
} // Arbie

#endif //BOUNDINGBOX_H
