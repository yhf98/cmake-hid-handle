cmake_minimum_required(VERSION 3.0)

project(CmakeHidTest)

# 设置源文件目录
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# 添加源文件
file(GLOB SRC_FILES ${SRC_DIR}/*)

# 添加头文件目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/hidapi/hidapi)

# 添加hidapi动态库

# find_package(hidapi CONFIG REQUIRED)

add_subdirectory(src/hmi)

# 创建可执行文件
add_executable(CmakeHidTest ${SRC_FILES})

# 链接hidapi动态库
# target_link_libraries(CmakeHidTest PRIVATE hidapi::darwin hidapi::hidapi hidapi::include)

# set( PROJECT_LINK_LIBS
#     PRIVATE 
#     hidapi::hidapi 
#     hidapi::winapi 
#     hidapi::include
# )
# target_link_libraries( CmakeHidTest ${PROJECT_LINK_LIBS} )

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/hidapi/windows)
target_link_libraries(CmakeHidTest hmi hidapi.dll)
