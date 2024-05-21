#ifndef _WINDOWS
//
// Created by thome on 11/27/2023.
//
#include "Base_Body_Part.h"

namespace Body {
    namespace Parts {
        Base_Body_Part::~Base_Body_Part() {

        }


        int Base_Body_Part::getPartLength() const {
            return part_length;
        }

        void Base_Body_Part::setPartLength(int partLength) {
            part_length = partLength;
        }

        Body_Part Base_Body_Part::getPartName() const {
            return part_name;
        }

        void Base_Body_Part::setPartName(Body_Part partName) {
            part_name = partName;
        }

        Side_Of_Body Base_Body_Part::getBodySide() const {
            return body_side;
        }

        void Base_Body_Part::setBodySide(Side_Of_Body bodySide) {
            body_side = bodySide;
        }

        Base_Body_Part::Base_Body_Part() {

        }

        bool Base_Body_Part::isJoint() const {
            return is_joint;
        }

        void Base_Body_Part::setIsJoint(bool isJoint) {
            is_joint = isJoint;
        }


    } // Body
} // Parts

#endif
