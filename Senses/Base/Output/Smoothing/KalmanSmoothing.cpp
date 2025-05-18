//
// Created by thom on 5/17/25.
//

#include "KalmanSmoothing.h"

namespace Arbie {
namespace Senses {
namespace Base {
namespace Output {
namespace Smoothing {
    cv::Mat & KalmanSmoothing::get_prediction_matrix() {
        return prediction_matrix;
    }

    void KalmanSmoothing::set_prediction_matrix(cv::Mat prediction_matrix) {
        this->prediction_matrix = std::move(prediction_matrix);
    }

    cv::KalmanFilter & KalmanSmoothing::get_filter() {
        return filter;
    }

    void KalmanSmoothing::set_filter(cv::KalmanFilter filter) {
        this->filter = std::move(filter);
    }

    cv::Mat & KalmanSmoothing::get_state_matrix() {
        return state_matrix;
    }

    void KalmanSmoothing::set_state_matrix(cv::Mat state_matrix) {
        this->state_matrix = std::move(state_matrix);
    }

    cv::Mat & KalmanSmoothing::get_measurement_matrix() {
        return measurement_matrix;
    }

    void KalmanSmoothing::set_measurement_matrix(cv::Mat measurement_matrix) {
        this->measurement_matrix = std::move(measurement_matrix);
    }

    bool & KalmanSmoothing::is_initialized() {
        return initialized;
    }

    void KalmanSmoothing::set_initialized(bool initialized) {
        this->initialized = initialized;
    }

    void KalmanSmoothing::update_kalman_prediction(int x, int y, int width, int height) {

        if (!this->is_initialized()) {
            // Initialize state on first detection
            this->get_filter().statePost.at<float>(0) = x;
            this->get_filter().statePost.at<float>(1) = y;
            this->get_filter().statePost.at<float>(2) = width;
            this->get_filter().statePost.at<float>(3) = height;
            this->get_filter().statePost.at<float>(4) = 0;
            this->get_filter().statePost.at<float>(5) = 0;
            this->get_filter().statePost.at<float>(6) = 0;
            this->get_filter().statePost.at<float>(7) = 0;
            this->set_initialized( true);
        }

        this->get_filter().correct(this->get_measurement_matrix()); // Update with measurement

        cv::Mat prediction = this->get_filter().predict();


        this->set_prediction_matrix(prediction);


    }

    KalmanSmoothing::KalmanSmoothing() {

        cv::KalmanFilter kf(8, 4); // 8 states, 4 measurements
        cv::Mat state(8, 1, CV_32F);  // [x, y, w, h, dx, dy, dw, dh]
        cv::Mat meas(4, 1, CV_32F);   // [z_x, z_y, z_w, z_h]

        // Transition matrix (how state evolves)
        kf.transitionMatrix = (cv::Mat_<float>(8, 8) <<
            1,0,0,0, 1,0,0,0,
            0,1,0,0, 0,1,0,0,
            0,0,1,0, 0,0,1,0,
            0,0,0,1, 0,0,0,1,
            0,0,0,0, 1,0,0,0,
            0,0,0,0, 0,1,0,0,
            0,0,0,0, 0,0,1,0,
            0,0,0,0, 0,0,0,1
        );

        // Measurement matrix
        kf.measurementMatrix = cv::Mat::zeros(4, 8, CV_32F);
        kf.measurementMatrix.at<float>(0,0) = 1.0f;
        kf.measurementMatrix.at<float>(1,1) = 1.0f;
        kf.measurementMatrix.at<float>(2,2) = 1.0f;
        kf.measurementMatrix.at<float>(3,3) = 1.0f;

        // Initialize other matrices
        cv::setIdentity(kf.processNoiseCov, cv::Scalar::all(1e-2));
        cv::setIdentity(kf.measurementNoiseCov, cv::Scalar::all(1e-1));
        cv::setIdentity(kf.errorCovPost, cv::Scalar::all(1));

        this->set_filter(kf);
        this->set_measurement_matrix(measurement_matrix);

        // Initialize state
        this->set_initialized( false );

    }
} // Smoothing
} // Output
} // Base
} // Senses
} // Arbie