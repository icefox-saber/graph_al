#pragma once
#include "header.h"
using namespace std;

template <class elemType>
class seqQueue
{
private:
    elemType *array;//储存元素的数组
    int maxSize;//实际储存元素个数为maxSize-1
    int front = 0, rear = -1; // front为队头index，tear为队尾index，进队tear++%maxSize，出队front++%maxSize
    void doubleSpace();       // 拓展队列元素的储存空间为原来的2倍
    int length = 0;

public:
    // 初始化
    seqQueue(int size = 100);                        
    // 队空返回true，否则false                                    
    bool isEmpty() const { return (front == (rear + 1) % maxSize); };   //或者length==0         
    // 队满返回true，否则false（队满为剩下一个位置）
    bool isFull() const { return (front == (rear + 2) % maxSize); }; //或者length==maxSize-1
    // 返回队首元素
    elemType getFront() const { return array[front]; };      
    //返回队头下标                        
    int frontIndex() const { return front; };
    //返回队尾下标
    int tearIndex() const { return rear; };
    //返回MaxSize
    int getMaxSize() const { return maxSize; };
    //返回队伍长度
    int getLength() const { return length; };
    // e进队
    void enQueue(const elemType &e); 
    // 队首出队
    void deQueue();                 
    // 析构 
    ~seqQueue();                     
};
template <class elemType>
void seqQueue<elemType>::doubleSpace()
{
    elemType *tmp;
    int i, j;

    tmp = new elemType[2 * maxSize];
    if (!tmp)
        throw illegalSize();

    for (i = 0, j = front; j != rear + 1; i++, j = (j + 1) % maxSize)
    {
        tmp[i] = array[j];
    }
    delete[] array;
    array = tmp;
    front = 0;
    rear = i - 1;
    maxSize *= 2;
}
template <class elemType>
seqQueue<elemType>::seqQueue(int size)
{
    array = new elemType[size];
    if (!array)
        throw illegalSize();
    maxSize = size;
}

template <class elemType>
void seqQueue<elemType>::enQueue(const elemType &e)
{
    if (isFull())
        doubleSpace();
    rear = (rear + 1) % maxSize;
    array[rear] = e;
    length++;
}

template <class elemType>
void seqQueue<elemType>::deQueue()
{
    if (isEmpty())
        throw outOfBound();
    front = (front + 1) % maxSize;
    length--;
}
template <class elemType>
seqQueue<elemType>::~seqQueue()
{
    delete[] array;
}


