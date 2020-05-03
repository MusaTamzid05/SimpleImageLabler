#include "labeler.h"
#include "util.h"
#include "const.h"

namespace App {


    Rect* Labeler::rect = nullptr;
    bool Labeler::track_mouse = false;

    Labeler::Labeler(const std::string& image_path , const std::string& window_name):
        window_name(window_name){
            
            src_image= cv::imread(image_path);

            if(src_image.empty()) {
                std::cerr << "Could not read " << image_path << "\n";
                return;
            }

            if(Util::should_resize(src_image))
                cv::resize(src_image , src_image , cv::Size(Const::WIDTH , Const::HEIGHT));

        cv::namedWindow(window_name , cv::WINDOW_NORMAL);
        cv::setMouseCallback(window_name , mouse_callback , nullptr);
    }

    Labeler::~Labeler() {
        cv::destroyWindow(window_name);
    }

    void Labeler::run() {


        if(src_image.empty()) {
            std::cerr << "Valid image is required.\n";
            return;
        }

        bool running = true;
        result_image = src_image.clone();

        while(running) {

           
            draw_rect();
            cv::imshow(window_name , result_image);

            if(cv::waitKey(1) == 27){
                running = false;
            }
        }
    }
    
    
    void Labeler::mouse_callback(int event , int x ,int y , int flags , void* userdata) {

        if(event == cv::EVENT_LBUTTONDOWN) {
            track_mouse = true;
            rect = new Rect(x , y , x ,y);

        }

        if(event == cv::EVENT_LBUTTONUP) {
            if(!track_mouse)
                return;

            rect->x2 = x;
            rect->y2 = y;
            track_mouse = false;
        }

        if(event == cv::EVENT_MOUSEMOVE) {
            if(!track_mouse) 
                return;

            rect->x2 = x;
            rect->y2 = y;
        }
        
    }


    
    void Labeler::draw_rect() {

        if(rect == nullptr) 
            return;

        result_image = src_image.clone();

        cv::rectangle(result_image , cv::Point(rect->x1 , rect->y1) , cv::Point(rect->x2, rect->y2), cv::Scalar(200.0f , 0.f , 0.f));
    }
};
