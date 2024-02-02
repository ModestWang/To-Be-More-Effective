/**
****************************************************************************************
* @FilePath: item_33.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-02-01 10:09:54
* @LastEditors: Modest Wang
* @LastEditTime: 2024-02-01 10:09:54
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 避免遮掩继承而来的名称
****************************************************************************************
*/

#include <iostream>

// 这一部分是为了说明，如果子类中有和父类同名的函数，那么父类中的同名函数会被遮掩
// 实际上是与作用域有关

// 一个人简单的例子：
int x;
void f()
{
    double x;      // 遮掩了全局变量x
    std::cin >> x; // 读取到的是局部变量x
}

// 一个稍微复杂的例子：
class Base
{
public:
    virtual void mf1() = 0;
    virtual void mf1(int)
    {
        std::cout << "Base::mf1(int)" << std::endl;
    }
    virtual void mf2()
    {
        std::cout << "Base::mf2()" << std::endl;
    }
    void mf3()
    {
        std::cout << "Base::mf3()" << std::endl;
    }
    void mf3(double x)
    {
        std::cout << "Base::mf3(double)" << std::endl;
    }

private:
    int x;
};

class Derived : public Base
{
public:
    virtual void mf1()
    {
        std::cout << "Derived::mf1()" << std::endl;
    }
    void mf3()
    {
        std::cout << "Derived::mf3()" << std::endl;
    }
    void mf4()
    {
        std::cout << "Derived::mf4()" << std::endl;
        mf2(); // 调用的是Base::mf2()
        // 编译器查找过程为：
        // 1. 在Derived中查找mf2，没有找到
        // 2. 在Base中查找mf2，找到了
        // 3. 在Base中查找mf2的访问权限，发现是public
        // 4. 在Base中查找mf2的virtual属性，发现是virtual
        // 5. 在Base中查找mf2的签名，发现是void mf2()
        // 6. 在Base中查找mf2的实现，找到了
        // 7. 在Base中调用mf2
        // 8. 在Derived中调用mf2
        // 9. 在Derived中调用mf4
    }
};

int main(int argc, char *argv[])
{
    Derived d;
    d.mf1(); // 调用的是Derived::mf1()
    // d.mf1(1);   // 错误，因为Base::mf1()和Derived::mf1(int)是同名的，但是签名不同，所以Derived::mf1(int)会遮掩Base::mf1()
    d.mf2(); // 调用的是Base::mf2()
    d.mf3(); // 调用的是Derived::mf3()
    // d.mf3(1.0); // 错误，因为Derived::mf3()和Base::mf3(double)是同名的，同样Derived::mf3(double)会遮掩Base::mf3()
    d.mf4(); // 调用的是Derived::mf4()

    return 0;
}

// 为了避免这种情况，可以使用using声明式
class Derived_1 : public Base
{
public:
    using Base::mf1; // 告诉编译器，Derived_1中的mf1和Base中的mf1是同名的
    using Base::mf3; // 告诉编译器，Derived_1中的mf3和Base中的mf3是同名的
    virtual void mf1()
    {
        std::cout << "Derived_1::mf1()" << std::endl;
    }
    void mf3()
    {
        std::cout << "Derived_1::mf3()" << std::endl;
    }
    void mf4()
    {
        std::cout << "Derived_1::mf4()" << std::endl;
        mf2(); // 调用的是Derived_1::mf2()
    }
};

// 或者使用转交函数（forwarding function）
class Derived_2 : private Base
{
public:
    virtual void mf1()
    {
        std::cout << "Derived_2::mf1()" << std::endl;
        Base::mf1(); // 调用的是Base::mf1()
    }
    void mf3()
    {
        std::cout << "Derived_2::mf3()" << std::endl;
        Base::mf3(); // 调用的是Base::mf3()
    }
    void mf4()
    {
        std::cout << "Derived_2::mf4()" << std::endl;
        mf2(); // 调用的是Base::mf2()
    }
};
