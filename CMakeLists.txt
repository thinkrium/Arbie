cmake_minimum_required(VERSION 3.26)
project(Arbie)

set(CMAKE_CXX_STANDARD 17)

add_executable(Arbie main.cpp
        Body/Motors/Base/Base.cpp
        Body/Motors/Base/Base.h
        Body/Motors/Servo/Servo.cpp
        Body/Motors/Servo/Servo.h
        Body/Motors/Utilities/Enumerations.h
        Body/Motors/Utilities/Error_Messaging.h
)
