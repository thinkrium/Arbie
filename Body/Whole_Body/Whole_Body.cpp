//
// Created by thome on 12/1/2023.
//

#include "Whole_Body.h"

namespace Body {
    const map<Side_Of_Body, Arm> &Whole_Body::getArms() const {
        return arms;
    }

    void Whole_Body::setArms(const map<Side_Of_Body, Arm> &arms) {
        Whole_Body::arms = arms;
    }

    const map<Side_Of_Body, Leg> &Whole_Body::getLegs() const {
        return legs;
    }

    void Whole_Body::setLegs(const map<Side_Of_Body, Leg> &legs) {
        Whole_Body::legs = legs;
    }
} // Body