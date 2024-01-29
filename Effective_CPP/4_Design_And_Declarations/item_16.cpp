/**
****************************************************************************************
* @FilePath: item_16.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-28 19:14:20
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-28 19:14:20
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 成对使用new和delete时要采取相同形式
****************************************************************************************
*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>

// 但是如果使用了new[]，就必须使用delete[]，否则会出现未定义行为
// 例如下面的代码：
int main(int argc, char *argv[])
{
    std::string *stringArray = new std::string[100]; // 为100个string对象分配内存
    // ...
    delete[] stringArray; // 释放内存
    // 而不是: delete stringArray;
    return 0;
}
