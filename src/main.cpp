#include "labeler.h"
#include "util.h"


int main(int argc , char** argv) {

    if(argc != 3) {
        std::cerr << "Usage : image_path result_dir\n";
        return -1;
    }

    
    App::Labeler labeler(argv[1]);
    labeler.run(argv[2]);
    

    return 0;
}
