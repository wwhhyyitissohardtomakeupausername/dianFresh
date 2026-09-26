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
    src/ItemManager.cpp
    src/POSsystem.cpp
)

add_custom_command(TARGET dian POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/data"
    "$<TARGET_FILE_DIR:dian>/data"
)