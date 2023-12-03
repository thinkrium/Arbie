//
// Created by thome on 11/28/2023.
//

#ifndef ARBIE_ERROR_MESSAGING_H
#define ARBIE_ERROR_MESSAGING_H

#include <iostream>

using namespace std;

namespace Utilities {
    namespace Enumerations {

        struct Error_Messaging {

        public:

            inline static const string No_Error = "No error found";
            inline static const string Object_Initiated_Successfully = "The object was initiated [and/or] values were set successfully";
            inline static const string Object_Failed_To_Initiated = "The object was failed in its attempt to initiate [and/or] set its values";
            inline static const string Generic_Error = "There was a generic error";
            inline static const string Axis_General_Failure = "There was a generic failure in the servo motor";
            inline static const string Axis_Init_Succeeded = "The values of the axis have been set successfully";
            inline static const string Servo_Motor_General_Failure = "There was a generic failure in the axis";
            inline static const string Servo_Motor_Init_Succeeded = "The values of the servo motor have been set successfully";
            inline static const string Header_File_Not_Present = "The header file you are trying to include does not exist";
            inline static const string Outside_Servo_PWM_Range = "The system is trying to turn a servo motor outside its allowable range";
        };
    }
}

#endif //ARBIE_ERROR_MESSAGING_H
