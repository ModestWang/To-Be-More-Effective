/**
****************************************************************************************
* @FilePath: item_19.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-30 22:02:14
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-30 22:02:14
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion: 设计class犹如设计type
****************************************************************************************
*/

/* 如何设计高效的classes呢？首先你必须了解你面对的问题 */

// 1.新type的对象应该如何被创建和销毁？
// 2.对象的初始化和对象的赋值该有什么样的差别？
// 3.新type的对象如果被passed by value(传值)，意味着什么？
// 4.什么是新type的“合法值”(valid values)？
// 5.你的新type需要配合某个继承图系(inheritance graph)？如果是，该继承图系应该是怎样的？
// 6.你的新type需要什么样的转换？
// 7.什么样的操作符和函数对于你的新type而言是合理的？
// 8.什么样的标准函数应该驳回？
// 9.谁该取用新type的成员？
// 10.什么是新type的“未声明接口”(undeclared interface)？
// 11.你的新type有多么一般化(generalized)？
// 12.你真的需要一个新type吗？
