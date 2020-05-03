#ifndef LABELER_H
#define LABELER_H

#include <string>
#include <opencv2/opencv.hpp>
#include "rect.h"


namespace App {

    class Labeler {

        public:

            Labeler(const std::string& image_path , const std::string& window_name = "Window");
            virtual ~Labeler();

            void run();

        private:

            std::string window_name;
            cv::Mat src_image;
            cv::Mat result_image;

            static void mouse_callback(int event , int x ,int y , int flags , void* userdata);

            static Rect* rect;
            void draw_rect();
            
            static bool track_mouse;


    };
};

#endif
