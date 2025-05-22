//
// Created by thom on 5/17/25.
//


#include <opencv2/core.hpp>
#include <opencv2/video/tracking.hpp>

#ifndef KALMANSMOOTHING_H
#define KALMANSMOOTHING_H

namespace Arbie {
namespace Senses {
namespace Base {
namespace Output {
namespace Smoothing {

class KalmanSmoothing {

    cv::KalmanFilter filter;
    cv::Mat state_matrix;
    cv::Mat measurement_matrix;

    cv::Mat prediction_matrix;


    bool initialized;

public:

    cv::Mat & get_prediction_matrix();

    void set_prediction_matrix(cv::Mat prediction_matrix);

    cv::KalmanFilter & get_filter();

    void set_filter(cv::KalmanFilter filter);

    cv::Mat & get_state_matrix();

    void set_state_matrix(cv::Mat state_matrix);

    cv::Mat & get_measurement_matrix();

    void set_measurement_matrix(cv::Mat measurement_matrix);

    bool & is_initialized();

    void set_initialized(bool initialized);

    void update_kalman_prediction(int x, int y, int width, int height);

    KalmanSmoothing();

    ~KalmanSmoothing() = default;
};

} // Smoothing
} // Output
} // Base
} // Senses
} // Arbie

#endif //KALMANSMOOTHING_H
