#pragma once
#include "header.h"
using namespace std;

template <class elemType>
class seqStack
{
private:
    elemType *array;    // 数组指针
    int topIndex;       // 栈顶下标
    int maxSize;        // 栈容量
    // 栈扩容为原来的两倍
    void doublespace(); 
public:
    // 初始化
    seqStack(int initSize = 100);                      
    // 栈空返回true，否则返回false
    bool isEmpty() const { return (topIndex == -1); }; 
    // 栈满返回true，否则返回false
    bool isFull() const { return (topIndex == maxSize - 1); };
    // 返回栈顶元素
    elemType top() const;         
    // 将元素e压入栈顶，使其成为新栈顶
    void push(const elemType &e); 
    // 将栈顶元素弹出
    void pop();                   
    //析构
    ~seqStack() { delete[] array; };
};

// 栈扩容为原来的两倍
template <class elemType>
void seqStack<elemType>::doublespace() 
{
    elemType *tmp;
    tmp = new elemType[2 * maxSize];
    if (!tmp)
        throw illegalSize();
    for (int i = 0; i < maxSize; i++)
    {
        *(tmp + i) = *(array + i);
    }
    delete[] array;
    array = tmp;
    maxSize *= 2;
}

template <class elemType>
seqStack<elemType>::seqStack(int initSize) // 初始化
{
    array = new elemType[initSize];
    if (!array)
        throw illegalSize();
    maxSize = initSize;
    topIndex = -1;
}

template <class elemType>
elemType seqStack<elemType>::top() const // 返回栈顶元素
{
    if (isEmpty())
        throw outOfBound();
    return *(array + topIndex);
}

template <class elemType>
void seqStack<elemType>::push(const elemType &e) // 将元素e压入栈顶，使其成为新栈顶
{
    if (isFull())
        doublespace();
    topIndex++;
    *(array + topIndex) = e;
}

template <class elemType>
void seqStack<elemType>::pop() // 将栈顶元素弹出
{
    if (isEmpty())
        throw outOfBound();
    topIndex--;
}
