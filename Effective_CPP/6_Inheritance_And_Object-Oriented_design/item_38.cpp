/**
****************************************************************************************
* @FilePath: item_38.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-02-01 10:13:13
* @LastEditors: Modest Wang
* @LastEditTime: 2024-02-01 10:13:13
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 通过复合塑模出has-a或根据某物实现出
****************************************************************************************
*/

// 复合（composition）是类型之间的一种关系，当某种类型的对象内含它种类型的对象，便是这种关系
// 复合是一种has-a关系

class Address
{
};

class PhoneNumber
{
};

class Person
{
public:
    Person::Person(const Address &addr, const PhoneNumber &phone)
        : address(addr), voiceNumber(phone), faxNumber(phone) {}

private:
    Address address;
    PhoneNumber voiceNumber;
    PhoneNumber faxNumber;
    // 组合
};

