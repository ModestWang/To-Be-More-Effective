/**
****************************************************************************************
* @FilePath: item_13.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-28 17:16:01
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-28 17:16:01
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 使用对象管理资源
****************************************************************************************
*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Investment
{
public:
    Investment()
    {
        std::cout << "Investment::Investment()" << std::endl;
    }
    ~Investment()
    {
        std::cout << "Investment::~Investment()" << std::endl;
    }
};
/**
****************************************************************************************
* @brief: 创建Investment对象
* @return
****************************************************************************************
*/
Investment *createInvestment()
{
    return new Investment();
}
// void f()
// {
//     Investment *pInv = createInvestment();
//     // ...
//     delete pInv;
// } // 一旦忘记delete，就会造成内存泄漏

/**
****************************************************************************************
* @brief: 使用智能指针
* @return
****************************************************************************************
*/
void f()
{
    std::unique_ptr<Investment> pInv1(createInvestment());

    std::unique_ptr<Investment> plnv2(std::make_unique<Investment>(*pInv1));
    //     std::unique_ptr<Investment> pInv2(pInv1);
    //     pInv1 = pInv2;
}

int main(int argc, char *argv[])
{
    f();
}
