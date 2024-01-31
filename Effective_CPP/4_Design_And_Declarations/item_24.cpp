/**
****************************************************************************************
* @FilePath: item_24.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-31 14:28:14
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-31 14:28:14
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 若所有参数皆需类型转换，请为此采用non-member函数
****************************************************************************************
*/

#include <iostream>
#include <string>

class Rational
{
public:
    Rational(int numerator = 0, int denominator = 1) : n(numerator), d(denominator) {}
    int numerator() const { return n; }
    int denominator() const { return d; }

    const Rational operator*(const Rational &rhs) const {}
    // 通过重载运算符实现乘法，但是结果并不令人满意

private:
    int n;
    int d;
};

// non-member函数
const Rational operator*(const Rational &lhs, const Rational &rhs)
{
    return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}

int main()
{
    Rational oneEighth(1, 8);
    Rational result;
    // result = oneEighth * 2; // 正确！2被转换为Rational(2, 1)
    // result = 2 * oneEighth; // 错误！2不能被转换为Rational类型
    // 但是当Rational的构造函数为explicit时，上述两种情况都无法通过编译

    // 为了解决上述问题，可以将operator*重载为non-member函数
    // const Rational operator*(const Rational &lhs, const Rational &rhs)
    // {
    //     return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
    // }
}

// 如果你需要为某个函数的所有参数（包括被this指针所指的那个隐喻参数）进行类型转换，那么这个函数必须是个non-member
