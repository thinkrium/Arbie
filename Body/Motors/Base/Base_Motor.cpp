//
// Created by thome on 11/9/2023.
//

#include "Base_Motor.h"



Motor::Base_Motor::~Base_Motor() {

}

Motor::Base_Motor::Base_Motor() {}

int Motor::Base_Motor::getPinNumber() const {
    return pin_number;
}

void Motor::Base_Motor::setPinNumber(int pinNumber) {
    pin_number = pinNumber;
}

void Motor::Base_Motor::setDegreeOfRotation(int degreeOfRotation) {
    degree_of_rotation = degreeOfRotation;
}

int Motor::Base_Motor::getDegreeOfRotation() const {
    return degree_of_rotation;
}
