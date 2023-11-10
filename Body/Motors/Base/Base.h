//
// Created by thome on 11/9/2023.
//

#ifndef ARBIE_BASE_H
#define ARBIE_BASE_H

#include "../Utilities/Enumerations.h"

using namespace Utilities::Enumerations;

namespace Motor {

    class Base {

    public:

        Base();
        float getDegrees() const;

        void setDegrees(float degrees);

        virtual void Turn_Motor(Rotation_Direction rotationDirection, float degrees, float speed) = 0;

        virtual ~Base();

    private:
        float Degrees;
    };
}

#endif //ARBIE_BASE_H
