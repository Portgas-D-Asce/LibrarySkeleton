cmake_minimum_required(VERSION 3.15)
project(consumer LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)


list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../output/${CMAKE_BUILD_TYPE}")
find_package(mylib 0.1 REQUIRED)

add_executable(consumer main.cpp)                          # ← 缺了这行
target_link_libraries(consumer PRIVATE mylib::mylib)
