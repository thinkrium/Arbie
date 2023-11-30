cmake_minimum_required(VERSION 3.16.3)
project(Arbie)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-I/usr/include -L/usr/lib )

add_executable(Arbie main.cpp
        Body/Motors/Base/Base_Motor.cpp
        Body/Motors/Base/Base_Motor.h
        Body/Motors/Servo/Servo_Motor.cpp
        Body/Motors/Servo/Servo_Motor.h
        Utilities/Logger/Logger.cpp
        Utilities/Logger/Logger.h
        Body/Libraries/PCA9685/PCA9685.cpp
        Body/Libraries/PCA9685/PCA9685.h
        Body/Parts/Base/Base_Body_Part.cpp
        Body/Parts/Base/Base_Body_Part.h
        Body/Definitions.h
        Utilities/Enumerations.h
        Utilities/Error_Messaging.h
        Body/Parts/Shoulder/Shoulder.cpp
        Body/Parts/Shoulder/Shoulder.h
        Body/Axes/Axis.cpp
        Body/Axes/Axis.h
        Body/Parts/Joint/Joint.cpp
        Body/Parts/Joint/Joint.h
        Brain/Functionality/Functionality.cpp
        Brain/Functionality/Functionality.h
        Body/Parts/Elbow/Elbow.cpp
        Body/Parts/Elbow/Elbow.h
        Body/Parts/Arm/Arm.cpp
        Body/Parts/Arm/Arm.h
)


