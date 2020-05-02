cmake_minimum_required(VERSION 2.8)
project("OpenCV_Project")


SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET( OpenCV_FOUND TRUE )
SET(Source
    src/main.cpp
    src/util.cpp
    src/labeler.cpp
    )
find_package(OpenCV REQUIRED)
add_executable(testas ${Source})


include_directories(include)
target_link_libraries(testas ${OpenCV_LIBS})

