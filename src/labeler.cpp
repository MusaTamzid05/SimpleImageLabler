#include "labeler.h"
#include "util.h"
#include "const.h"

namespace App {

    
    Labeler::Labeler(const std::string& image_path , const std::string& window_name):
        window_name(window_name){
            
            image = cv::imread(image_path);

            if(image.empty()) {
                std::cerr << "Could not read " << image_path << "\n";
                return;
            }

            if(Util::should_resize(image))
                cv::resize(image , image , cv::Size(Const::WIDTH , Const::HEIGHT));

        cv::namedWindow(window_name , cv::WINDOW_NORMAL);
        cv::setMouseCallback(window_name , mouse_callback , nullptr);
    }

    Labeler::~Labeler() {
        cv::destroyWindow(window_name);
    }

    void Labeler::run() {


        if(image.empty()) {
            std::cerr << "Valid image is required.\n";
            return;
        }

        bool running = true;

        while(running) {

            
            cv::imshow(window_name , image);

            if(cv::waitKey(0) == 27){
                running = false;
            }
        }
    }
    
    
    void Labeler::mouse_callback(int event , int x ,int y , int flags , void* userdata) {

        if(event == cv::EVENT_LBUTTONDOWN) {
            std::cout << "mouse button down.\n";
        }



        if(event == cv::EVENT_LBUTTONUP) {
            std::cout << "mouse button up.\n";
        }
    }
};
