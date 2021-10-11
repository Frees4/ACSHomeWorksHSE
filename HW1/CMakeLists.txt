cmake_minimum_required(VERSION 3.16)
project(task)

set(CMAKE_CXX_STANDARD 17)

add_executable(task src/main.cpp src/text.cpp src/text.h src/char_encryption.cpp src/char_encryption.h src/shift_encryption.cpp src/shift_encryption.h src/container.cpp src/container.h src/error.h)
