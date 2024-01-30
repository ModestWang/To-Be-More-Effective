/**
****************************************************************************************
* @FilePath: 6_生成临时文件.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-30 12:07:12
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-30 12:49:56
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion:
****************************************************************************************
*/

#include <iostream>
#include <stdio.h>

int main()
{
    char *temp_file_name;
    temp_file_name = tmpnam(NULL);
    printf("Temporary file name is: %s\n", temp_file_name);
    return 0;
}
