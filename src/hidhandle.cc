/*
 * @Author: yaohengfeng 1921934563@qq.com
 * @Date: 2023-01-13 10:45:03
 * @LastEditors: yaohengfeng 1921934563@qq.com
 * @LastEditTime: 2023-06-09 18:36:20
 * @FilePath: \hid-handle\src\hidhandle.cc
 * @Description: hidhandle.cc
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../hidapi/hidapi/hidapi.h"
#include <vector>

#include "hmi/hmi_hid.h"
#include "hmi/hmi_core.h"

using namespace std;

// **************************************************************************************************************

hid_device *hid_handle = NULL;

wchar_t manufact[1024] = {0};
wchar_t product[1024] = {0};
wchar_t serial_num[1024] = {0};
wchar_t indexed[1024] = {0};

int hid_handle_init()
{
	int string_index = 1;

	if (hid_handle == NULL)
	{
		hid_init();
		hid_handle = hid_open(0x264a, 0x232a, NULL);

		hid_set_nonblocking(hid_handle, 0);

		hid_get_manufacturer_string(hid_handle, manufact, sizeof(manufact));
		printf("manufact     = %ls\n", manufact);
		hid_get_product_string(hid_handle, product, sizeof(product));
		printf("product      = %ls\n", product);
		hid_get_serial_number_string(hid_handle, serial_num, sizeof(serial_num));
		printf("serial_num   = %ls\n", serial_num);
		hid_get_indexed_string(hid_handle, string_index, indexed, sizeof(indexed));
		printf("indexed      = %ls\n", indexed);
	}
	else
	{
		printf("HID Driver was opened!\n");
	}
	return 0;
}

/**
 * 写入文件
 * @full_path 文件路径
 * @file_name 文件名
 * @file_type 文件类型
 */
int hid_write_file_handle(const char *full_path, const char *file_name, unsigned int file_type)
{
	hid_handle_init();
	return hid_write_file(hid_handle, full_path, file_name, file_type);
}

int mian(){
	printf("Main");
	return 0;
}