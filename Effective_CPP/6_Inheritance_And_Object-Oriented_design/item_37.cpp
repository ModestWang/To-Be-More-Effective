/**
****************************************************************************************
* @FilePath: item_37.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-02-01 10:12:08
* @LastEditors: Modest Wang
* @LastEditTime: 2024-02-01 10:12:08
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 绝不重新定义继承而来的缺省参数值
****************************************************************************************
*/

#include <iostream>

class Shape
{
public:
    enum ShapeColor
    {
        Red,
        Green,
        Blue
    };
    // virtual函数是动态绑定，而缺省参数值是静态绑定
    virtual void draw(ShapeColor color = Red) const = 0;
};

class Rectangle : public Shape
{
public:
    virtual void draw(ShapeColor color = Green) const
    {
        std::cout << "Rectangle::doDraw" << std::endl;
        std::cout << "color: " << color << std::endl;
    }
};

class Circle : public Shape
{
public:
    // 使用对象调用这个函数时，必须提供一个参数，应为静态绑定下，这个函数不会从基类中继承缺省参数值
    // 但是，当通过指针或引用调用这个函数时，可以提供一个参数，也可以不提供参数，因为动态绑定下，这个函数会从基类中继承缺省参数值
    virtual void draw(ShapeColor color) const
    {
        std::cout << "Circle::draw" << std::endl;
        std::cout << "color: " << color << std::endl;
    }
};

int main()
{
    Rectangle r;
    Shape *ps = &r;
    r.draw();   // draw(Green)
    ps->draw(); // draw(Red)
    // 真糟糕，两者结果不一致！

    Circle c;
    ps = &c;
    ps->draw(Shape::Blue); // draw(Blue)

    return 0;
}
