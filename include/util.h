#ifndef UTIL_H
#define UTIL_H
#include <opencv2/opencv.hpp>


namespace Util {


    void show_image(const std::string& image_path, const std::string window_name = "Window" , bool delay = true);
    void show_image(const cv::Mat& image , const std::string window_name = "Window" , bool delay = true);
    bool should_resize(const cv::Mat& image);
};

#endif
