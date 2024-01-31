/**
****************************************************************************************
* @FilePath: item_14.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-28 17:54:29
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-28 17:54:30
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 在资源管理类中小心copying行为
****************************************************************************************
*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Mutex // 互斥量类
{
public:
    bool isLocked = false;
};

void lock(Mutex *pm) // 锁定互斥量
{
    pm->isLocked = true;
    std::cout << "lock" << std::endl;
}

void unlock(Mutex *pm) // 解锁互斥量
{
    pm->isLocked = false;
    std::cout << "unlock" << std::endl;
}

// class Lock // 互斥量锁定类
// {
// public:
//     explicit Lock(Mutex *pm) : mutexPtr(pm) // 构造函数
//     {
//         lock(mutexPtr); // 在此处锁定互斥量
//     }
//     ~Lock() // 析构函数
//     {
//         unlock(mutexPtr); // 在此处解锁互斥量
//     }

// private:
//     Mutex *mutexPtr; // 使用shared_ptr来管理Mutex对象
// };
/*
lock
unlock
unlock
*/

class Lock // 互斥量锁定类
{
public:
    explicit Lock(Mutex *pm) : mutexPtr(pm, unlock) // 构造函数
    {
        lock(mutexPtr.get()); // 在此处锁定互斥量
    }

private:
    std::shared_ptr<Mutex> mutexPtr; // 使用shared_ptr来管理Mutex对象
};
/*
lock
unlock
*/

Mutex m; // 互斥量

int main(int argc, char *argv[])
{

    Lock ml1(&m);  // 正确，Lock对象可正常构造
    Lock ml2(ml1); // 错误，Lock对象不可拷贝
    return 0;
}
