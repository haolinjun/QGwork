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
//˫��ѭ��������ģ��
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
    //����ͷ�ڵ�
    m_head = new DLNode < T >;
    if (nullptr == m_head)
    {
        cout << "��̬����ͷ�ڵ��ڴ�ʧ��" << endl;
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
    ClearList();    //��Ϊ�հ�
    delete m_head;  //�ͷ�ͷ�ڵ�
}

template <typename T>
void DLinkList<T>::ClearList() const        //����Ա���� ���ı�����ֵ
{
    DLNode<T>* temp, * p = m_head->next;

    while (p != m_head)     //ɾ��ͷ�ڵ��Ժ�����нڵ�
    {
        temp = p->next;
        delete p;           //Ҫ�ͷŶ�̬�ڴ�
        p = temp;
    }

    m_head->next = m_head;
    m_head->prior = m_head;
}

template <typename T>
bool DLinkList<T>::Empty() const
{
    //���ͷ�ڵ����һ���ڵ�Ϊ�գ��������Ϊ��
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
        if (ptemp->data == data)            //ע�� �����ͱ���֧�� == �������������֧����Ҫ�������������
        {
            return location;
        }

        ptemp = ptemp->next;
    }

    return 0;       //����0��ʾδ�ҵ�
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

        //������һ���µĽڵ�
        DLNode<T>* newnode = new DLNode < T >;
        if (nullptr == newnode)
        {
            cout << "����ռ�ʧ��" << endl;
            return false;
        }

        newnode->data = elem;       //����������Ͳ��ǻ����������ͣ�����֧�� = ����������Ҫ���� = ������


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

        DLNode<T>* t = ptemp->next;     //ָ���ɾ���Ľڵ�

        ptemp->next = ptemp->next->next;        //����ɾ���ڵ����һ�ڵ�ָ���ɾ���ڵ����һ�ڵ�
        ptemp->next->next->prior = ptemp;

        delete t;       //�ͷ�ɾ���ڵ���ڴ�

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
        if (ptemp->next->data == elem)          //�ҵ���Ҫɾ���Ľڵ���ͬ
        {
            DLNode<T>* t = ptemp->next;     //ָ���ɾ���Ľڵ�
            ptemp->next = ptemp->next->next;        //����ɾ���ڵ����һ�ڵ�ָ���ɾ���ڵ����һ�ڵ�
            delete t;       //�ͷ�ɾ���ڵ���ڴ�
        }
        else        //������Ҫע��һ�£����ɾ������ô������һ�ڵ����µĽڵ���Ҫ�����жϣ����Բ���Ҫ�ƶ�
        {
            ptemp = ptemp->next;
        }

    }
}