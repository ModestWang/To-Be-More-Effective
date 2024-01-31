/**
****************************************************************************************
* @FilePath: item_17.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-28 19:28:58
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-28 19:28:58
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 以独立语句将newed对象置入智能指针
****************************************************************************************
*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Widget
{
};

int priority()
{
    std::cout << "priority" << std::endl;
    return 0;
}
void processWidget(std::shared_ptr<Widget> pw, int priority)
{
    std::cout << "processWidget" << std::endl;
}

int main(int argc, char *argv[])
{
    // 1. 以独立语句将newed对象置入智能指针
    // processWidget(std::shared_ptr<Widget>(new Widget), priority());
    // 2. 以独立语句将newed对象置入智能指针
    std::shared_ptr<Widget> pw(new Widget);
    processWidget(pw, priority());
    return 0;
}
