#include<iostream>
using namespace std;

template<class ElemType>
struct Node
{
    ElemType data;//������
    Node<ElemType>* next;//ָ����

    Node()//�޲ι��캯��
    {
        next = NULL;
    }

    Node(ElemType item, Node<ElemType>* link = NULL)//�вι��캯��
    {
        data = item;
        next = link;
    }
};

template<class ElemType>
class SimpleLinkList
{
protected:
	Node<ElemType>* head;//ͷ���ָ��
    Node<ElemType>* GetElemPtr(int pos) const;//����ָ��posλ�ý���ָ��
public:
	SimpleLinkList();//�޲ι���
	~SimpleLinkList();//����
    int Length() const;//�󳤶�
    bool Empty() const;//�ж��Ƿ�Ϊ��
    void Clear();//������Ա�
    void Traverse() const;//����
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
        Delete(1, t);//������գ�������ͷ��1����ʼɾ����ֱ�����
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
        tPtr = GetElem(pos - 1);//ȡ��posλ��ǰһλ��ָ��
        newtPtr = new Node<ElemType>(e);//�����½��
        newtPtr->next = tPtr->next;
        tPtr->next = newtPtr;//��newPtr��������
        return true;
    }
}

int main()
{

	return 0;
}