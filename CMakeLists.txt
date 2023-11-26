cmake_minimum_required(VERSION 3.16.3)
project(Arbie)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-I/usr/include -L/usr/lib -lwiringPi)

include(Findpigpio.cmake)

add_executable(Arbie main.cpp
        Body/Motors/Base/Base_Motor.cpp
        Body/Motors/Base/Base_Motor.h
        Body/Motors/Servo/Servo_Motor.cpp
        Body/Motors/Servo/Servo_Motor.h
        Body/Motors/Utilities/Enumerations.h
        Body/Motors/Utilities/Error_Messaging.h
        Body/Libraries/PCA9685/PCA9685.cpp
        Body/Libraries/PCA9685/PCA9685.h
        OS_Utilities/Logger.cpp
        OS_Utilities/Logger.h
)


