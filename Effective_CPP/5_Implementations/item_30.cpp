/**
****************************************************************************************
* @FilePath: item_30.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-31 19:01:32
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-31 19:01:32
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 透彻了解inlining的里里外外
****************************************************************************************
*/

// inline会产生weak symbol，所以inline函数的定义必须放在头文件中
#include <iostream>

class Person
{
public:
    int age() const { return theAge; } // 隐含的inline函数
private:
    int theAge;
};

// template <typename T>
// inline const T &std::max(const T &a, const T &b) // 显式的inline函数
// {
//     return a < b ? b : a;
// }

// 另外，一个表面上看起来是inline的函数是否真的inline，取决于编译器的意愿
// 多数情况下，编译器会尽力遵守你的要求
// 如果它们无法满足你的要求，会给你一个警告

namespace libfoo
{
    template <typename T>
    T foo(T d) { return d; }

    class Bar1
    {
    public:
        void doSomething()
        {
            std::cout << "Bar1::doSomething()" << std::endl;
        }
    };

    // namespace libfoo_2024
    inline namespace libfoo_2024
    {
        void foo1(Bar1 pb) { pb.doSomething(); }

        class Bar2
        {
        public:
            void doSomething()
            {
                std::cout << "Bar2::doSomething()" << std::endl;
            }
        };

    }
    using namespace libfoo_2024;
    void foo2(Bar2 pb) { pb.doSomething(); }
}

namespace libfoo
{
    template <>
    double foo<double>(double d)
    {
        std::cout << "libfoo::foo<double>" << d << std::endl;
        return d;
    }
}

int main(int argc, char *argv[])
{
    libfoo::foo(3.14);
    libfoo::Bar1 bar1;
    libfoo::Bar2 bar2;
    (void)foo1(bar1);
    (void)foo2(bar2);
    return 0;
}
