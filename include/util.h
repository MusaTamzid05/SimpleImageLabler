#ifndef UTIL_H
#define UTIL_H
#include <opencv2/opencv.hpp>


namespace Util {
    bool should_resize(const cv::Mat& image);
    std::vector<std::string> split(const std::string& text , char  delimeter);
    void write_file(const std::string& filepath, const std::string& text , bool append = false);
    std::vector<std::string> get_files(const std::string& path);
};

#endif
