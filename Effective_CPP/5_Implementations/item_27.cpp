/**
****************************************************************************************
* @FilePath: item_27.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-31 19:00:29
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-31 19:00:29
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 尽量少做转型动作
****************************************************************************************
*/

// C语言中的转型动作有两种：
// 1. (new_type)expression: 用于强制类型转换，如整型和浮点型之间的转换，父类和子类之间的转换
// 2. new_type(expression): 用于将一个指针转换为一个整型，或者将一个整型转换为一个指针

// C++中的转型动作有四种：
// 1. static_cast<new_type>(expression): 用于非多态类型的转换，如整型和浮点型之间的转换，父类和子类之间的转换
// 2. const_cast<new_type>(expression): 用于将const或volatile属性加或去掉
// 3. dynamic_cast<new_type>(expression): 用于多态类型的转换，如父类和子类之间的转换
// 4. reinterpret_cast<new_type>(expression): 用于将一个指针转换为一个整型，或者将一个整型转换为一个指针

#include <iostream>

class Windows
{
public:
    void showThis()
    {
        std::cout << "this = " << this << std::endl;
    }
    virtual void onResize()
    {
        std::cout << "Windows::onResize()" << std::endl;
    }
};

class SpecialWindows_1 : public Windows
{
public:
    virtual void onResize()
    {
        static_cast<Windows>(*this).showThis();
        static_cast<Windows>(*this).onResize(); // 将*this转换为Windows类型，然后调用Windows::onResize()
        // 然而这里实际上相当于创建了一个临时对象，该临时对象是*this的一个副本，因此对该临时对象的操作并不会影响*this
        this->showThis();
        std::cout << "SpecialWindows::onResize()" << std::endl;
    }
};

class SpecialWindows_2 : public Windows
{
public:
    virtual void onResize()
    {
        this->showThis();
        Windows::onResize(); // 调用Windows::onResize()
        std::cout << "SpecialWindows::onResize()" << std::endl;
    }
};
/*
class SpecialWindows : public Windows
{
public:
    void blink()
    {
        std::cout << "SpecialWindows::blink()" << std::endl;
    }
};

//typedef std::vector<std::tr1::shared_ptr<SpecialWindows> > VPSW;
typedef std::vector<std::shared_ptr<SpecialWindows> > VPSW; // std::tr1::shared_ptr已经被C++11标准库中的std::shared_ptr取代
VPSW winPtrs;

for (VPSW::iterator iter = winPtrs.begin(); iter != winPtrs.end(); ++iter)
{
    (*iter)->blink();
}
*/

int main(int argc, char *argv[])
{
    SpecialWindows_1 sw1;
    sw1.onResize();

    SpecialWindows_2 sw2;
    sw2.onResize();
    return 0;
}
