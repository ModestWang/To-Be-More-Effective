/**
****************************************************************************************
* @FilePath: 1_C++模板.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-30 10:47:17
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-30 12:46:07
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion:
****************************************************************************************
*/

#include <iostream>

template <typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}

int main()
{
    std::cout << max(1, 2) << std::endl;
    std::cout << max(1.1, 2.2) << std::endl;
    std::cout << max('a', 'b') << std::endl;
    std::cout << max("hello", "world") << std::endl;
    return 0;
}
