/**
****************************************************************************************
* @FilePath: item_21.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-31 11:41:08
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-31 11:41:08
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 必须返回对象时，别妄想返回其reference，必须返回对象时，别妄想返回其reference
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

private:
    friend const Rational operator*(const Rational &lhs, const Rational &rhs);
    int n, d;
};

const Rational operator*(const Rational &lhs, const Rational &rhs)
{
    // 如果返回的是引用，那么返回的是局部变量的引用，局部变量在函数结束后会被销毁，所以返回的引用是无效的
    return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}

int main()
{
    Rational a(1, 2);
    Rational b(2, 3);
    Rational c(3, 4);

    Rational d = a * b * c;
    std::cout << d.numerator() << "/" << d.denominator() << std::endl;
    return 0;
}

// 绝不要返回pointer或reference指向一个local stack对象，
// 或指向一个heap-allocated对象，而其指针或引用已经被销毁
