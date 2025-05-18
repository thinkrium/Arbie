//
// Created by thom on 5/16/25.
//

#include <opencv2/opencv.hpp>
#include "SenseOfSight.h"

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
        }
    }

     SenseOfSight::SenseOfSight() {
        Pipeline::Pipe temporary_pipe("../../Sight/Assets/TFliteModel/face_detection_short_range.tflite");
        face_detection_pipe = temporary_pipe;
        face_detection_pipe.PreparePipeLineInterpreter();

    }

} // Senses
} // Arbie