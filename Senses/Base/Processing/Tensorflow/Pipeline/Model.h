//
// Created by thom on 5/13/25.
//

#ifndef MODEL_H
#define MODEL_H

namespace Arbie {
namespace Senses {
namespace Sight {
namespace Base {
namespace Processing {
namespace Tensorflow {
    namespace Pipeline {
        class Model {
        public:
              ~Model() = default;


            virtual void Preprocess() = 0;
            virtual void Process() = 0;
            virtual void Postprocess() = 0;

            Model() = default;
        };
    }
} // Tensorflow
} // Processing
} // Base
} // Sight
} // Senses
} // Arbie

#endif //MODEL_H
