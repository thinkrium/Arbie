 //
// Created by thom on 5/9/25.
//

#include "SenseOfSight.h"
int main( ) {


    Arbie::Senses::SenseOfSight sense_of_sight;

    sense_of_sight.process();

    return 0;
}
// #include "tensorflow/lite/interpreter.h"
// #include "tensorflow/lite/kernels/register.h"
// #include "tensorflow/lite/model.h"
// #include <opencv2/opencv.hpp>
//
// #include <algorithm>
//
// #include <iostream>
// #include <memory>
//
// #include <vector>
//
// struct BoundingBox
// {
//     int cx;
//     int cy;
//     int x;
//     int y;
//     int w;
//     int h;
//     float score;
//     int class_id;
// };
//
// // dst[i * img_channel + c] = (src[i * img_channel + c] - input_tensor_info.normalize.mean[c]) * input_tensor_info.normalize.norm[c];
// //
// void CreateAnchor( std::vector<std::pair<float, float>>& anchor_list,int width = 128, int height = 128)
// {
//
//
//     std::array<std::pair<int32_t, int32_t>, 2> kAnchorGridSize = { std::pair<int32_t, int32_t>(16, 16), std::pair < int32_t, int32_t>(8, 8) };
//     std::array<int32_t, 2> kAnchorNum = { 2, 6 };
//
//
//
//     for (size_t i = 0; i < kAnchorGridSize.size(); i++) {
//         int32_t grid_cols = kAnchorGridSize[i].first;
//         int32_t grid_rows = kAnchorGridSize[i].second;
//         float  stride_x = static_cast<float>(width) / grid_cols;
//         float  stride_y = static_cast<float>(height) / grid_rows;
//         int anchor_num = kAnchorNum[i];
//
//         std::pair<float, float> anchor;
//         for (int grid_y = 0; grid_y < grid_rows; grid_y++) {
//             anchor.second = stride_y * (grid_y + 0.5f);
//             for (int grid_x = 0; grid_x < grid_cols; grid_x++) {
//                 anchor.first = stride_x * (grid_x + 0.5f);
//                 for (int n = 0; n < anchor_num; n++) {
//                     anchor_list.push_back(anchor);
//                 }
//             }
//         }
//     }
//
// }
//
//
// float Dequantize(uint8_t value, float scale, int zero_point) {
//     return scale * (static_cast<int>(value) - zero_point);
// }
//
// int main() {
//
// /////////////////////////////////////////////////////////////////////////////////////////////////////// /
// ///////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ////////////////////////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////////////
//     cv::KalmanFilter kf(8, 4); // 8 states, 4 measurements
//     cv::Mat state(8, 1, CV_32F);  // [x, y, w, h, dx, dy, dw, dh]
//     cv::Mat meas(4, 1, CV_32F);   // [z_x, z_y, z_w, z_h]
//
//     // Transition matrix (how state evolves)
//     kf.transitionMatrix = (cv::Mat_<float>(8, 8) <<
//         1,0,0,0, 1,0,0,0,
//         0,1,0,0, 0,1,0,0,
//         0,0,1,0, 0,0,1,0,
//         0,0,0,1, 0,0,0,1,
//         0,0,0,0, 1,0,0,0,
//         0,0,0,0, 0,1,0,0,
//         0,0,0,0, 0,0,1,0,
//         0,0,0,0, 0,0,0,1
//     );
//
//     // Measurement matrix
//     kf.measurementMatrix = cv::Mat::zeros(4, 8, CV_32F);
//     kf.measurementMatrix.at<float>(0,0) = 1.0f;
//     kf.measurementMatrix.at<float>(1,1) = 1.0f;
//     kf.measurementMatrix.at<float>(2,2) = 1.0f;
//     kf.measurementMatrix.at<float>(3,3) = 1.0f;
//
//     // Initialize other matrices
//     cv::setIdentity(kf.processNoiseCov, cv::Scalar::all(1e-2));
//     cv::setIdentity(kf.measurementNoiseCov, cv::Scalar::all(1e-1));
//     cv::setIdentity(kf.errorCovPost, cv::Scalar::all(1));
//
//     // Initialize state
//     bool initialized = false;
//  /////////////////////////////////////////////////////////////////////////////////////////////////////
//  ///////////////////////////////////////////////////////////////////////////////////////////////////
//
//                 const char* detection_model_path = "/home/thom/Development/Robotics/Arbie/OS/SourceCode/Arbie/Senses/Sight/Assets/TFliteModel/face_detection_short_range.tflite";
//                 // const char* detection_model_path = "../face_detection_front.tflite";
//
//     // Load TFLite model
//     auto detection_model = tflite::FlatBufferModel::BuildFromFile(detection_model_path);
//     tflite::ops::builtin::BuiltinOpResolver detection_resolver;
//     std::unique_ptr<tflite::Interpreter> detection_interpreter;
//
//     tflite::InterpreterBuilder(*detection_model, detection_resolver)(&detection_interpreter);
//     detection_interpreter->AllocateTensors();
//
//     // Get model input details
//     int detection_input = detection_interpreter->inputs()[0];
//     TfLiteIntArray* detection_dims = detection_interpreter->tensor(detection_input)->dims;
//     int detection_height = detection_dims->data[1];
//     int detection_width = detection_dims->data[2];
//     int detection_channels = detection_dims->data[3];
//
//     std::cout << "Expecting input shape: " << detection_height << "x" << detection_width << "x" << detection_channels << "\n";
//
//     std::vector<std::pair<float, float>> detection_anchor_list;
//     CreateAnchor( detection_anchor_list );
//
//
//     /////////////////////////////////////////////////////////////////////////////////////////////////0
//     //////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//     // Open webcam
//     cv::VideoCapture cap(0);
//     if (!cap.isOpened()) {
//         std::cerr << "Cannot open webcam\n";
//         return 1;
//     }
//
//     cv::Mat frame;
//     while (true) {
//         cap >> frame;
//         if (frame.empty()) break;
//         cv::flip(frame, frame, 1);
//
//
//         /////////////////////////////////////////////////////////////////////////////////////////////
//         ////////////////////////////////////////////////////////////////////////////////////////////
//
//         // Resize and convert to float
//         cv::Mat detection_resized, detection_float_img;
//         cv::resize(frame, detection_resized, cv::Size(detection_width, detection_height));
//         cv::cvtColor(detection_resized, detection_resized, cv::COLOR_BGR2RGB);
//
//         detection_resized.convertTo(detection_float_img, CV_32FC3, 1.0f / 255.0f, 0.0f ); // Normalize
//
//         // Copy to input tensor
//         float* detection_input_tensor = detection_interpreter->input_tensor(0)->data.f;
//         std::memcpy(detection_input_tensor, detection_float_img.data, detection_height * detection_width * detection_channels * sizeof(float));
//
//         // Run inference
//         if (detection_interpreter->Invoke() != kTfLiteOk) {
//             std::cerr << "Failed to invoke\n";
//             continue;
//         }
//
//
//         TfLiteTensor* detection_scores_tensor = detection_interpreter->tensor(detection_interpreter->outputs()[1]);
//         TfLiteTensor* detection_boxes_tensor = detection_interpreter->tensor(detection_interpreter->outputs()[0]);
//
//         float* detection_scores = detection_scores_tensor->data.f;
//         float* detection_boxes = detection_boxes_tensor->data.f;
//
//         std::vector<float> detection_test = {};
//         std::vector<BoundingBox> detection_test2 = {};
//
//         int detection_num_detections = detection_scores_tensor->dims->data[1];
//
//         float scale ;
//
//         for (int i = 0; i < detection_num_detections; ++i) {
//             float detection_score = detection_scores[i];
//             if (detection_score > 0.85f) {
//
//
//
//                 int32_t detection_index_regressor = i * 16;
//
//                 float cx0 = detection_boxes[detection_index_regressor + 0];
//                 float cy0 = detection_boxes[detection_index_regressor + 1];
//
//                 float cx = cx0  + detection_anchor_list[i].first;
//                 float cy = cy0 + detection_anchor_list[i].second;
//
//                 float w0 = detection_boxes[detection_index_regressor + 2];
//                 float h0 = detection_boxes[detection_index_regressor + 3];
//
//                 float rel_pos_x = static_cast<float>(frame.cols) / detection_width;
//                 float rel_pos_y = static_cast<float>(frame.rows) / detection_height;
//
//
//                 scale = 1.5; //std::max(scale_x, scale_y);
//
//                 // int x = static_cast<int>((cx - w0 / 2) * scale_x);
//                 // int y = static_cast<int>((cy - h0 / 2) * scale_y);
//                 // int w = static_cast<int>(w0 * scale_x );
//                 // int h = static_cast<int>(h0 * scale_y * 1.25 );
//
//
//
//                 int x = static_cast<int>((cx - w0 * scale   / 2 ) * rel_pos_x);
//                 int y = static_cast<int>((cy - h0 * scale   / 2 ) * rel_pos_y);
//                 int w = static_cast<int>(w0 * rel_pos_x * scale);
//                 int h = static_cast<int>(h0 * rel_pos_y  * scale);
//
//                 if (w > h) {h = w;}
//                 else if (w < h) {w = h;}
//
//
//                     detection_test2.push_back({cx,cy, x, y, w, h, detection_score, i});
//
//
//             }
//         }
//
//         std::sort(detection_test2.begin(), detection_test2.end(), [](const BoundingBox& a, const BoundingBox& b) {
//             return a.score > b.score;
//         });
//
//
//         if (detection_test2.empty()) {
//             std::cout << "No detection\n";
//             continue;
//         }
//
//         BoundingBox bbox = detection_test2.at(0);
//
//         if (detection_test2.size() > 1) {
//
//             BoundingBox bbox2 = detection_test2.at(1);
//
//
//             //  // Draw bounding box
//             cv::rectangle(frame, cv::Point(bbox2.x, bbox2.y),
//             cv::Point(bbox2.x + bbox2.w, bbox2.y + bbox2.h),
//             cv::Scalar(255, 0, 0), 2);
//         }
//
//         detection_test2.clear();
//         // std::cout << "Box: " << bbox.class_id << " Score: " << bbox.score << " x0: " << bbox.x << " y0: " << bbox.y << " w: " << bbox.w << " h: " << bbox.h << std::endl;
// ///////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////////////////
//
//         // if (detected) {
//             // Detected bounding box
//             float x = bbox.x + bbox.w / 2.0;
//             float y = bbox.y + bbox.h  / 2.0;
//             float w = bbox.w ;
//             float h = bbox.h ;
//
//             meas.at<float>(0) = x;
//             meas.at<float>(1) = y;
//             meas.at<float>(2) = w;
//             meas.at<float>(3) = h;
//
//             if (!initialized) {
//                 // Initialize state on first detection
//                 kf.statePost.at<float>(0) = x;
//                 kf.statePost.at<float>(1) = y;
//                 kf.statePost.at<float>(2) = w;
//                 kf.statePost.at<float>(3) = h;
//                 kf.statePost.at<float>(4) = 0;
//                 kf.statePost.at<float>(5) = 0;
//                 kf.statePost.at<float>(6) = 0;
//                 kf.statePost.at<float>(7) = 0;
//                 initialized = true;
//             }
//
//             kf.correct(meas); // Update with measurement
//         // }
//
//         cv::Mat prediction = kf.predict();
//         float pred_x = prediction.at<float>(0);
//         float pred_y = prediction.at<float>(1);
//         float pred_w = prediction.at<float>(2);
//         float pred_h = prediction.at<float>(3);
//
//
//
//     if ( initialized && pred_x > 0 && pred_y > 0 && pred_w > 0 && pred_h > 0 ) {
//         bbox.x = static_cast<int>(pred_x - pred_w / 2);
//         bbox.y = static_cast<int>(pred_y - pred_h / 2);
//         bbox.w = static_cast<int>(pred_w);
//         bbox.h = static_cast<int>(pred_h);
//     }
// // // //////////////////////////////////////////////////////////////////////////////////////////////////////
// // // ///////////////////////////////////////////////////////////////////////////////////////////////////
//
//        if (
//         bbox.x <= 0 || bbox.y <= 0 ||
//         bbox.x + bbox.w >= frame.cols ||
//         bbox.y + bbox.h >= frame.rows ||
//         bbox.w <= 0 || bbox.h <= 0) {
//             initialized = false; // Reset if out of bounds
//             continue;
//         }
//
//          // Draw bounding box
//          cv::rectangle(frame, cv::Point(bbox.x, bbox.y),
//          cv::Point(bbox.x + bbox.w, bbox.y + bbox.h),
//          cv::Scalar(255, 0, 0), 2);
//
//
//
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//          cv::imshow("Test", frame);
//
//          if (cv::waitKey(1) == 27) break;
//     }
//
//
//     return 0;
// }
