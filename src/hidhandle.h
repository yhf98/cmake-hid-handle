/*
 * @Author: yaohengfeng 1921934563@qq.com
 * @Date: 2023-01-13 10:46:10
 * @LastEditors: yaohengfeng 1921934563@qq.com
 * @LastEditTime: 2023-06-09 17:57:54
 * @FilePath: \hid-handle\src\hidhandle.h
 * @Description: hidhandle.h
 */
#ifndef HIDHANDLE_H
#define HIDHANDLE_H

#include <vector>
#include "hmi/hmi_core.h"

using namespace std;

int hid_write_file_handle(const char *full_path, const char *file_name, unsigned int file_type);
#endif