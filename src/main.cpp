#include "labeler.h"
#include "util.h"


int main(int argc , char** argv) {

    App::Labeler labeler("../test.jpg");
    labeler.run("./results");
    

    return 0;
}
