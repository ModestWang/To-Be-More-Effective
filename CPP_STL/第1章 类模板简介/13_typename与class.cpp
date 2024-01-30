/**
****************************************************************************************
* @FilePath: 13_typename与class.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-30 17:44:36
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-30 17:44:57
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion:
****************************************************************************************
*/

#include <iostream>

// typename与class的区别
// 1.在模板中，typename和class可以互换
// 2.在模板中，typename和class可以用来声明模板参数，但是typename更加通用

// 示例1
template <typename T>
class X
{
    T t;
};

template <class T>
class Y
{
    T t;
};

// 示例2
template <typename T>
void func1(T t)
{
    std::cout << "func1:" << t << std::endl;
}

template <class T>
void func2(T t)
{
    std::cout << "func2:" << t << std::endl;
}

int main(int argc, char *argv[])
{
    // 示例1
    X<int> x1;
    Y<int> y1;

    // 示例2
    func1(1);
    func2(1);

    return 0;
}
