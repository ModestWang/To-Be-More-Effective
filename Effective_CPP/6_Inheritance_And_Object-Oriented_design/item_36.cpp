/**
****************************************************************************************
* @FilePath: item_36.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-02-01 10:10:58
* @LastEditors: Modest Wang
* @LastEditTime: 2024-02-01 10:11:06
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 绝不重新定义继承而来的non-virtual函数
****************************************************************************************
*/

#include <iostream>

class Base
{
public:
    void mf() { std::cout << "Base::mf()" << std::endl; }
};

class Derived : public Base
{

public:
    void mf() { std::cout << "Derived::mf()" << std::endl; }
};

int main()
{
    Derived d;
    Base *pB = &d;
    Derived *pD = &d;
    pB->mf(); // Base::mf()
    pD->mf(); // Derived::mf()
    return 0;
}
