/**
****************************************************************************************
* @FilePath: item_28.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-31 19:00:37
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-31 19:00:37
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 避免返回handles指向对象内部成分
****************************************************************************************
*/

#include <iostream>

class Point
{
public:
    Point(int x, int y) : _x(x), _y(y) {}
    void setX(int x) { _x = x; }
    void setY(int y) { _y = y; }
    int getX() const { return _x; }
    int getY() const { return _y; }

private:
    int _x;
    int _y;
};

struct RectData
{
    RectData() : ulhc(0, 0), lrhc(0, 0) {}
    Point ulhc; // upper-left-hand corner
    Point lrhc; // lower-right-hand corner
};

class Rectangle
{
public:
    Rectangle(const Point &ulhc, const Point &lrhc)
        : _pData(new RectData) // 在构造函数中动态分配内存
    {
        _pData->ulhc = ulhc;
        _pData->lrhc = lrhc;
    }
    const Point &upperLeft() const { return _pData->ulhc; }
    const Point &lowerRight() const { return _pData->lrhc; }

private:
    std::shared_ptr<RectData> _pData;
};
