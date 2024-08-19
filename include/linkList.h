#pragma once
#include "header.h"
using namespace std;
//需要将linkList变得方便 好用 安全
template <class elemType>
class linkList;
template <class elemType>
class linkListNode
{
    friend class linkList<elemType>;

private:
    elemType data;
    linkListNode *next;
    linkListNode() : next(nullptr){};
    linkListNode(const elemType &e, linkListNode *N = nullptr) : data(e), next(N){};
public:
};
 
template <class elemType>
class linkList
{
private:
    linkListNode<elemType> *head;

public:
    linkList();                            // 构造函数，建立空表
    bool isEmpty() const;                  // 空true，否则false
    int length() const;                    // 返回表的长度
    elemType& operator[](int i);             // 返回下标为i的值的引用；
    int find(const elemType &e) const;     // 返回元素值为e的序号，无则返回-1
    void insert(int i, const elemType &e); // 插入e后e的index[]为i
    void exchange();//从头开始两两换位
    void remove(int i);   // 若第i个元素存在，将其删除
    void reverse() const; // 元素就地逆置
    void clear();         // 清空表，使其为空表
    void moveForward(int i, int x);//将下标为i,x以及中间的节点移动至链表首
    void moveBackward(int i, int x);//将下标为i,x以及中间的节点移动至链表尾部
    void show();//展示链表
    ~linkList();//析构
};
template <class elemType>
linkList<elemType>::linkList() // 构造函数，建立空表
{
    head = new linkListNode<elemType>();
}

template <class elemType>
bool linkList<elemType>::isEmpty() const // 空true，否则false
{
    return !head->next;
}

template <class elemType>
int linkList<elemType>::length() const // 返回表的长度
{
    int i = 0;
    linkListNode<elemType> *q = head->next;
    while (q)
    {
        q = q->next;
        i++;
    }
    return i;
}

template <class elemType>
elemType& linkList<elemType>:: operator[](int i) // 返回下标为i的元素的引用；
{
    if (i < 0)
        throw outOfBound(); // i is illegal
    int j = 0;
    linkListNode<elemType> *p = head->next;
    //找到下标为i的节点
    while (p && i - j)
    {
        p = p->next;
        j++;
    }
    
    if (p)
        return p->data;
    else
        throw outOfBound(); // i is bigger than the limit
}

template <class elemType>
int linkList<elemType>::find(const elemType &e) const // 返回元素值为e的序号，无则返回-1
{
    int i = 0;
    linkListNode<elemType> *p = head->next;
    while (p)
    {
        if (p->data == e)
            return i;
        i++;
        p = p->next;
    }
    return -1;
}

template <class elemType>
void linkList<elemType>::insert(int i, const elemType &e) // 插入e后e的下标为i
{
    if (i < 0)
        throw outOfBound();
    int j = -1;
    linkListNode<elemType> *tmp, *p = head;
    while (p && i - j - 1)
    {
        j++;
        p = p->next;
    }
    if (!p)
        throw outOfBound();
    tmp = new linkListNode<elemType>(e, p->next);
    p->next = tmp;
}
template< class elemType>
void linkList<elemType>::exchange()//从头开始两两换位
{
    int i=0,bound=length()-1;
    linkListNode<elemType>*p=head,*q;
    while(i<bound){
        q=p->next;
        p->next=q->next;
        p=q;
        q=p->next;
        p->next=q->next;
        q->next=p;
        i+=2;
    }
}

template <class elemType>
void linkList<elemType>::remove(int i) // 若下标为i的元素存在，将其删除并放入e指向空间
{
    if (i < 0)
        throw outOfBound();
    int j = 0;
    linkListNode<elemType> *tmp, *p = head->next;

    while (p && i - j - 1)
    {
        p = p->next;
        j++;
    }
    if (!p->next)
        throw outOfBound();
    tmp = p->next;
    p->next = tmp->next;
    delete tmp;
}

template <class elemType>
void linkList<elemType>::reverse() const // 元素就地逆置
{
    linkListNode<elemType> *p = head->next, *q;
    head->next = nullptr;
    while (p)
    {
        q = p->next;
        p->next = head->next;
        head->next = p;
        p = q;
    }
}

template <class elemType>
void linkList<elemType>::clear() // 清空表，使其为空表
{
    linkListNode<elemType> *p = head->next, *q;
    head->next = nullptr;
    while (p)
    {
        q = p->next;
        delete p;
        p = q;
    }
}

template <class elemType>
void linkList<elemType>::moveForward(int i, int x)//将下标为i,x以及中间的节点移动至队尾
{
    if(!(i>=0&&x>=i))
        throw outOfBound();
    int ind = 0;
    linkListNode<elemType> *p = head->next, *q, *tmp;
    //找到下标为i-1的节点
    while (ind < i-1)
    {
        ind++;
        p = p->next;
    }
    q = p;
    //找到下标为x的节点
    while (ind < x)
    {
        q = q->next;
        ind++;
    }
    tmp = p->next;
    p->next = q->next;
    q->next = head->next;
    head->next = tmp;
}
template <class elemType>
void linkList<elemType>::moveBackward(int i, int x)//将下标为i,x以及中间的节点移动至队尾
{
    if(!(i>=0&&x>=i))
        throw outOfBound();
    int ind = 0;
    linkListNode<elemType> *p = head->next, *q, *tmp;
    //找到下标为i-1的节点
    while (ind < i-1)
    {
        ind++;
        p = p->next;
    }
    q = p;
    //找到下标为x的节点
    while (ind < x)
    {
        q = q->next;
        ind++;
    }
    tmp = p->next;
    p->next = q->next;
    q->next = nullptr;
    while(q->next)
        q=q->next;
    q->next=tmp;
}
template <class elemType>
void linkList<elemType>::show()
{
    linkListNode<elemType> *p = head->next;
    while (p)
    {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}
template <class elemType>
linkList<elemType>::~linkList()
{
    clear();
    delete head;
}


