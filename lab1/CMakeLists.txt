cmake_minimum_required(VERSION 4.2)
project(lab1)

set(CMAKE_CXX_STANDARD 20)
find_package(Eigen3 REQUIRED NO_MODULE)

add_executable(lab1
        src/main.cpp
        src/random_vector.cpp
)
target_include_directories(lab1 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(lab1 Eigen3::Eigen)

