/**
****************************************************************************************
* @FilePath: 5_Calculator.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-30 11:19:13
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-30 12:49:34
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion:
****************************************************************************************
*/

#include <iostream>
#include <cmath>
#include <stdio.h>

class Calculator
{
public:
    Calculator();
    ~Calculator();
    double x;
    double y;

    double adder(double x, double y);      // 加法
    double subtractor(double x, double y); // 减法
    double multiplier(double x, double y); // 乘法
    double divider(double x, double y);    // 除法
    double power(double x, double y);      // 幂运算
    double root(double x, double y);       // 开方
};

Calculator::Calculator()
{
    std::cout << "Calculator is created." << std::endl;
}

Calculator::~Calculator()
{
    std::cout << "Calculator is destroyed." << std::endl;
}

double Calculator::adder(double x, double y)
{
    return x + y;
}

double Calculator::subtractor(double x, double y)
{
    return x - y;
}

double Calculator::multiplier(double x, double y)
{
    return x * y;
}

double Calculator::divider(double x, double y)
{
    return x / y;
}

double Calculator::power(double x, double y)
{
    return pow(x, y);
}

double Calculator::root(double x, double y)
{
    return pow(x, 1 / y);
}

int main()
{
    Calculator calculator;
    double x, y;
    std::cout << "Please input two numbers: " << std::endl;
    std::cin >> x >> y;
    std::cout << "The sum of " << x << " and " << y << " is " << calculator.adder(x, y) << std::endl;
    std::cout << "The difference of " << x << " and " << y << " is " << calculator.subtractor(x, y) << std::endl;
    std::cout << "The product of " << x << " and " << y << " is " << calculator.multiplier(x, y) << std::endl;
    std::cout << "The quotient of " << x << " and " << y << " is " << calculator.divider(x, y) << std::endl;
    std::cout << x << " to the power of " << y << " is " << calculator.power(x, y) << std::endl;
    std::cout << x << " to the root of " << y << " is " << calculator.root(x, y) << std::endl;
    return 0;
}
