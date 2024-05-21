#ifndef _WINDOWS
//
// Created by thome on 12/13/2023.
//
#include "Bone.h"

namespace Body {
    namespace Parts {
        namespace Bones {
            Bone::Bone(float boneLength) : bone_length(boneLength) {}

            Bone::Bone() {}

            Bone::~Bone() {

            }

            float Bone::getBoneLength() const {
                return bone_length;
            }

            void Bone::setBoneLength(float boneLength) {
                bone_length = boneLength;
            }
        } // Body
    } // Parts
} // Bones

#endif
