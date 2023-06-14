/*
 * @Author: yaohengfeng 1921934563@qq.com
 * @Date: 2023-01-13 10:45:03
 * @LastEditors: 姚恒锋 1921934563@qq.com
 * @LastEditTime: 2023-06-14 15:59:28
 * @FilePath: \hid-handle\src\hidhandle.cc
 * @Description: hidhandle.cc
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <hidapi.h>

#include "hmi_hid.h"

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

		if (!hid_handle)
		{
			printf("\nFailed to open HID Device!\n");
			return -1;
		}

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

int main()
{
	if (hid_handle_init() == -1)
		return -1;

	printf("HID Driver opened!\n");

	hid_write_file(hid_handle, "H:/cmake-hid-handle/output/product_sabbat_dual.abs", "product_sabbat_dual.abs", TRAN_TYPE_FIRMWARE);

	return 0;
}