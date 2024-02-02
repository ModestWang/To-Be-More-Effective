/**
****************************************************************************************
* @FilePath: item_32.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-02-01 10:09:13
* @LastEditors: Modest Wang
* @LastEditTime: 2024-02-01 10:09:13
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 确定你的public继承塑模出is-a关系
****************************************************************************************
*/

#include <iostream>
#include <cassert>

// “public继承”意味着is-a，适用于base class身上的每一件事情一定也适用于derived class身上
// 因为每一个derived class对象也都是一个base class对象

// 考虑以下示例
class Rectangle
{
public:
    virtual void setHeight(int newHeight);
    virtual void setWidth(int newWidth);
    virtual int height() const;
    virtual int width() const;
    // ...
};

void makeBigger(Rectangle &r)
{
    int oldHeight = r.height();
    r.setWidth(r.width() + 10);
    assert(r.height() == oldHeight);
}

class Square : public Rectangle
{
public:
    virtual void setHeight(int newHeight);
    virtual void setWidth(int newWidth);
    // ...
};

// 由于Square是Rectangle，所以makeBigger函数也适用于Square对象
// 但是Square对象的height和width不一定相等，所以makeBigger函数不适用于Square对象
// 由此可见，Square不是Rectangle，所以public继承不适用于Square和Rectangle之间的关系

int main(int argc, char *argv[])
{
    Rectangle r;
    Square s;
    makeBigger(r);
    // makeBigger(s); // error: no matching function for call to 'makeBigger(Square&)'
    return 0;
}
