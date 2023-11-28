//
// Created by thome on 11/9/2023.
//

#include "Base_Motor.h"



Motors::Base_Motor::~Base_Motor() {

}

Motors::Base_Motor::Base_Motor() {}

const string &Motors::Base_Motor::getMotorName() const {
    return motor_name;
}

void Motors::Base_Motor::setMotorName(const string &motorName) {
    motor_name = motorName;
}


int Motors::Base_Motor::getPinNumber() const {
    return pin_number;
}

void Motors::Base_Motor::setPinNumber(int pinNumber) {
    pin_number = pinNumber;
}

void Motors::Base_Motor::setDegreeOfRotation(int degreeOfRotation) {
    degree_of_rotation = degreeOfRotation;
}

int Motors::Base_Motor::getDegreeOfRotation() const {
    return degree_of_rotation;
}

Motors::Base_Motor::Base_Motor(int pinNumber) {

}
