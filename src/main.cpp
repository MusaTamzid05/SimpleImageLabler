#include "labeler.h"
#include "util.h"

#include <boost/filesystem.hpp>


std::vector<std::string> get_image_paths(const std::string& path) {


    if(!boost::filesystem::is_directory(path)) {
        std::vector<std::string> paths;
        paths.push_back(path);
        return paths;
    }

    return Util::get_files(path);
}

int main(int argc , char** argv) {

    if(argc != 3) {
        std::cerr << "Usage : image_path/image_dir result_dir\n";
        return -1;
    }


    std::vector<std::string> paths = get_image_paths(argv[1]);
    App::Labeler labeler;

    for(std::string path : paths)
        labeler.run(path , argv[2]);
    

    return 0;
}
