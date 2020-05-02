#include "util.h"
#include <iostream>

namespace Util {

    void show_image(const std::string& image_path, const std::string window_name , bool delay ) {

        cv::Mat image = cv::imread(image_path);

        if(image.empty()) {
            std::cerr << "Could not load " << image_path << "\n";
            return;
        }

        show_image(image , window_name , delay);

    }


    void show_image(const cv::Mat& image , const std::string window_name  , bool delay) {

        cv::namedWindow(window_name , cv::WINDOW_NORMAL);
        cv::imshow(window_name , image);

        if(delay)
            cv::waitKey(0);
    }
};
