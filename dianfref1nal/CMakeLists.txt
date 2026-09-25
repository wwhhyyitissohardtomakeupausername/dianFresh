cmake_minimum_required(VERSION 3.10)
project(DianFresh)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(dian
    src/main.cpp
    src/Item.cpp
    src/Cart.cpp
    src/Sale.cpp
    src/SaleManager.cpp
)

# 如果不需要把 data 目录复制到可执行文件旁边，可以删掉这一段
add_custom_command(TARGET dian POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/data"
    "$<TARGET_FILE_DIR:dian>/data"
)