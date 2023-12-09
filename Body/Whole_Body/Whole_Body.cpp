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

    Whole_Body::~Whole_Body() {

    }

    Whole_Body::Whole_Body() {
        try{

            Arm_Pinout leftArmPinout(0,1,2,3,4),
                       rightArmPinout(5,6,7,8,9);

            Arm leftArm( leftArmPinout ), rightArm(rightArmPinout);

            this->setArms({
                                  {Side_Of_Body::left,  leftArm},
                                  {Side_Of_Body::right, rightArm}
                          });

            Leg leftLeg, rightLeg;

            this->setLegs({
                                  {Side_Of_Body::left,  leftLeg},
                                  {Side_Of_Body::right, rightLeg}
                          });

            Logger::Success("Whole_Body", "Whole_Body", Error_Messaging::Object_Initiated_Successfully);
        }
        catch(exception e) {
            Logger::Error("Whole_Body", "Whole_Body", Error_Messaging::Object_Failed_To_Initiated);
        }

    }

    Arm Whole_Body::getArmBySideOfBody(Side_Of_Body sideOfBody) {

        map<Side_Of_Body, Arm> arms = this->getArms();

        return arms[sideOfBody];
    }

    Leg Whole_Body::getLegBySideOfBody(Side_Of_Body sideOfBody) {
        map<Side_Of_Body, Leg> legs = this->getLegs();

        return legs[sideOfBody];

    }
} // Body