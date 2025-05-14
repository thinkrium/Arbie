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
            virtual ~Model();


            virtual void Preprocess();
            virtual void Process();
            virtual void Postprocess();

            Model() = default;

        private:
            char * model_path;

          public:
              char * get_model_path() const;

              void set_model_path(char *model_path);
        };
    }
} // Tensorflow
} // Processing
} // Base
} // Sight
} // Senses
} // Arbie

#endif //MODEL_H
