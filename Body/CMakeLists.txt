cmake_minimum_required(VERSION 3.16.3)
project(Body)

set(CMAKE_CXX_STANDARD 17)

add_executable(Body main.cpp
        NervousSystem/NervousSystem.cpp
        NervousSystem/NervousSystem.h
        Parts/Joints/Base/BaseJoint.cpp
        Parts/Joints/Base/BaseJoint.h
        Movement/Motors/Base/BaseMotor.cpp
        Movement/Motors/Base/BaseMotor.h
        Movement/Motors/Stepper/StepperMotor.cpp
        Movement/Motors/Stepper/StepperMotor.h
        ../Shared/MovementProfiles.h
        ../Shared/BodyPartProfiles.h
        ../Shared/MotorAxis.h
)
