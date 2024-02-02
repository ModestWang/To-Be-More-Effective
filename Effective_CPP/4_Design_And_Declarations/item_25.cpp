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

// pimpl手法：将实现细节放到一个class中，再将该class的对象指针或引用放到另一个class中
// pointer to implementation

#include <iostream>
#include <string>

// namespace std
// {
//     template <typename T>
//     void mySwap(T &a, T &b)
//     {
//         T tmp(a);
//         a = b;
//         b = tmp;
//     }
// }

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
    void showPImpl()
    {
        std::cout << pImpl << std::endl;
    }
    void swap(Widget &rhs)
    {
        using std::swap; // 为了调用std::swap，必须使用using声明
        swap(pImpl, rhs.pImpl);
    }

private:
    WidgetImpl *pImpl;
};

namespace std
{
    // 很神奇
    // 为了让std::swap能够调用Widget::swap，必须使用template<>，否则编译器会认为std::swap是一个普通函数
    template <> // 表示这是一个全特化版本（total specialization）
    void swap<Widget>(Widget &a, Widget &b)
    {
        a.swap(b);
    }
}

namespace myNamespace
{
    template <typename T>
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
        void showPImpl()
        {
            std::cout << pImpl << std::endl;
        }
        void swap(Widget &rhs)
        {
            using std::swap; // 为了调用std::swap，必须使用using声明
            swap(pImpl, rhs.pImpl);
        }

    private:
        WidgetImpl *pImpl;
    };

    template <typename T>
    void swap(Widget<T> &a, Widget<T> &b)
    {
        a.swap(b);
    }
}

int main(int argc, char *argv[])
{
    // 采用pimpl手法时，只需要交换指针即可
    Widget w1;
    Widget w2;

    std::cout << "交换前：" << std::endl;
    w1.showPImpl();
    w2.showPImpl();

    std::swap(w1, w2);

    std::cout << "交换后：" << std::endl;
    w1.showPImpl();
    w2.showPImpl();

    myNamespace::Widget<int> w3;
    myNamespace::Widget<int> w4;

    std::cout << "交换前：" << std::endl;
    w3.showPImpl();
    w4.showPImpl();

    myNamespace::swap(w3, w4);

    std::cout << "交换后：" << std::endl;
    w3.showPImpl();
    w4.showPImpl();

    return 0;
}

// 当std::swap对你的类型效率不高时，提供一个swap成员函数，并确定这个函数不抛出异常。
// 如果你提供了swap成员函数，那么你也应该提供一个non-member swap函数（如上面的std::swap<Widget>），
// 调用swap时，应该使用using声明式，然后调用swap并且不带任何“命名空间资格”（namespace qualification）。
// 为“用户定义类型”进行std template全特化是好的，但是千万不要尝试在std内加入某些对std而言全新的东西。
