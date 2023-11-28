//
// Created by thome on 11/27/2023.
//

#include "Base_Body_Part.h"

namespace Body {
    namespace Parts {
        Base_Body_Part::~Base_Body_Part() {

        }

        Base_Body_Part::Base_Body_Part() {}

        int Base_Body_Part::getPartLength() const {
            return part_length;
        }

        void Base_Body_Part::setPartLength(int partLength) {
            part_length = partLength;
        }

    } // Body
} // Parts