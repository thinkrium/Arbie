//
// Created by thome on 11/27/2023.
//

#ifndef ARBIE_BASE_BODY_PART_H
#define ARBIE_BASE_BODY_PART_H
#include "iostream"
#include "../../../Utilities/Enumerations.h"
#include "../../Motors/Base/Base_Motor.h"
#include "../../Motors/Servo/Servo_Motor.h"

using namespace std;
using namespace Utilities::Enumerations;
using namespace Motors;

namespace Body {
    namespace Parts {

        class Base_Body_Part {
        private:
            Body_Part part_name ;

            Body_Side body_side;

            int part_length;

            bool is_joint;
        public:
            bool isJoint() const;

            void setIsJoint(bool isJoint);


        public:
            Base_Body_Part(   );


            Body_Part getPartName() const;

            void setPartName(Body_Part partName);

            Body_Side getBodySide() const;

            void setBodySide(Body_Side bodySide);

            int getPartLength() const;

            void setPartLength(int partLength);

            virtual ~Base_Body_Part();

         };

    } // Body
} // Parts

#endif //ARBIE_BASE_BODY_PART_H
