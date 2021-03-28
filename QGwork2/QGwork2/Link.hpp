#include<iostream>
#include<string>

using namespace std;

template<class T>
struct DLNode
{
    T data;
    DLNode<T>* next;
    DLNode<T>* prior;
};
//双向循环链表类模板
template <typename T>
class DLinkList
{
public:
    DLinkList();
    DLinkList(T elem);
    DLinkList(int n, T elem);
    ~DLinkList();
    void ClearList() const;
    bool Empty() const;
    int Length() const;
    T GetElem(int n) const;
    int LocateElem(T elem) const;
    bool Insert(int n, T elem);
    bool Delete(int n);
    void Displasy();
    void DisplasyL();
    void Remove(T elem);
private:
    DLNode<T>* m_head;
};




template <typename T>
DLinkList<T>::DLinkList()
{
    //创建头节点
    m_head = new DLNode < T >;
    if (nullptr == m_head)
    {
        cout << "动态申请头节点内存失败" << endl;
        return;
    }

    m_head->next = m_head;
    m_head->prior = m_head;
}

template <typename T>
DLinkList<T>::DLinkList(T elem) :DLinkList()
{
    Insert(1, elem);
}

template <typename T>
DLinkList<T>::DLinkList(int n, T elem) :DLinkList()
{
    for (int i = 0; i < n; ++i)
    {
        Insert(i, elem);
    }
}

template <typename T>
DLinkList<T>::~DLinkList()
{
    ClearList();    //置为空白
    delete m_head;  //释放头节点
}

template <typename T>
void DLinkList<T>::ClearList() const        //常成员函数 不改变对象的值
{
    DLNode<T>* temp, * p = m_head->next;

    while (p != m_head)     //删除头节点以后的所有节点
    {
        temp = p->next;
        delete p;           //要释放动态内存
        p = temp;
    }

    m_head->next = m_head;
    m_head->prior = m_head;
}

template <typename T>
bool DLinkList<T>::Empty() const
{
    //如果头节点的下一个节点为空，则该链表为空
    return m_head == m_head->next;
}

template <typename T>
int DLinkList<T>::Length() const
{
    int count = 0;
    DLNode<T>* ptemp = m_head->next;

    while (ptemp != m_head)
    {
        count++;
        ptemp = ptemp->next;
    }

    return count;
}

template <typename T>
T DLinkList<T>::GetElem(int n) const
{
    DLNode<T>* ptemp = m_head->next;

    if (n <= Length())
    {
        for (int i = 1; i < n; ++i)
        {
            ptemp = ptemp->next;
        }
    }
    else
    {
        cout << "out of ranger" << endl;
        return false;
    }

    return ptemp->data;
}

template <typename T>
int DLinkList<T>::LocateElem(T data) const
{
    size_t location = 0;
    DLNode<T>* ptemp = m_head->next;

    while (ptemp != m_head)
    {
        ++location;
        if (ptemp->data == data)            //注意 该类型必须支持 == 操作符，如果不支持需要进行运算符重载
        {
            return location;
        }

        ptemp = ptemp->next;
    }

    return 0;       //返回0表示未找到
}

template <typename T>
bool DLinkList<T>::Insert(int n, T elem)
{
    DLNode<T>* ptemp = m_head;

    if (n - 1 <= Length())
    {
        for (int i = 0; i < n - 1; ++i)
        {
            ptemp = ptemp->next;
        }

        //先生成一个新的节点
        DLNode<T>* newnode = new DLNode < T >;
        if (nullptr == newnode)
        {
            cout << "申请空间失败" << endl;
            return false;
        }

        newnode->data = elem;       //如果数据类型不是基本数据类型，即不支持 = 操作符，需要重载 = 操作符


        newnode->next = ptemp->next;
        newnode->prior = ptemp;

        ptemp->next->prior = newnode;
        ptemp->next = newnode;

        return true;
    }
    else
    {
        cout << "out of range" << endl;
        return false;
    }
}

template <typename T>
bool DLinkList<T>::Delete(int n)
{
    DLNode<T>* ptemp = m_head;

    if (n <= Length())
    {
        for (int i = 0; i < n - 1; ++i)
        {
            ptemp = ptemp->next;
        }

        DLNode<T>* t = ptemp->next;     //指向待删除的节点

        ptemp->next = ptemp->next->next;        //将待删除节点的上一节点指向待删除节点的下一节点
        ptemp->next->next->prior = ptemp;

        delete t;       //释放删除节点的内存

        return true;
    }
    else
    {
        cout << "out of range" << endl;
        return false;
    }
}

template <typename T>
void DLinkList<T>::Displasy()
{
    DLNode<T>* ptemp = m_head->next;

    while (ptemp != m_head)
    {
        cout << ptemp->data << "  ";
        ptemp = ptemp->next;
    }
    cout << endl;
}

template <typename T>
void DLinkList<T>::DisplasyL()
{
    DLNode<T>* ptemp = m_head->prior;

    while (ptemp != m_head)
    {
        cout << ptemp->data << "  ";
        ptemp = ptemp->prior;
    }
    cout << endl;
}

template <typename T>
void DLinkList<T>::Remove(T elem)
{
    DLNode<T>* ptemp = m_head;

    while (ptemp->next != m_head)
    {
        if (ptemp->next->data == elem)          //找到与要删除的节点相同
        {
            DLNode<T>* t = ptemp->next;     //指向待删除的节点
            ptemp->next = ptemp->next->next;        //将待删除节点的上一节点指向待删除节点的下一节点
            delete t;       //释放删除节点的内存
        }
        else        //这里需要注意一下：如果删除了那么它的下一节点是新的节点需要重现判断，所以不需要移动
        {
            ptemp = ptemp->next;
        }

    }
}