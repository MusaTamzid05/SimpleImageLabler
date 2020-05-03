#include "util.h"
#include "const.h"
#include <iostream>

namespace Util {

    bool should_resize(const cv::Mat& image) {
        return image.size().width > Const::WIDTH || image.size().height > Const::HEIGHT;
    }

    std::vector<std::string> split(const std::string& text , char  delimeter) {


        std::vector<std::string> data;
        std::stringstream ss(text);
        std::string token;

        while(std::getline(ss , token , delimeter))
            data.push_back(token);

        return data;
    }

     void write_file(const std::string& filepath, const std::string& text , bool append){
            
            std::ofstream output_file;
            if(append)
                output_file.open(filepath, std::ios::out | std::ios::app);
            else
                output_file.open(filepath);


            output_file << text;
            output_file.close();
     }
};
