//
// Created by thome on 11/25/2023.
//

#ifndef ARBIE_LOGGER_H
#define ARBIE_LOGGER_H

#include "iostream"

using namespace std;

namespace Utilities {

    class Logger {
    public:
        static void Info(string originatingObject, string originatingFunction, string message);
        static void Log(string originatingObject, string originatingFunction, string message);
        static void Success(string originatingObject, string originatingFunction, string message);
        static void Warn(string originatingObject, string originatingFunction, string message);
        static void Error(string originatingObject, string originatingFunction, string message);
    };

} // Utilities

#endif //ARBIE_LOGGER_H
