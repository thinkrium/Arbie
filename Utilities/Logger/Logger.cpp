//
// Created by thome on 11/25/2023.
//

#include "Logger.h"

//https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal

namespace OS_Utilities {
    void Logger::Info(string message) {
        cout << "\033[1;37m" + message + "\033[0m\n";

    }

    void Logger::Log(string message) {
        cout << "\033[1;37m" + message +  "\033[0m\n";

    }

    void Logger::Warn(string message) {
        cout << "\033[1;33m" + message +  "\033[0m\n";

    }

    void Logger::Error(string message) {
        cout << "\033[1;31m" + message + "\033[0m\n";

    }

    void Logger::Success(string message) {
        cout << "\033[1;32m" + message + "\033[0m\n";

    }

} // Utilities