/**
****************************************************************************************
* @FilePath: item_34.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-02-01 10:10:18
* @LastEditors: Modest Wang
* @LastEditTime: 2024-02-01 10:10:18
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 区分接口继承和实现继承
****************************************************************************************
*/

// 函数接口继承(function interface inheritance)和函数实现继承(function implementation inheritance)
// 接口继承和实现继承的区别在于，接口继承只继承函数的声明，而实现继承则继承函数的声明和定义。

#include <iostream>
class Shape
{
public:
    virtual void draw() const = 0; // 纯虚函数（pure virtual function）
    virtual void error(const std::string &msg);
    int objectID() const;
};
void Shape::draw() const
{
    std::cout << "Shape::draw()" << std::endl;
} // 注意：纯虚函数也可以有定义，但是定义必须在类的外部，而且不能在定义中使用关键字virtual
// 调用的时候，必须使用类名限定，如Shape::draw()

class Rectangle : public Shape
{
public:
    virtual void draw() const;
};

class Ellipse : public Shape
{
public:
    virtual void draw() const;
};

// 以下是实现继承的例子
class Airport
{
public:
    std::string getName() const;

private:
    std::string name;
};
class Airplane
{
public:
    virtual void fly(const Airport &destination);
};

class ModelA : public Airplane
{
public:
    virtual void fly(const Airport &destination);
};

class ModelB : public Airplane
{
public:
    virtual void fly(const Airport &destination);
};

class ModelC : public Airplane
{
};

int main(int argc, char *argv[])
{
    Airport destination;
    Airplane *c = new ModelC;
    c->fly(destination); // 这样会调用Airplane::fly这一默认实现
    // 试想：一架飞机以另一架飞机的方式飞行，这是不可能的，所以这里的实现继承是不合理的
    // 问题不在于Airplane::fly有缺省行为，而在于ModelC在未明白说出“我需要”的情况下继承了这个缺省行为

    // 将Airplane::fly声明为纯虚函数，这样ModelC就必须提供自己的实现，这或许是一个解决方案

    return 0;
}

// 在public继承下，派生类总是继承基类的接口
// pure virtual函数只具体指定接口继承，而不具体指定实现继承
// impure virtual函数具体指定接口继承，以及缺省实现继承
// non-virtual函数具体指定接口继承，以及强制性实现继承
