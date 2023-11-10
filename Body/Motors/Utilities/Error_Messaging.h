//
// Created by thome on 11/10/2023.
//

#ifndef ARBIE_ERROR_MESSAGING_H
#define ARBIE_ERROR_MESSAGING_H

#include <iostream>

using namespace std;

namespace Utilities {
    namespace Enumerations {

             struct Error_Messaging {

             public:
                 inline static const string Header_File_Not_Present = "The header file you are trying to include does not exist";
         };
    }
}

#endif //ARBIE_ERROR_MESSAGING_H
