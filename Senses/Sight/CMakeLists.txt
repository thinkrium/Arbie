cmake_minimum_required(VERSION 3.16.3)
project(Sight)

set(CMAKE_CXX_STANDARD 17)

add_executable( Sight
        ../Base/Sense/BaseSense.cpp
        ../Base/Sense/BaseSense.h
        main.cpp
        ../../Shared/ErrorCodes.h)
