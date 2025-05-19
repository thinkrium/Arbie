//
// Created by thom on 5/16/25.
//

#include <opencv2/opencv.hpp>
#include "SenseOfSight.h"

#include "Processing/Tensorflow/Pipeline/Models/FaceDetection/FaceDetectionModel.h"

namespace Arbie {
namespace Senses {

    void SenseOfSight::process() {

        cv::VideoCapture cap(0);

        if (!cap.isOpened()) {
            std::cerr << "Cannot open webcam\n";
            return;
        }

        cv::Mat frame;
        while (true) {
            cap >> frame;
            if (frame.empty()) break;
            cv::flip(frame, frame, 1);

            // Resize and convert to float
            cv::Mat resized_img, float_img;
            cv::cvtColor(resized_img, resized_img, cv::COLOR_BGR2RGB);

            resized_img = face_detection_pipe.resizeImage(frame, resized_img);

            resized_img.convertTo( float_img, CV_32FC3, 1.0f / 255.0f, 0.0f ); // Normalize

            face_detection_pipe.initialize_pipeline();

            face_detection_pipe.preprocess_pipeline();

            for (int i = 0; i < 468; i++) {
                face_detection_pipe.process_pipeline(i);
            }

            face_detection_pipe.post_process_pipeline();

            // face_detection_pipe.get_ai_model().DrawDetection(frame);
        }

    }

     SenseOfSight::SenseOfSight() {
        Pipeline::Pipe temporary_pipe ;
        Pipeline::FaceDetectionModel temporary_face_detection_model;

        temporary_face_detection_model.set_model_path("../../Sight/Assets/TFliteModel/face_detection_short_range.tflite");
        temporary_pipe.set_ai_model(temporary_face_detection_model);

        face_detection_pipe = temporary_pipe;
        face_detection_pipe.PreparePipeLineInterpreter();

    }

} // Senses
} // Arbie