/**
****************************************************************************************
* @FilePath: item_26.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-31 18:59:54
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-31 18:59:54
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 尽可能延后变量定义式的出现时间
****************************************************************************************
*/

#include <iostream>
#include <string>

std::string encryptPassword_1(const std::string &password)
{
    std::string encrypted;
    // ... encrypt password ...
    if (password.length() < 6)
    {
        throw std::logic_error("Password is too short");
    } // 如果抛出异常，就要多承受encrypted构造和析构的开销
    return encrypted;
}

std::string encryptPassword_2(const std::string &password)
{
    // ... encrypt password ...

    if (password.length() < 6)
    {
        throw std::logic_error("Password is too short");
    }
    std::string encrypted; // 定义式延后，直到需要时才定义
    return encrypted;
}

// 尽可能延后变量定义式的出现时间，可以增加程序的清晰度和效率
