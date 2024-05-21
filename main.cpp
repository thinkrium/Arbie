#include "Brain/Activity/Activity.h"

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/dnn.hpp"

using namespace cv;
using namespace cv::dnn;

using namespace Brain::Activity;

int main() {

    Mat frame;

    Brain::Activity::Activity::Run();

    return 0;
}
