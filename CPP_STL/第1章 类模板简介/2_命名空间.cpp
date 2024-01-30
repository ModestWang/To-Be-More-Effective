/**
****************************************************************************************
* @FilePath: 2_命名空间.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-30 10:52:04
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-30 12:45:53
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion:
****************************************************************************************
*/

#include <iostream>
using namespace std;

namespace A
{
    int a = 10;
    void func()
    {
        cout << "A::func()" << endl;
    }
} // namespace A

namespace B
{
    int a = 20;
    void func()
    {
        cout << "B::func()" << endl;
    }
} // namespace B

int main()
{
    // using namespace std;  // 可以在源代码的任何位置使用using声明
    cout << A::a << endl; // 使用命名空间A中的变量a
    cout << B::a << endl; // 使用命名空间B中的变量a
    A::func();            // 使用命名空间A中的函数func
    B::func();            // 使用命名空间B中的函数func
    return 0;
}
