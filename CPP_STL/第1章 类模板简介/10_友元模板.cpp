/**
****************************************************************************************
* @FilePath: 10_友元模板.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-30 16:20:01
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-30 16:20:01
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion:
****************************************************************************************
*/

/*
类模板中友元定义主要分为以下3类：
    1. 非模板函数、类作为实例类的友元；
    2. 模板函数、模板类作为同类型实例类的友元；
    3. 模板函数、模板类作为不同类型实例类的友元。
*/

#include <iostream>

// 1. 非模板函数、类作为实例类的友元
class A1
{
    void aFun();
};

template <class T>
class C
{
    friend class B1;        // 类B1不需要事先声明
    friend void A1::aFun(); // 类A1必须事先声明
};

// 2. 模板函数、模板类作为同类型实例类的友元
template <class T>
class A2
{
    void aFun();
};

template <class T>
void D2(A2<T>);

template <class T>
class B2
{
    void bFun();
};

template <class T>
class C2
{
    friend class A2<T>;        // 类A2需要事先定义或声明
    friend void D2(A2<T>);     // 函数D需要事先定义或声明
    friend void B2<T>::bFun(); // 类B2必须事先定义
};

// 3. 模板函数、模板类作为不同类型实例类的友元
class C3
{
    void cFun();
};

template <class T>
class B3
{
    template <class T1>
    friend class A3;

    template <class T1>
    friend void D3(B3<T1>);

    template <class T1>
    friend void C3::cFun();
};
