//
// Created by thom on 10/3/24.
//

#ifndef MOVEMENTPROFILES_H
#define MOVEMENTPROFILES_H
#include <map>
#include <string>
#include <vector>

#include "BodyPartProfiles.h"
#include "MotorAxis.h"

using namespace std;
namespace Shared {
    namespace Profiles {
        class MovementProfiles {
        public:
            MovementProfiles() = default;

            ~MovementProfiles() = default;

            class IndividualAxisMovement {
            public:
                string axisName;
                float axisAngle;

                IndividualAxisMovement(const string &axis_name, float axis_angle)
                    : axisName(axis_name),
                      axisAngle(axis_angle) {
                }

                ~IndividualAxisMovement() = default;
            };


            class RelativeJointMovement {

            public:

                string bodyPartName ;
                vector <IndividualAxisMovement> individual_axis_movement;

                RelativeJointMovement(const string &body_part_name, vector<IndividualAxisMovement> individual_axis_movement)
                     : bodyPartName(body_part_name),
                       individual_axis_movement(individual_axis_movement) {
                }

                ~RelativeJointMovement() = default;
            };

            static struct  MovementStages {

                string stage1 = "Stage 1";
                string stage2 = "Stage 2";
                string stage3 = "Stage 3";
                string stage4 = "Stage 4";
            };

            class MovementStage {

            public:
                vector<RelativeJointMovement> relative_joint_movement;

                MovementStage(  vector<RelativeJointMovement> relative_joint_movement)
                    :   relative_joint_movement(relative_joint_movement) {
                }

                ~MovementStage() = default;
            };

            static struct {
                map<string, MovementStage > move = {
                     {MovementStages::stage1, MovementStage(
                         {
                             RelativeJointMovement(
                                BodyPart.LeftAnkle,
                             {
                                  IndividualAxisMovement(MotorAxis.XAxis,90)
                                 }
                             ) ,
                          RelativeJointMovement(
                              BodyPart.LeftKnee,
                             {
                                  IndividualAxisMovement(MotorAxis.XAxis,90)
                                 }
                             )
                         })}

                };


            } ForwardMovement;
        };
    }
}

#endif //MOVEMENTPROFILES_H
