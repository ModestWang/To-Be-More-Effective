/**
****************************************************************************************
* @FilePath: 11_类模板的参数.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-30 16:53:11
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-30 16:53:11
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion:
****************************************************************************************
*/

// 类模板的参数可以是类型参数，也可以是非类型参数。
// 类模板的参数可以有多个，用逗号分隔。
// 并且，类模板的参数可以有默认值。

#include <iostream>

// 1. 类模板的类型参数
template <class T1, class T2>
class A1
{
public:
    A1(T1 a, T2 b) : m_a(a), m_b(b) {}
    void print()
    {
        std::cout << m_a << " " << m_b << std::endl;
    }

private:
    T1 m_a;
    T2 m_b;
};

// 2. 类模板的非类型参数
template <class T, int size>
class A2
{
public:
    A2(T a)
    {
        for (int i = 0; i < size; i++)
        {
            m_a[i] = a;
        }
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << m_a[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    T m_a[size];
};

// 3. 类模板的默认参数
template <class T1 = int, class T2 = int>
class A3
{
public:
    A3(T1 a, T2 b) : m_a(a), m_b(b) {}
    void print()
    {
        std::cout << m_a << " " << m_b << std::endl;
    }

private:
    T1 m_a;
    T2 m_b;
};

int main()
{
    // 1. 类模板的类型参数
    A1<int, double> a1(1, 2.2); // 由于指定了类型参数，所以必须指定类型参数
    a1.print();

    // 2. 类模板的非类型参数
    A2<int, 5> a2(1); // 由于指定了非类型参数，所以必须指定类型参数
    a2.print();

    // 3. 类模板的默认参数
    A3<> a3(1, 2); // 由于指定了默认参数，所以可以不用指定类型参数
    a3.print();

    return 0;
}
