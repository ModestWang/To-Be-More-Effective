/**
****************************************************************************************
* @FilePath: item_15.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-28 18:55:40
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-28 18:55:40
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 在资源管理类中提供对原始资源的访问
****************************************************************************************
*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>

struct FontHandle
{
    int size;                // 字体大小
    int ID;                  // 字体ID
    bool isoccupied = false; // 是否被占用
    //...
};

FontHandle getFont(FontHandle fh) // 获取字体
{
    fh.isoccupied = true;
    std::cout << "getFont对象, ID为" << fh.ID << std::endl;
    return fh;
}

void releaseFont(FontHandle fh) // 释放字体
{
    fh.isoccupied = false;
    std::cout << "releaseFont对象, ID为" << fh.ID << std::endl;
}

class Font
{
public:
    explicit Font(FontHandle fh) : f(fh)
    {
        // std::cout << "Font::Font" << std::endl;
    }
    ~Font()
    {
        releaseFont(f);
        // std::cout << "Font::~Font" << std::endl;
    }
    FontHandle get() const // 显式转换函数
    {
        return f;
    }
    operator FontHandle() const // 隐式转换函数
    {
        return f;
    }

private:
    FontHandle f;
};

void changeFontSize(FontHandle f, int newSize) // 改变字体大小
{
    f.size = newSize;
    std::cout << "changeFontSize对象, ID为" << f.ID << std::endl;
}

FontHandle fontHandle;

int main(int argc, char *argv[])
{
    Font font(getFont(fontHandle));
    int newFontSize = 10;
    changeFontSize(font.get(), newFontSize); // 显式转换函数

    newFontSize = 20;
    changeFontSize(font, newFontSize); // 隐式转换函数
                                       /*
                                       注意：隐式转换的问题：
                                       Font f1(getFont(fontHandle));
                                       ...
                                       FontHandle f2 = f1;
                                       原意是将f1转换为FontHandle类型，
                                       但是编译器会将其转换为Font类型，
                                       然后再转换为FontHandle类型
                                       */
    return 0;
}
