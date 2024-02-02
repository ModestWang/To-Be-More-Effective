/**
****************************************************************************************
* @FilePath: item_29.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-31 19:00:47
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-31 19:01:05
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 为"异常安全"而努力是值得的
****************************************************************************************
*/

#include <iostream>

class Mutex
{
public:
    bool isLocked = false;
};

class Image
{
public:
    Image(std::istream &imgSrc) {}
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

class Lock
{
public:
    explicit Lock(Mutex *pm) : mutexPtr(pm, unlock)
    {
        lock(mutexPtr.get());
    }

private:
    std::shared_ptr<Mutex> mutexPtr;
};

class PrettyMenu_1
{
public:
    void changeBackground_1(std::istream &imgSrc);
    void changeBackground_2(std::istream &imgSrc);

private:
    Mutex mutex;
    Image *bgImage;
    int imageChanges;
};

// 异常不安全函数
void PrettyMenu_1::changeBackground_1(std::istream &imgSrc)
{
    lock(&mutex); // 获取互斥锁
    delete bgImage;
    ++imageChanges;
    bgImage = new Image(imgSrc);
    // 那么，如果new Image(imgSrc)抛出异常，会发生什么事情呢？
    // 1. imageChanges的值会被增加，但是bgImage的值不会被改变
    // 2. 互斥锁mutex会被永远锁住
    // 这样既造成了资源泄露，又损坏了数据
    unlock(&mutex); // 释放互斥锁
}

// 异常不安全函数
void PrettyMenu_1::changeBackground_2(std::istream &imgSrc)
{
    Lock ml(&mutex); // 使用智能指针解决了锁的释放问题
    delete bgImage;  // 但是仍然存在资源损坏问题
    ++imageChanges;
    bgImage = new Image(imgSrc);
    unlock(&mutex);
}

class PrettyMenu_2
{
public:
    void changeBackground(std::istream &imgSrc);

private:
    Mutex mutex;
    std::shared_ptr<Image> bgImage;
    int imageChanges;
};

// 异常安全函数
void PrettyMenu_2::changeBackground(std::istream &imgSrc)
{
    using std::swap;
    Lock ml(&mutex);
    std::shared_ptr<Image> pNew(new Image(imgSrc));
    swap(pNew, bgImage);
    ++imageChanges;
}

// 异常安全函数(Exception-safe function)
// 1. 基本承诺：如果异常被抛出，程序内的任何事物仍然保持在有效状态下
// 2. 强烈保证：如果异常被抛出，程序状态不改变，也不调用任何非局部对象的析构函数
// 3. 不抛掷异常：承诺绝不抛出异常

// copy-and-swap技术
