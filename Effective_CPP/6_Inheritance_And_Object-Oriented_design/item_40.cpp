/**
****************************************************************************************
* @FilePath: item_40.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-02-01 10:14:07
* @LastEditors: Modest Wang
* @LastEditTime: 2024-02-01 10:14:07
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 明智而审慎地使用多重继承
****************************************************************************************
*/

#include <iostream>
// 多重继承（multiple inheritance；MI）意味着一个类有多个直接基类
// 使用多继承时，派生类会继承多个基类的接口和实现
// 程序可能继承相同名称的函数，这种情况称为二义性（ambiguity）
// 例如，如果D继承了B和C，而B和C都有一个名为f的函数，那么D就会继承两个名为f的函数
// 这种情况下，如果D调用f，编译器就无法确定调用哪个f
class B
{
public:
    virtual void f() {}
};

class C
{
public:
    virtual void f() {}
};

class D : public B, public C
{
};

// 解决二义性的方法之一是在派生类中重新定义函数f
class D_1 : public B, public C
{
public:
    virtual void f() {}
};

// 或者指明调用哪个基类的f函数
class D_2 : public B, public C
{
public:
    virtual void f() {}
    void call_f()
    {
        B::f();
    }
};

// 有时候，多重继承是必要的
// 例如，如果要建立一个类，它同时是一个窗口和一个按钮，那么就需要同时继承窗口类和按钮类
// 但是，多重继承也可能导致设计问题
// 例如，如果一个类同时继承了两个类，而这两个类都继承了同一个类，那么这个类就会继承两份相同的基类
// 这种情况称为菱形继承（diamond inheritance）
// 例如，如果D继承了B和C，而B和C都继承了A，那么D就会继承两份A
// 这种情况下，如果A有成员变量，那么D就会继承两份成员变量
// 为了解决这个问题，C++引入了虚拟继承（virtual inheritance）
// 虚拟继承意味着派生类只继承一个基类的子对象
// 例如，如果B和C都使用了虚拟继承，那么D就只会继承一份A
// 虚拟继承的语法是在基类前加上virtual关键字
class A
{
public:
    virtual void show() const = 0;
};

class B_1 : virtual public A
{
public:
    virtual void show() const
    {
        std::cout << "B_1::show()" << std::endl;
    }
};

class C_1 : virtual public A
{
public:
    virtual void show() const
    {
        std::cout << "C_1::show()" << std::endl;
    }
};

class D_3 : public B_1, public C_1
{
public:
    virtual void show() const
    {
        B_1::show();
    }
};

int main()
{
    D_3 d;
    d.show(); // A::show()

    return 0;
}
