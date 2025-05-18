//
// Created by thom on 10/4/24.
//

#ifndef BODYPARTPROFILES_H
#define BODYPARTPROFILES_H
#include <string>

using namespace  std;

namespace Shared {
    namespace Profiles {
        static  struct {

            // Joints

            string LeftAnkle = "Left Ankle";
            string RightAnkle = "Right Ankle";
            string LeftKnee = "Left Knee";
            string RightKnee = "Right Knee";
            string LeftHip = "Left Hip";
            string RightHip = "Right Hip";
            string LeftShoulder = "Left Shoulder";
            string RightShoulder = "Right Shoulder";
            string LeftElbow = "Left Elbow";
            string RightElbow = "Right Elbow";
            string LeftWrist = "Left Wrist";
            string RightWrist = "Right Wrist";


            string Torsoe = "Torsoe";
            string Neck = "Neck";


        } BodyPart;
    }
}
#endif //BODYPARTPROFILES_H
