/**
****************************************************************************************
* @FilePath: item_39.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-02-01 10:13:41
* @LastEditors: Modest Wang
* @LastEditTime: 2024-02-01 10:13:41
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 明智而审慎地使用private继承
****************************************************************************************
*/

// 通常来说，public继承意味着is-a关系
// 显然，private继承并不意味着is-a关系，它意味着is-implemented-in-terms-of关系

class Timer
{
public:
    explicit Timer(int tickFrequency);
    virtual void onTick() const;
};

class Widget_1 : private Timer
{
public:
    virtual void onTick() const;
};

class Widget_2
{
private:
    class WidgetTimer : public Timer
    {
    public:
        virtual void onTick() const;
    };
    WidgetTimer timer;
};
