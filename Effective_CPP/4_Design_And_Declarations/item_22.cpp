/**
****************************************************************************************
* @FilePath: item_22.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-31 12:19:05
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-31 12:19:05
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 将成员变量声明为private，然后通过public的成员函数来访问成员变量
****************************************************************************************
*/

#include <iostream>
#include <string>

class AccessLevels
{
public:
    int getReadOnly() const { return readOnly; }
    void setReadWrite(int value) { readWrite = value; }
    int getReadWrite() const { return readWrite; }
    void setWriteOnly(int value) { writeOnly = value; }

private:
    int noAccess;
    int readOnly;
    int readWrite;
    int writeOnly;
};

class SpeedDataCollection
{
public:
    void addValue(int speed);
    double averageSoFar() const;

private:
    int total;
    int numValues;
};

void SpeedDataCollection::addValue(int speed)
{
    ++numValues;
    total += speed;
}

double SpeedDataCollection::averageSoFar() const
{
    return static_cast<double>(total) / numValues;
}

int main()
{
    AccessLevels accessLevels;
}

// 封装的重要性比你初见它的时候还要重要。
// 切记将成员变量声明为private，然后通过public的成员函数来访问成员变量。
// protected并不比public更具封装性。
