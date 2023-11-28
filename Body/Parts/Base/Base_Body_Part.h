//
// Created by thome on 11/27/2023.
//

#ifndef ARBIE_BASE_BODY_PART_H
#define ARBIE_BASE_BODY_PART_H
#include "iostream"

using namespace std;

namespace Body {
    namespace Parts {

        class Base_Body_Part {
        public:
            Base_Body_Part();

            string part_name ;

            int part_length;


            int getPartLength() const;

            void setPartLength(int partLength);

            virtual ~Base_Body_Part();
        };

    } // Body
} // Parts

#endif //ARBIE_BASE_BODY_PART_H
