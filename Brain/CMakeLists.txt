cmake_minimum_required(VERSION 3.28)
project(Brain)

set(CMAKE_CXX_STANDARD 17)

add_executable(Brain main.cpp
        NervousSystem/NervousSystem.h
        NervousSystem/NervousSystem.cpp
        NervousSystem/MessageObjects/MessageObject/BaseMessageObject.cpp
        NervousSystem/MessageObjects/MessageObject/BaseMessageObject.h
        NervousSystem/MessageObjects/Movement/MovementMessageObject.cpp
        NervousSystem/MessageObjects/Movement/MovementMessageObject.h)
