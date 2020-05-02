#include "util.h"
#include "const.h"
#include <iostream>

namespace Util {

    bool should_resize(const cv::Mat& image) {
        return image.size().width > Const::WIDTH || image.size().height > Const::HEIGHT;
    }
};
