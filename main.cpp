#include<iostream>
using namespace std;

template<class ElemType>
struct Node
{
    ElemType data;//数据域
    Node<ElemType>* next;//指针域

    Node()//无参构造函数
    {
        next = NULL;
    }

    Node(ElemType item, Node<ElemType>* link = NULL)//有参构造函数
    {
        data = item;
        next = link;
    }
};

template<class ElemType>
class SimpleLinkList
{
protected:
	Node<ElemType>* head;//头结点指针
    Node<ElemType>* GetElemPtr(int pos) const;//返回指向pos位置结点的指针
public:
	SimpleLinkList();//无参构造
	~SimpleLinkList();//析构
    int Length() const;//求长度
    bool Empty() const;//判断是否为空
    void Clear();//清空线性表
    void Traverse() const;//遍历
    bool GetElem(int pos, ElemType& e) const;
    bool SetElem(int pos, ElemType& e);
    bool Delete(int pos, ElemType& e);
    bool Insert(int pos, const ElemType& e);
    SimpleLinkList(const SimpleLinkList<ElemType>& copy);
    SimpleLinkList<ElemType>& operator=(const SimpleLinkList<ElemType>& copy);
};

template<class ElemType>
Node<ElemType>* SimpleLinkList<ElemType>::GetElemPtr(int pos) const
{
    Node<ElemType>* ptr = head;
    int c = 0;
    while (c < pos)
    {
        ptr = ptr->next;
        c++;
    }
    return ptr;
}

template<class ElemType>
SimpleLinkList<ElemType>::SimpleLinkList()
{
    head = new Node<ElemType>;
}

template<class ElemType>
bool SimpleLinkList<ElemType>::Empty() const
{
    if (head->next == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class ElemType>
void SimpleLinkList<ElemType>::Clear()
{
    ElemType t;
    while (!Empty())
    {
        Delete(1, t);//如果不空，从链表头（1）开始删除，直到清空
    }
}

template<class ElemType>
SimpleLinkList<ElemType>::~SimpleLinkList()
{
    Clear();
    delete head;
}

template<class ElemType>
bool SimpleLinkList<ElemType>::Insert(int pos, const ElemType& e)
{
    if (pos < 1 || pos > count+1)
    {
        return false;
    }
    else
    {
        Node<ElemType>* tPtr, newtPtr;
        tPtr = GetElem(pos - 1);//取出pos位置前一位的指针
        newtPtr = new Node<ElemType>(e);//生成新结点
        newtPtr->next = tPtr->next;
        tPtr->next = newtPtr;//将newPtr插入链表
        return true;
    }
}

int main()
{

	return 0;
}