/**
****************************************************************************************
* @FilePath: item_18.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-28 19:33:48
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-28 19:33:48
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 让接口容易被正确使用，不易被误用
****************************************************************************************
*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>

struct Day
{
    explicit Day(int d) : val(d) {}
    int val;
};

// struct Month
// {
//     explicit Month(int m) : val(m) {}
//     int val;
// };

// 但是enum不具备我们希望拥有的类型安全性
class Month
{
public:
    int val;
    static Month Jan() { return Month(1); }
    static Month Feb() { return Month(2); }
    static Month Mar() { return Month(3); }
    static Month Apr() { return Month(4); }
    static Month May() { return Month(5); }
    //...

private:
    explicit Month(int m)
    {
        if (m < 1 || m > 12)
        {
            throw std::out_of_range("Month value is out of range");
        }
        val = m;
    }
};

struct Year
{
    explicit Year(int y) : val(y) {}
    int val;
};

class Date
{
public:
    Date(Year year, Month month, Day day) : _year(year), _month(month), _day(day)
    {
    }

    void show()
    {
        std::cout << _year.val << "-" << _month.val << "-" << _day.val << std::endl;
    }

private:
    Year _year;
    Month _month;
    Day _day;
};

int main(int argc, char **argv)
{
    // Year year(2024);
    // Month month(1);
    // Day day(27);
    // Date date(year, month, day); // 无法通过编译，因为Date的构造函数是explicit的
    // 但是如果我不知道顺序，又不想犯错误
    // 例如:如果参数类型都是int型时,将月份和年份参数搞反是没有报错
    // 这样显然是会出错误的，但是编译器不会给你指出来，导致接口误用
    // 为了避免这种情况，可以使用命名参数
    // Date date2(Day(27), Month(1), Year(2024)); // 无法通过编译，因为Date的构造函数是explicit的
    // 另外，为了避免像13月这种错误，可以使用枚举类型
    // enum class Month2
    // {
    //     Jan = 1,
    //     Feb,
    //     Mar,
    //     Apr,
    //     May,
    //     Jun,
    //     Jul,
    //     Aug,
    //     Sep,
    //     Oct,
    //     Nov,
    //     Dec,
    //     max = Dec
    // };
    // 然而使用枚举类型也有缺点

    Date date2(Year(2024), Month::Jan(), Day(30));
    date2.show();

    return 0;
}
