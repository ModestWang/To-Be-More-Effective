/**
****************************************************************************************
* @FilePath: item_25.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-31 14:29:29
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-31 14:29:29
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 考虑写出一个不抛异常的swap函数
****************************************************************************************
*/

#include <iostream>
#include <string>
#include <vector>

namespace std
{
    template <typename T>
    void swap(T &a, T &b)
    {
        T tmp(a);
        a = b;
        b = tmp;
    }
}

class WidgetImpl
{
public:
    WidgetImpl() : data(0) {}
    WidgetImpl(const WidgetImpl &rhs) : data(rhs.data) {}
    WidgetImpl &operator=(const WidgetImpl &rhs)
    {
        data = rhs.data;
        return *this;
    }

private:
    int data;
};

class Widget
{
public:
    Widget() : pImpl(new WidgetImpl) {}
    Widget(const Widget &rhs) : pImpl(new WidgetImpl(*rhs.pImpl)) {}
    Widget &operator=(const Widget &rhs)
    {
        *pImpl = *rhs.pImpl;
        return *this;
    }

    void swap(Widget &rhs)
    {
        using std::swap;
        swap(pImpl, rhs.pImpl);
    }

private:
    WidgetImpl *pImpl;
};

int main(int argc, char *argv[])
{
    Widget w1;
    Widget w2;
    std::swap(w1, w2);
    return 0;
}
