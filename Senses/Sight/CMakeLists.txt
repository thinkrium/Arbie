cmake_minimum_required(VERSION 3.16.3)
project(Sight)

set(CMAKE_CXX_STANDARD 17)


include(tflite.cmake)

# For OpenCV
find_package(OpenCV REQUIRED)

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
        ../Base/Processing/Tensorflow/Pipeline/PoseDetectionModel.cpp
        ../Base/Processing/Tensorflow/Pipeline/PoseDetectionModel.h
        ../Base/Processing/Tensorflow/Pipeline/HandLandmarkDetectionModel.cpp
        ../Base/Processing/Tensorflow/Pipeline/HandLandmarkDetectionModel.h
        ../Base/Processing/Tensorflow/Pipeline/ObjectDetectionModel.cpp
        ../Base/Processing/Tensorflow/Pipeline/ObjectDetectionModel.h
        ../Base/Processing/Tensorflow/Pipeline/ModelDetails.cpp
        ../Base/Processing/Tensorflow/Pipeline/ModelDetails.h
        SenseOfSight.cpp
        SenseOfSight.h
        ../Base/Processing/Tensorflow/Pipeline/BoundingBox.cpp
        ../Base/Processing/Tensorflow/Pipeline/BoundingBox.h

)

target_include_directories(Sight PUBLIC ${TFLITE_INC} ${OpenCV_INCLUDE_DIRS})
target_link_libraries(Sight PRIVATE ${TFLITE_LIB}  ${OpenCV_LIBS})
