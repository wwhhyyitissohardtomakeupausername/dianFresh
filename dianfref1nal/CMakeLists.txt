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

# 1. 确保 build 目录下有一个 data 文件夹
file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/data")

# 2. 如果 build/data/warehouse.csv 不存在，说明是首次运行或数据被清空
# 这时候才从外层初始备份拷贝过去，以后再也不覆盖
if(NOT EXISTS "${CMAKE_BINARY_DIR}/data/warehouse.csv")
    message(STATUS "Initializing data from external backup...")
    file(COPY "${CMAKE_SOURCE_DIR}/data/warehouse.csv" DESTINATION "${CMAKE_BINARY_DIR}/data")
    # 如果 sales.csv 也要初始化，把下面这行加进 if 里
    file(COPY "${CMAKE_SOURCE_DIR}/data/sales.csv" DESTINATION "${CMAKE_BINARY_DIR}/data")
endif()