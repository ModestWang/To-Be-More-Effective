/**
****************************************************************************************
* @FilePath: item_35.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-02-01 10:10:48
* @LastEditors: Modest Wang
* @LastEditTime: 2024-02-01 10:10:48
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 考虑virtual函数以外的其他选择
****************************************************************************************
*/

#include <iostream>
#include <functional>

// 由 non-virtual interface (NVI) 手法实现 Template Method 模式
// 注意：Template Method 模式是一种行为设计模式，它定义了一组算法的骨架，将一些步骤推迟到子类中实现。
class GameCharacter_1
{
public:
    int healthValue() const
    {
        int retVal = doHealthValue(); // doHealthValue编译时与子类对象动态绑定
        // ...其他操作
        return retVal;
    }

private:
    virtual int doHealthValue() const
    {
        // ...其他操作
        return 0;
    }
};

// 由 fuction pointer 实现 Strategy 模式
// 注意：Strategy 模式是一种行为设计模式，它定义了一系列算法，将每一个算法封装起来，并使它们可以互相替换。
class GameCharacter_2;
int defaultHealthCalc(const GameCharacter_2 &gc)
{
    // ...其他操作
    return 0;
}

class GameCharacter_2
{
public:
    // 使用std::function代替函数指针
    typedef std::function<int(const GameCharacter_2 &)> HealthCalcFunc; // HealthCalcFunc是一个函数对象
    // typedef int (*HealthCalcFunc)(const GameCharacter_2 &); // HealthCalcFunc是一个指向函数的指针
    explicit GameCharacter_2(HealthCalcFunc hcf = defaultHealthCalc)
        : healthFunc(hcf)
    {
    }

    void setHealthCalcFunc(HealthCalcFunc hcf)
    {
        healthFunc = hcf;
    }

    int healthValue() const
    {
        return healthFunc(*this); // healthFunc编译时与子类对象动态绑定
    }

private:
    HealthCalcFunc healthFunc;
};

class EvilBadGuy : public GameCharacter_2
{
public:
    explicit EvilBadGuy(HealthCalcFunc hcf = defaultHealthCalc)
        : GameCharacter_2(hcf)
    {
    }
};

int loseHealthQuickly(const GameCharacter_2 &gc)
{
    // ...其他操作
    return 1;
}

int loseHealthSlowly(const GameCharacter_2 &gc)
{
    // ...其他操作
    return 2;
}

int main()
{
    EvilBadGuy ebg(loseHealthQuickly);
    ebg.setHealthCalcFunc(loseHealthSlowly);

    EvilBadGuy ebg_1(
        std::bind(loseHealthQuickly, std::placeholders::_1) // 使用std::bind绑定函数
        // std::placeholders::_1 是占位符，表示传入的第一个参数
    );

    return 0;
}

// 当你解决问题而寻找某个设计方法时，不妨考虑viirtual函数的替代方案。
