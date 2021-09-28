#include <iostream>
using namespace std;

template <class ElemType>
struct Node
{
    ElemType data;        //数据域
    Node<ElemType> *next; //指针域

    Node() //无参构造函数
    {
        next = nullptr;
    }

    Node(ElemType item, Node<ElemType> *link = nullptr) //有参构造函数
    {
        data = item;
        next = link;
    }
};

template <class ElemType>
class SimpleLinkList
{
protected:
    Node<ElemType> *head;                     //头节点指针
    Node<ElemType> *GetPosPtr(int pos) const; //获取欲求位置指针
public:
    SimpleLinkList();
    ~SimpleLinkList();
    int Length() const;
    bool Empty() const;
    void Clear();
    void Traverse() const;
    bool GetElem(int pos, ElemType &e) const;
    bool SetElem(int pos, const ElemType &e) const;
    bool Delete(int pos, ElemType &e);
    bool Insert(int pos, const ElemType &e);
    SimpleLinkList(const SimpleLinkList<ElemType> &copy);
    SimpleLinkList<ElemType> &operator=(const SimpleLinkList<ElemType> &copy);
};

template <class ElemType>
Node<ElemType> *SimpleLinkList<ElemType>::GetPosPtr(int pos) const
{
    Node<ElemType> *t = head;
    int a = 0;
    while (a < pos)
    {
        a++;
        t = t->next;
    }
    return t;
}

template <class ElemType>
SimpleLinkList<ElemType>::SimpleLinkList()
{
    head = new Node<ElemType>;
}

template <class ElemType>
SimpleLinkList<ElemType>::~SimpleLinkList()
{
    Clear();
    delete head;
}

template <class ElemType>
int SimpleLinkList<ElemType>::Length() const
{
    Node<ElemType> *a = head->next;
    int length = 0;
    while (a != nullptr)
    {
        length++;
        a = a->next;
    }
    return length;
}

template <class ElemType>
bool SimpleLinkList<ElemType>::Empty() const
{
    if (head->next == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class ElemType>
void SimpleLinkList<ElemType>::Clear()
{
    ElemType t;
    while (!Empty())
    {
        Delete(1, t);
    }
}

template <class ElemType>
void SimpleLinkList<ElemType>::Traverse() const
{
    Node<ElemType> *ptr = head->next;
    while (ptr != nullptr)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

template <class ElemType>
bool SimpleLinkList<ElemType>::SetElem(int pos, const ElemType &e) const
{
    if (pos < 1 || pos > Length())
    {
        return false;
    }
    else
    {
        Node<ElemType> *temPtr;
        temPtr = GetPosPtr(pos);
        temPtr->data = e;
        return true;
    }
}

template <class ElemType>
bool SimpleLinkList<ElemType>::GetElem(int pos, ElemType &e) const
{
    if (pos > 1 || pos > Length())
    {
        return false;
    }
    else
    {
        Node<ElemType> *temPtr;
        temPtr = GetPosPtr(pos);
        e = temPtr->data;
        return true;
    }
}

template <class ElemType>
bool SimpleLinkList<ElemType>::Delete(int pos, ElemType &e)
{
    if (Length() == 0)
    {
        return false;
    }
    if (pos < 1 || pos > Length())
    {
        return false;
    }
    else
    {
        Node<ElemType> *temPtr, *temFrPtr;
        //temPtr = GetPosPtr(pos);
        temFrPtr = GetPosPtr(pos - 1);
        temPtr = temFrPtr->next;
        temFrPtr->next = temPtr->next;
        e = temPtr->data; //用e返回被删除结点的元素值
        delete temPtr;    //释放被删除结点
        return true;
    }
}

template <class ElemType>
bool SimpleLinkList<ElemType>::Insert(int pos, const ElemType &e)
{
    if (pos > Length() + 1 || pos < 1)
    {
        return false;
    }
    else
    {
        Node<ElemType> *newPtr, *temPtr;
        temPtr = GetPosPtr(pos - 1);    //取出指向第pos-1个结点的指针
        newPtr = new Node<ElemType>(e); //生成新结点
        newPtr->next = temPtr->next;
        temPtr->next = newPtr; //将temPtr插入到链表中
        return true;
    }
}

template <class ElemType>
SimpleLinkList<ElemType>::SimpleLinkList(const SimpleLinkList &copy)
{
    Node<ElemType> *p, *r, *q;
    head = new Node<ElemType>;
    p = head;
    q = head->next;
    while (q != nullptr)
    {
        r = new Node<ElemType>(q->data);
        p->next = r;
        p = r;
        q = q->next;
    }
}

template <class ElemType>
SimpleLinkList<ElemType> &SimpleLinkList<ElemType>::operator=(const SimpleLinkList<ElemType> &copy)
{
    ElemType t;
    while (!Empty())
    {
        Delete(1, t);
    }
    delete head;
    Node<ElemType> *p, *q, *r;
    head = new Node<ElemType>;
    p = head->next;
    q = copy.head->next;
    while (q != nullptr)
    {
        r = new Node<ElemType>(q->data);
        p->next = r;
        p = r;
        q = q->next;
    }
}

//A test case.
int main()
{
    SimpleLinkList<int> S1;
    S1.Insert(1, 1);
    S1.Traverse();
    return 0;
}
