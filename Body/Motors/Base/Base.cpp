//
// Created by thome on 11/9/2023.
//

#include "Base.h"

float Motor::Base::getDegrees() const {
    return Degrees;
}

void Motor::Base::setDegrees(float degrees) {
    Degrees = degrees;
}

Motor::Base::~Base() {

}

Motor::Base::Base() {}
