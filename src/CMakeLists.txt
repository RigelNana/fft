cmake_minimum_required(VERSION 3.30)
set(CMAKE_CXX_STANDARD 14)


add_executable(main main.cpp
        fft.h
        fft.cpp
        ifft.h
        ifft.cpp
        conv.cpp
        conv.h)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
find_package(Eigen3 REQUIRED CONFIG)
target_link_libraries(main Eigen3::Eigen)