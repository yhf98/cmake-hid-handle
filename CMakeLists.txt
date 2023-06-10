cmake_minimum_required(VERSION 3.0)

project(MyProject)

# 设置源文件目录
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# 添加源文件
file(GLOB SRC_FILES ${SRC_DIR}/*.cc)

# 添加头文件目录
include_directories(${SRC_DIR})

# 添加hidapi动态库
find_library(HIDAPI_LIB hidapi)

# 创建可执行文件
add_executable(MyProject ${SRC_FILES})

# 链接hidapi动态库
target_link_libraries(MyProject ${HIDAPI_LIB})
