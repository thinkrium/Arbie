//
// Created by thome on 11/30/2023.
//

#include "Arm.h"

namespace Body {
    namespace Parts {
        Arm::Arm() {
            Wrist leftWrist, rightWrist;
            Elbow leftElbow, rightElbow;
            Shoulder leftShoulder, rightShoulder;

            setWrists({
                {Side_Of_Body::left, leftWrist}
               ,{Side_Of_Body::right, rightWrist}
            });

            setElbows({
               {Side_Of_Body::left, leftElbow}
              ,{Side_Of_Body::right, rightElbow}
            });

            setShoulders({
               {Side_Of_Body::left, leftShoulder}
              ,{Side_Of_Body::right, rightShoulder}
            });

        }

        Arm::~Arm() {

        }

        const map<Side_Of_Body, Shoulder> &Arm::getShoulders() const {
            return shoulders;
        }

        void Arm::setShoulders(const map<Side_Of_Body, Shoulder> &shoulders) {
            Arm::shoulders = shoulders;
        }

        const map<Side_Of_Body, Elbow> &Arm::getElbows() const {
            return elbows;
        }

        void Arm::setElbows(const map<Side_Of_Body, Elbow> &elbows) {
            Arm::elbows = elbows;
        }

        const map<Side_Of_Body, Wrist> &Arm::getWrists() const {
            return wrists;
        }

        void Arm::setWrists(const map<Side_Of_Body, Wrist> &wrists) {
            Arm::wrists = wrists;
        }

        Arm::Arm(const map<Side_Of_Body, Shoulder> &shoulders, const map<Side_Of_Body, Elbow> &elbows,
                 const map<Side_Of_Body, Wrist> &wrists) : shoulders(shoulders), elbows(elbows), wrists(wrists) {

            setShoulders(shoulders);
            setElbows(elbows);
            setWrists(wrists);
        }

    } // Body
} // Parts