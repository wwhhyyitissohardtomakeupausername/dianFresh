cmake_minimum_required(VERSION 3.10)        #最低版本号
project(DianFresh)        #项目名
set(CMAKE_CXX_STANDARD 17)      #用c++11标准来编译
set(CMAKE_CXX_STANDARD_REQUIRED ON)     #强制要求编译器支持
include_directories(${CMAKE_SOURCE_DIR}/include)        #去include里面找头文件
add_executable(dian
    src/main.cpp 
    src/Item.cpp
    src/Cart.cpp
    src/Sale.cpp
    src/SaleManager.cpp)      #可执行文件名,源文件1,2......
add_custom_command(TARGET dian POST_BUILD       #添加一个自定义命令,指定这个命令和dian绑定,再dian编译完成之后进行
    COMMAND ${CMAKE_COMMMAND} -E copy_directory     #执行指令,指向CMake可执行程序本身的路径,工具模式,复制整个文件夹
    "${CMAKE_SOURCE_DIR}/data"      #指向顶层,拼接data
    "$<TARGET_FILE_DIR:dian>/data"      #构建时动态获取dian这个目标的可执行文件所在的目录路径,在这个目录下拼一个子文件夹data
)       #注意,这个过程是单向的,可以在原data里面放初始数据