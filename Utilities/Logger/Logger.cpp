//
// Created by thome on 11/25/2023.
//

#include "Logger.h"

//https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal

namespace Utilities {
    void Logger::Info(string originatingObject, string originatingFunction, string message) {
        string builtMessage = + "[" + originatingObject + "::" + originatingFunction + "]  " + message;
        cout << "\033[1;37m" + builtMessage + "\033[0m\n";

    }

    void Logger::Log(string originatingObject, string originatingFunction, string message) {
        string builtMessage = + "[" + originatingObject + "::" + originatingFunction + "]  " + message;
        cout << "\033[1;37m" + builtMessage +  "\033[0m\n";

    }

    void Logger::Warn(string originatingObject, string originatingFunction, string message) {
        string builtMessage = + "[" + originatingObject + "::" + originatingFunction + "]  " + message;
        cout << "\033[1;33m" + builtMessage +  "\033[0m\n";

    }

    void Logger::Error(string originatingObject, string originatingFunction, string message) {
        string builtMessage = + "[" + originatingObject + "::" + originatingFunction + "]  " + message;
        cout << "\033[1;31m" + builtMessage + "\033[0m\n";

    }

    void Logger::Success(string originatingObject, string originatingFunction, string message) {
        string builtMessage = + "[" + originatingObject + "::" + originatingFunction + "]  " + message;
        cout << "\033[1;32m" + builtMessage + "\033[0m\n";

    }

} // Utilities