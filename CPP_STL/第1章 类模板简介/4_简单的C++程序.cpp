/**
****************************************************************************************
* @FilePath: 4_简单的C++程序.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-30 11:43:21
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-30 12:49:00
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion:
****************************************************************************************
*/

#include <iostream>
#include <list>
#include <string.h>

struct Person
{
    int id;
    int age;
    void init()
    {
        id = 0;
        age = 0;
    }
};

int main()
{
    Person temp;
    std::list<Person> person_list; // 注意前面要加std::
    int id_temp;
    int age_temp;
    temp.init();
    int counter = 0;
    std::cout << "This is a simple C++ program." << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.get();

    // 输入3个人的信息
    while (counter < 3)
    {
        std::cout << "Please input the id of the person:";
        std::cin >> id_temp;
        std::cout << "Please input the age of the person:";
        std::cin >> age_temp;
        std::cout << std::endl;
        temp.id = id_temp;
        temp.age = age_temp;
        person_list.push_back(temp);
        memset(&temp, 0, sizeof(temp));
        counter++;
    }
    std::cout << "Press Enter to continue..." << std::endl;
    std::cin.get();

    // 输出3个人的信息
    std::list<Person>::iterator iter;
    for (iter = person_list.begin(); iter != person_list.end(); iter++) // 注意这里的写法
    {
        std::cout << "The id of the person is: " << iter->id << std::endl;
        std::cout << "The age of the person is: " << iter->age << std::endl;
        std::cout << std::endl;
    }
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.get();

    return 0;
}
