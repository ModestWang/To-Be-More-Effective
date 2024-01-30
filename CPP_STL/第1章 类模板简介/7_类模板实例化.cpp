/**
****************************************************************************************
* @FilePath: 7_类模板实例化.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-30 12:45:12
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-30 12:51:40
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 类模板仅仅是模板。模板实例化一般指使用模板类和模板参数生成一个类声明的过程。
****************************************************************************************
*/

#include <iostream>
#include <list>

int main()
{
    int count = 0;
    double number = 0;
    std::list<int> myList; // 声明一个list对象,进行实例化

    std::cout << "输入三个数" << std::endl;
    while (count < 3)
    {
        std::cin >> number;
        myList.push_back(number);
        count++;
    }

    std::list<int>::iterator iter;
    for (iter = myList.begin(); iter != myList.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }

    return 0;
}
