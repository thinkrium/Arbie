cmake_minimum_required(VERSION 3.16.3)
project(Sight)

set(CMAKE_CXX_STANDARD 17)

include(tflite.cmake)

add_executable( Sight
        ../Base/Sense/BaseSense.cpp
        ../Base/Sense/BaseSense.h
        main.cpp
        ../../Shared/ErrorCodes.h
        ../Base/Processing/Tensorflow/Pipeline/Pipe.cpp
        ../Base/Processing/Tensorflow/Pipeline/Pipe.h
        ../Base/Processing/Tensorflow/Pipeline/Model.cpp
        ../Base/Processing/Tensorflow/Pipeline/Model.h
        ../Base/Processing/Tensorflow/Pipeline/FaceDetectionModel.cpp
        ../Base/Processing/Tensorflow/Pipeline/FaceDetectionModel.h
        ../Base/Processing/Tensorflow/Pipeline/FacialLandmarkDetectionModel.cpp
        ../Base/Processing/Tensorflow/Pipeline/FacialLandmarkDetectionModel.h

)

target_include_directories(Sight PUBLIC ${TFLITE_INC})
target_link_libraries(Sight PRIVATE ${TFLITE_LIB})
