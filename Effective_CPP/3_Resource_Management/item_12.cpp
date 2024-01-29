/**
****************************************************************************************
* @FilePath: item_12.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-28 17:08:40
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-28 17:11:53
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 复制对象时勿忘其每一个成分
****************************************************************************************
*/

#include <iostream>
#include <string>

/**
****************************************************************************************
* @brief: 记录函数调用
* @param[in] &funcName
* @return
****************************************************************************************
*/
void logCall(const std::string &funcName)
{
    std::cout << funcName << std::endl;
}

class Customer
{
public:
    Customer() // 构造函数
    {
        logCall("Customer::Customer()");
    }
    ~Customer() // 析构函数
    {
        logCall("Customer::~Customer()");
    }
    Customer(const Customer &rhs) // 拷贝构造函数
    {
        logCall("Customer::Customer(const Customer &)");
    }
    Customer &operator=(const Customer &rhs) // 赋值操作符
    {
        logCall("Customer::operator=(const Customer &)");
        return *this;
    }
};

class PriorityCustomer : public Customer
{
public:
    PriorityCustomer() // 构造函数
    {
        logCall("PriorityCustomer::PriorityCustomer()");
    }
    ~PriorityCustomer() // 析构函数
    {
        logCall("PriorityCustomer::~PriorityCustomer()");
    }
    PriorityCustomer(const PriorityCustomer &rhs) // 拷贝构造函数
    {
        logCall("PriorityCustomer::PriorityCustomer(const PriorityCustomer &)");
    }
    PriorityCustomer &operator=(const PriorityCustomer &rhs) // 赋值操作符
    {
        logCall("PriorityCustomer::operator=(const PriorityCustomer &)");
        return *this;
    }
};

int main(int argc, char **argv)
{
    PriorityCustomer c1;
    PriorityCustomer c2(c1);
    PriorityCustomer c3;
    c3 = c2;

    return 0;
}
