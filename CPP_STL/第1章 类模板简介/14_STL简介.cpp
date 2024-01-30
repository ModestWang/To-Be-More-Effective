/**
****************************************************************************************
* @FilePath: 14_STL简介.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-30 17:55:21
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-30 17:55:33
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: STL: Standard Template Library 标准模板库
* 在C++标准中，STL被组织为一下13个头文件：
*   <algorithm> <deque> <functional> <iterator> <list> <map> <memory> <numeric> <queue>
*   <set> <stack> <utility> <vector>
* STL的六大组件：
*   1.容器(Container)：各种数据结构，如vector、list、deque、set、map等，用来存放数据
*   2.算法(Algorithm)：各种常用的算法，如sort、find、copy、for_each等
*   3.迭代器(Iterator)：扮演了容器与算法之间的胶合剂
*   4.仿函数(Functor)：行为类似函数，可作为算法的某种策略
*   5.适配器(Adapter)：一种用来修饰容器或者仿函数或迭代器接口的东西
*   6.空间配置器(Allocator)：负责空间的配置与管理
* STL的优点：
*   1.高可重用性：STL的六大组件都是独立的，可以重复使用
*   2.高性能：STL的六大组件都是用模板实现的，可以进行代码优化
*   3.高移植性：STL的六大组件都是独立的，可以在不同的平台上使用
* STL的缺点：
*   1.对初学者不友好：STL的六大组件都是用模板实现的，初学者不容易理解
*   2.效率问题：STL的六大组件都是用模板实现的，效率不一定高
*   3.代码可读性差：STL的六大组件都是用模板实现的，可读性差
****************************************************************************************
*/

// STL的基本观念是将数据和操作分离，数据由容器管理，操作由算法完成
// 迭代器在二者之间充当了胶合剂的作用，算法和容器都不需要知道彼此的细节，只需要通过迭代器进行交互

// STL中的<容器>分为序列式容器和关联式容器
//  序列式容器：强调值的排序，序列式容器中的每个元素均有固定的位置，容器中的位置决定了元素的值
//      序列式容器包括：vector、list、deque、stack、queue、heap、priority_queue
//  关联式容器：强调值的关联，关联式容器中的每个元素都有一个键值(key)，容器中的位置不决定元素的值
//      关联式容器包括：set、multiset、map、multimap

// STL中的<算法>分为质变算法和非质变算法
//  质变算法：指运算过程中会更改区间内的元素的内容，例如拷贝、替换、删除等
//  非质变算法：指运算过程中不会更改区间内的元素的内容，例如查找、计数、遍历、寻找极值等

// STL中的<迭代器>分为输入迭代器、输出迭代器、前向迭代器、双向迭代器、随机访问迭代器
//  输入迭代器：只读，支持++、==、!=、*、->
//  输出迭代器：只写，支持++
//  前向迭代器：读写，支持++、==、!=、*、->
//  双向迭代器：读写，支持++、--、==、!=、*、->
//  随机访问迭代器：读写，支持++、--、==、!=、*、->、[n]、-n、<、<=、>、>=

// STL中的<仿函数>分为一元仿函数和二元仿函数
//  一元仿函数：接受一个参数
//  二元仿函数：接受两个参数

// STL中的<适配器>分为容器适配器和迭代器适配器
//  容器适配器：stack、queue、priority_queue
//  迭代器适配器：insert_iterator、reverse_iterator、istream_iterator、ostream_iterator

// STL中的<空间配置器>分为一级空间配置器和二级空间配置器
//  一级空间配置器：直接使用malloc()和free()，不具备任何复杂行为
//  二级空间配置器：视情况而定，使用malloc()和free()或者使用自己的内存池

// 综合示例
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(5);
    vec.push_back(4);

    cout << "original vec: ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        cout << *it << " ";
    cout << endl;

    sort(vec.begin(), vec.end());
    cout << "sorted vec: ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
