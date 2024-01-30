/**
****************************************************************************************
* @FilePath: 12_typename的使用.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-30 17:03:15
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-30 17:03:15
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: typename关键字告诉编译器其后的模板参数是一个类型，而不是一个成员变量，可以用来创建实例
****************************************************************************************
*/

#include <iostream>

// 示例1
template <class T>
class X
{
    typedef typename T::A TA;
    TA *pTA;
};

// 示例2
template <class T>
class Y
{
    typename T::iter it;

public:
    explicit Y(const typename T::iter &i) : it(i) {} // 这里的typename不能省略
    void show()
    {
        typename T::iter *itemp;
        itemp = &it;
        std::cout << (*itemp)->p << std::endl;
    }
};

class Card
{
public:
    typedef Card *iter; // 这里的iter是一个类型，而不是一个成员变量
    int p;
    Card(int val) : p(val) {}
};

int main(int argc, char *argv[])
{
    // 示例2
    Card card(3);
    Y<Card> y(&card);
    y.show();

    return 0;
}
