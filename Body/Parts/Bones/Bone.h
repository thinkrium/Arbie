#ifndef _WINDOWS
//
// Created by thome on 12/13/2023.
//
#ifndef ARBIE_BONE_H

#define ARBIE_BONE_H

#include "../../Parts/Base/Base_Body_Part.h"


namespace Body {
    namespace Parts {
        namespace Bones {

            class Bone : public Base_Body_Part {
            private:
                /**
                 * bone length is measured in mm
                 */
                float bone_length;
            public:
                explicit Bone(float boneLength);

                Bone();

                ~Bone() override;

                float getBoneLength() const;

                void setBoneLength(float boneLength);
            };

        } // Body
    } // Parts
} // Bones

#endif //ARBIE_BONE_H
#endif
