//
// Created by thome on 11/25/2023.
//

#ifndef ARBIE_LOGGER_H
#define ARBIE_LOGGER_H

#include "iostream"

using namespace std;

namespace OS_Utilities {

    class Logger {
    public:
        static void Info(string message);
        static void Log(string message);
        static void Success(string message);
        static void Warn(string message);
        static void Error(string message);
    };

} // OS_Utilities

#endif //ARBIE_LOGGER_H
