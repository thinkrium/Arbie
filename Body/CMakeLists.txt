cmake_minimum_required(VERSION 3.28)
project(Body)

set(CMAKE_CXX_STANDARD 17)

add_executable(Body main.cpp
        NervousSystem/NervousSystem.cpp
        NervousSystem/NervousSystem.h
        Parts/Joints/Base/BaseJoint.cpp
        Parts/Joints/Base/BaseJoint.h
        Movement/Motors/Base/BaseMotor.cpp
        Movement/Motors/Base/BaseMotor.h
        ../Common/MotorIDs.h)
