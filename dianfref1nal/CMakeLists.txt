cmake_minimum_required(VERSION 3.10)        #最低版本号
project(DianFresh)        #项目名
set(CMAKE_CXX_STANDARD 17)      #用c++11标准来编译
set(CMAKE_CXX_STANDARD_REQUIRED ON)     #强制要求编译器支持
include_directories(${CMAKE_SOURCE_DIR}/include)        #去include里面找头文件
add_executable(dian
    src/main.cpp 
    src/Item.cpp)      #可执行文件名,源文件1,2......