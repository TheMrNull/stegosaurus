cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 17) #needed for filesystem library
project(stegosaurus)

add_executable(stegosaurus main.cpp functions.cpp)
