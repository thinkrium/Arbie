//
// Created by thome on 11/9/2023.
//

#include "Base_Motor.h"

float Motor::Base_Motor::getDegrees() const {
    return degrees;
}

void Motor::Base_Motor::setDegrees(float degrees) {
    degrees = degrees;
}

Motor::Base_Motor::~Base_Motor() {

}

Motor::Base_Motor::Base_Motor() {}

Pin_Number Motor::Base_Motor::getPinNumber() const {
    return pin_number;
}

void Motor::Base_Motor::setPinNumber(Pin_Number pinNumber) {
    pin_number = pinNumber;
}
