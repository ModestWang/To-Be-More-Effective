/**
****************************************************************************************
* @FilePath: 9_成员模板.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-30 16:04:04
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-30 16:05:38
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion:   成员模板是指在类中定义的模板函数或模板成员函数。
*                  成员模板的定义格式为：
*                  template <class T1, class T2, ...>
*                  ret-type Class::function-name(parameter list)
*                  {
*                      // 函数体
*                  }
*                  其中，ret-type是返回值类型，Class是类名，function-name是函数名，parameter list是参数列表。
*                  成员模板的定义必须在类的内部，但可以在类的外部进行实现。
*                  成员模板的使用格式为：
*                  Class::function-name<type-list>(parameter list)
*                  其中，Class是类名，function-name是函数名，type-list是模板参数列表，parameter list是参数列表。
*                  成员模板的使用必须在类的外部进行。
* 使用的注意事项：
*                  1. 成员模板不能重载基类的虚函数。
*                  2. 成员模板不能是virtual。
*                  3. 析构器不能是模板类型。
*                  4. 成员模板不能是虚基类。
*                  5. 成员模板不能是局部类的成员。
*                  6. 成员模板具有复杂的转换功能。
****************************************************************************************
*/

#include <iostream>

template <class T>
class string
{
    template <class T1>
    int compare(T1 &str);
};

// 成员模板的实现,在类外部定义成员函数
// 注意 template <class T> 不能省略
// 并且 template <class T, class T1> 不能写成 template<class T1, class T>
template <class T>
template <class T1>
int string<T>::compare(T1 &str)
{
    std::cout << "compare" << std::endl;
    return 0;
}
