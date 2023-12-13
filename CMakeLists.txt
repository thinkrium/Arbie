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

        Brain/Activity/Activity.cpp
        Brain/Activity/Activity.h
        Body/Parts/Elbow/Elbow.cpp
        Body/Parts/Elbow/Elbow.h
        Body/Parts/Arm/Arm.cpp
        Body/Parts/Arm/Arm.h
        Body/Whole_Body/Whole_Body.cpp
        Body/Whole_Body/Whole_Body.h
        Body/Parts/Leg/Leg.cpp
        Body/Parts/Leg/Leg.h
        Body/Parts/Knee/Knee.cpp
        Body/Parts/Knee/Knee.h
        Brain/Processes/Movement/Movement.cpp
        Brain/Processes/Movement/Movement.h
        Brain/Processes/Base/Base_Process.cpp
        Brain/Processes/Base/Base_Process.h
        Brain/CoreTechs/CoreTechs.h
        Brain/CoreTechs/CoreTechs.cpp
        Body/Parts/Wrist/Wrist.cpp
        Body/Parts/Wrist/Wrist.h
        Utilities/Pinouts/Arm_Pinout/Arm_Pinout.cpp
        Utilities/Pinouts/Arm_Pinout/Arm_Pinout.h
        Body/Parts/Joints/Base_Joint/Base_Joint.cpp
        Body/Parts/Joints/Base_Joint/Base_Joint.h
        Body/Parts/Joints/Arm_Joint/Arm_Joint.cpp
        Body/Parts/Joints/Arm_Joint/Arm_Joint.h
        Brain/Senses/Console_Input/Console_Input.cpp
        Brain/Senses/Console_Input/Console_Input.h
        Body/Parts/Bones/Bone.cpp
        Body/Parts/Bones/Bone.h
)


set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(Arbie PRIVATE Threads::Threads)

