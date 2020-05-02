#include "labeler.h"
#include "util.h"

namespace App {

    
    Labeler::Labeler(const std::string& image_path , const std::string& window_name):
        window_name(window_name){
            
            image = cv::imread(image_path);

            if(image.empty()) {
                std::cerr << "Could not read " << image_path << "\n";
                return;
            }

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

            Util::show_image(image , "Window" , false);

            if(cv::waitKey(0) == 27){
                running = false;
            }
        }
    }

};
