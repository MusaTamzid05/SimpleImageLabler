#ifndef LABELER_H
#define LABELER_H

#include <string>
#include <opencv2/opencv.hpp>


namespace App {

    class Labeler {

        public:

            Labeler(const std::string& image_path , const std::string& window_name = "Window");
            virtual ~Labeler();

            void run();

        private:

            std::string window_name;
            cv::Mat image;

            static void mouse_callback(int event , int x ,int y , int flags , void* userdata);



    };
};

#endif
