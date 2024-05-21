#ifndef _WINDOWS
//
// Created by thome on 12/1/2023.
//
#ifndef ARBIE_LEG_H

#define ARBIE_LEG_H

#include "../Base/Base_Body_Part.h"

namespace Body {
    namespace Parts {

        class Leg : public Base_Body_Part  {

        public:
            Leg();

            ~Leg() override;
        };

    } // Body
} // Parts

#endif //ARBIE_LEG_H
#endif
