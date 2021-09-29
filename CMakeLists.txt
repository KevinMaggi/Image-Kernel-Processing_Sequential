cmake_minimum_required(VERSION 3.20)
project(Image_Kernel_Processing C)

set(CMAKE_C_STANDARD 11)

add_executable(Image_Kernel_Processing main.c Image.h Image.c Utils.h Utils.c stb_image.h stb_image_write.h Kernel.c Kernel.h Processing.c Processing.h)
target_link_libraries(Image_Kernel_Processing m)