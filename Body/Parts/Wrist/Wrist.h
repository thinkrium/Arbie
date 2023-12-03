//
// Created by thome on 12/2/2023.
//

#ifndef ARBIE_WRIST_H
#define ARBIE_WRIST_H

#include "../../../Body/Parts/Base/Base_Body_Part.h"

namespace Body {
    namespace Parts {

        class Wrist : public Base_Body_Part {
        public:
            Wrist();

            ~Wrist() override;

        };

    } // Body
} // Parts

#endif //ARBIE_WRIST_H
