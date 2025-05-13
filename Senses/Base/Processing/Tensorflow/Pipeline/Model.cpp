//
// Created by thom on 5/13/25.
//

#include "Model.h"

namespace Arbie {
namespace Senses {
namespace Sight {
namespace Base {
namespace Processing {
namespace Tensorflow {
namespace Pipeline {
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