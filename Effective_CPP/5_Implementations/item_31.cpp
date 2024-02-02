/**
****************************************************************************************
* @FilePath: item_31.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-31 19:01:43
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-31 19:01:55
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 将文件间的编译依存关系降至最低
****************************************************************************************
*/

#include <iostream>

// 应该#include适当的头文件，而非声明forward class
// 可以参考<iosfwd>头文件，它声明了所有I/O流类的forward class
// 可以尝试在头文件中声明forward class，然后在源文件中进行实现

class Date
{
};
class Address
{
};

class PersonImpl
{
public:
    PersonImpl(const std::string &name, const Date &birthday, const Address &addr);

    std::string name() const { return theName; }
    Date birthDate() const { return theBirthDate; }
    Address address() const { return theAddress; }

private:
    std::string theName;
    Date theBirthDate;
    Address theAddress;
};

class Person
{
public:
    Person(const std::string &name, const Date &birthday, const Address &addr);

    std::string name() const { return pImpl->name(); }
    Date birthDate() const { return pImpl->birthDate(); }
    Address address() const { return pImpl->address(); }

private:
    std::shared_ptr<PersonImpl> pImpl; // 再次使用到pImpl手法
};
