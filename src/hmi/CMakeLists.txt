cmake_minimum_required(VERSION 3.0)

project(hmi)

# 添加头文件目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/hidapi/hidapi)

add_library(hmi hmi_config.h hmi_core.cc hmi_core.h hmi_hid.cc hmi_hid.h hmi_packet.cc hmi_packet.h list.c list.h)