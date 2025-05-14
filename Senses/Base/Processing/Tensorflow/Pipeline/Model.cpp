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
    Model::~Model() {
    }

    void Model::Preprocess() {
    }

    void Model::Process() {
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