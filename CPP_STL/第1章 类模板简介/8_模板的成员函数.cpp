/**
****************************************************************************************
* @FilePath: 8_模板的成员函数.cpp
* @Author: Modest Wang 1598593280@qq.com
* @Date: 2024-01-30 13:04:52
* @LastEditors: Modest Wang
* @LastEditTime: 2024-01-30 13:04:53
* @2024 by Modest Wang, All Rights Reserved.
* @Descripttion:
****************************************************************************************
*/

#include <iostream>

template <class T>
class Queue
{
public:
    Queue();
    ~Queue();
    bool empty() const;
    T &front();
    T &back();
    void pop();
    void push(const T &val);

private:
    void destroy();
};
template <class T>
Queue<T>::Queue()
{
}

template <class T>
Queue<T>::~Queue()
{
    destroy();
}

template <class T>
bool Queue<T>::empty() const
{
    return false;
}

template <class T>
T &Queue<T>::front()
{
    return T();
}

template <class T>
T &Queue<T>::back()
{
    return T();
}

template <class T>
void Queue<T>::pop()
{
}

template <class T>
void Queue<T>::push(const T &val)
{
}

template <class T>
void Queue<T>::destroy()
{
    while(!empty())
        pop();
}

int main(int argc, char *argv[])
{
    Queue<int> q;
    return 0;
}
