/**
****************************************************************************************
* @FilePath: item_23.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-31 14:27:41
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-31 14:27:41
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 宁以non-member、non-friend替换member函数
****************************************************************************************
*/

#include <iostream>
#include <string>

class WebBrowser
{
public:
    void clearCache() { cache = 0; }
    void clearHistory() { history = 0; }
    void removeCookies() { cookies = 0; }
    // ...
    void clearEverything()
    {
        clearCache();
        clearHistory();
        removeCookies();
    } // 许多用户希望一次执行上面三个操作

    // friend void clearBrowser(WebBrowser &wb);

private:
    // ...
    int cache = 0;
    int history = 0;
    int cookies = 0;
};

// 当然这个需求也可以用一个non-member函数实现
void clearBrowser(WebBrowser &wb)
{
    // // 如果声明为友元函数，那么就可以直接访问private成员
    // // 这样就破坏了封装性
    // wb.cache = 0;
    // wb.history = 0;
    // wb.cookies = 0;

    wb.clearCache();
    wb.clearHistory();
    wb.removeCookies();
}

// 那么哪种处理方式比较好呢？

int main()
{
    WebBrowser wb;
    wb.clearEverything();
    clearBrowser(wb);
}
