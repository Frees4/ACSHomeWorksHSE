cmake_minimum_required(VERSION 3.16)
project(HW5)

set(CMAKE_CXX_STANDARD 17)

add_executable(HW5 main.cpp)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(HW5 Threads::Threads)
