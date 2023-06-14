cmake_minimum_required(VERSION 3.0)

project(CmakeHidTest)

set (CMAKE_C_COMPILER "/usr/bin/gcc")
set (CMAKE_CXX_COMPILER "/usr/bin/g++")

# 设置源文件目录
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# 指定为C++11 版本
# set(CMAKE_CXX_STANDARD 11)
# 设置指定C++编译器版本。
# include(CheckCXXCompilerFlag)
# CHECK_CXX_COMPILER_FLAG("-std=c++17" COMPILER_SUPPORTS_CXX11)
# CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
# if(COMPILER_SUPPORTS_CXX11)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17") # set C++ 11
# # set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -std=c99")
# elseif(COMPILER_SUPPORTS_CXX0X)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
# message( STATUS "The comipler ${CMAKE_CXX_COMIPLER} has no C++ 17 suport. Please use a different C++ comipler.")
# endif()

# 添加源文件
file(GLOB SRC_FILES ${SRC_DIR}/*)

# 添加头文件目录
include_directories(${SRC_DIR}/hmi)

# 添加hidapi动态库
# find_library(HIDAPI_LIB hidapi)

find_package(hidapi CONFIG REQUIRED)

# 创建可执行文件
add_executable(CmakeHidTest ${SRC_FILES})

# 链接hidapi动态库
# target_link_libraries(MyProject ${HIDAPI_LIB})

# target_link_libraries(CmakeHidTest PRIVATE hidapi::darwin hidapi::hidapi hidapi::include)

set( PROJECT_LINK_LIBS
    PRIVATE 
    hidapi::darwin 
    hidapi::hidapi 
    hidapi::include
)
target_link_libraries( CmakeHidTest ${PROJECT_LINK_LIBS} )
