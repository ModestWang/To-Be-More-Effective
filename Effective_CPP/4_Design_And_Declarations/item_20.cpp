/**
****************************************************************************************
* @FilePath: item_20.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-31 11:07:33
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-31 11:07:33
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 宁以pass-by-reference-to-const替换pass-by-value
****************************************************************************************
*/

#include <iostream>
#include <string>

class Person
{
public:
    Person() {}
    virtual ~Person() {} // 为了让派生类的析构函数能被调用，基类的析构函数必须是虚函数

private:
    std::string _name;
    std::string _address;
};

class Student : public Person
{
public:
    Student() {}
    ~Student() {}

private:
    std::string _schoolName;
    std::string _schoolAddress;
};

// 传值方式调用validateStudent函数
// bool validateStudent(Student s)
// {
//     // do something
//     return true;
// }

// 为了避免不必要的拷贝构造和析构操作，可以将validateStudent函数的参数改为const Student& s
bool validateStudent(const Student &s)
{
    // do something
    return true;
}

int main(int argc, char *argv[])
{
    Student John;
    bool isOK = validateStudent(John);
    // bool isOK = validateStudent(John);
    // 1.调用validateStudent时，会调用Student的拷贝构造函数，将John拷贝一份给s
    // 2.调用validateStudent时，会调用Student的析构函数，销毁s
    // 3.然而，Student对象中有两个string对象，这两个string对象的拷贝构造函数和析构函数也会被调用
    // 4.此外，Student对象继承自Person对象，所以每次构造Student对象时也必须构造Person对象，Person对象中的string对象也会被构造和析构
    // 5.所以，validateStudent函数的调用会导致至少6次构造和析构操作!!!

    // 如果validateStudent函数的参数是const Student& s，那么就不会有拷贝构造和析构操作了，而且还能保证validateStudent函数不会修改s
    return 0;
}

// 尽量以pass-by-reference-to-const替换pass-by-value。前者通常比较高效，并可避免切割问题（slicing problem）

// 以上规则并不适用于内置类型，以及STL的迭代器和函数对象。对它们而言，pass-by-value往往比较适当
