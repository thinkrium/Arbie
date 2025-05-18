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
        Processing/Tensorflow/Pipeline/Models/FaceDetection/FaceDetectionModel.cpp
        Processing/Tensorflow/Pipeline/Models/FaceDetection/FaceDetectionModel.h
        Processing/Tensorflow/Pipeline/Models/FacialLandmarkDetection/FacialLandmarkDetectionModel.cpp
        Processing/Tensorflow/Pipeline/Models/FacialLandmarkDetection/FacialLandmarkDetectionModel.h
        Processing/Tensorflow/Pipeline/Models/PoseDetection/PoseDetectionModel.cpp
        Processing/Tensorflow/Pipeline/Models/PoseDetection/PoseDetectionModel.h
        Processing/Tensorflow/Pipeline/Models/HandLandmarkDetection/HandLandmarkDetectionModel.cpp
        Processing/Tensorflow/Pipeline/Models/HandLandmarkDetection/HandLandmarkDetectionModel.h
        Processing/Tensorflow/Pipeline/Models/ObjectDetection/ObjectDetectionModel.cpp
        Processing/Tensorflow/Pipeline/Models/ObjectDetection/ObjectDetectionModel.h
        ../Base/Processing/Tensorflow/Pipeline/ModelDetails.cpp
        ../Base/Processing/Tensorflow/Pipeline/ModelDetails.h
        SenseOfSight.cpp
        SenseOfSight.h
        ../Base/Processing/Tensorflow/Pipeline/BoundingBox.cpp
        ../Base/Processing/Tensorflow/Pipeline/BoundingBox.h
        ../Base/Output/Smoothing/KalmanSmoothing.cpp
        ../Base/Output/Smoothing/KalmanSmoothing.h

)

target_include_directories(Sight PUBLIC ${TFLITE_INC} ${OpenCV_INCLUDE_DIRS})
target_link_libraries(Sight PRIVATE ${TFLITE_LIB}  ${OpenCV_LIBS})
