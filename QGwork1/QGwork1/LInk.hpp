#include<iostream>
#include<string>

using namespace std;

//����ڵ�
template<class T>
struct ListNode
{
	T data;
	ListNode<T>* next;
};

//�������� ��ģ��
//�����������ģ��
template<class T>
class LinkList
{
public:
	LinkList();
	LinkList(T elem);
	LinkList(int n, T elem);
	~LinkList();
	void ClearList() const;
	bool Empty() const;
	int Length() const;
	T GetElem(int n) const;
	int LocateElem(T elem) const;
	bool Insert(int n, T elem);
	bool Delete(int n);
	void Displasy();
	void Remove(T elem);
	void IsCircle();
	void ReverseLink();
	void ReverseEven();

private:
	ListNode<T>* m_head;
};


template <class T>
LinkList<T>::LinkList()
{
	//����ͷ���
	m_head = new ListNode<T>;
	if (nullptr == m_head)
	{
		cout << "��̬����ͷ�ڵ��ڴ�ʧ��" << endl;
		return;
	}

	m_head->next = nullptr;
}


template <class T>
LinkList<T>::LinkList(T elem) :LinkList()
{
	insert(1, elem);
}


template<class T>
LinkList<T>::LinkList(int n, T elem) :LinkList()
{
	for (int i = 0; i < n; i++)
	{
		Insert(i, elem);
	}
}


template <class T>
LinkList<T>::~LinkList()
{
	ClearList();//��Ϊ�հ�
	delete m_head;//�ͷ�ͷ���
}

template <class T>
void LinkList<T>::ClearList() const
{
	ListNode<T>* temp, * p = m_head->next;

	while (p != nullptr)
	{
		temp = p->next;
		delete p;
		p = temp;
	}
}


template <class T>
bool LinkList<T>::Empty() const
{
	//���ͷ������һ���ڵ�Ϊ�� ��������Ϊ��
	return nullptr == m_head->next;
}


template <class T>
int LinkList<T>::Length() const
{
	int count = 0;
	ListNode<T>* ptemp = m_head->next;

	while (ptemp != nullptr)
	{
		count++;
		ptemp = ptemp->next;
	}
	return count;
}

template <class T>
T LinkList<T>::GetElem(int n)const
{
	ListNode<T>* ptemp = m_head->next;

	if (n <= Length())
	{
		for (int i = 1; i < n; i++)
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

template <class T>
int LinkList<T>::LocateElem(T data) const
{
	size_t location = 0;
	ListNode<T>* ptemp = m_head->next;

	while (ptemp != nullptr)
	{
		++location;
		if (ptemp->data == data)
		{
			return location;
		}

		ptemp = ptemp->next;
	}
	return 0;
}


template <class T>
bool LinkList<T>::Insert(int n, T elem)
{
	ListNode<T>* ptemp = m_head;

	if (n - 1 <= Length())
	{
		for (int i = 0; i < n - 1; ++i)
		{
			ptemp = ptemp->next;
		}

		//������һ���µĽڵ�
		ListNode<T>* newnode = new ListNode<T>;
		if (nullptr == newnode)
		{
			cout << "����ռ�ʧ��" << endl;
			return false;
		}
		newnode->data = elem;
		newnode->next = ptemp->next;
		ptemp->next = newnode;

		return true;
	}
	else
	{
		cout << "out of range" << endl;
		return false;
	}
}


template <class T>
void LinkList<T>::IsCircle()
{
	ListNode<T>* Link1 = m_head;
	ListNode<T>* Link2 = m_head;
	while (Link2 != nullptr && Link1->next != nullptr)
	{
		Link2 = Link2->next->next;
		Link1 = Link1->next;

		if (Link1 == Link2)
		{
			cout << "����ɻ�" << endl;
			return;
		}
	}
	cout << "�����ɻ�" << endl;
}



template <class T>
bool LinkList<T>::Delete(int n)
{
	ListNode<T>* ptemp = m_head;

	if (n <= Length())
	{
		for (int i = 0; i < n - 1; i++)
		{
			ptemp = ptemp->next;
		}

		ListNode<T>* t = ptemp->next;

		ptemp->next = ptemp->next->next;
		delete t;

		return 0;
	}
	else
	{
		cout << "out of range" << endl;
		return false;
	}
}

template <class T>
void LinkList<T>::Displasy()
{
	ListNode <T>* ptemp = m_head->next;

	while (ptemp != nullptr)
	{
		cout << ptemp->data << endl;
		ptemp = ptemp->next;
	}
}


template <class T>
void LinkList <T>::Remove(T elem)
{
	ListNode<T>* ptemp = m_head;

	while (ptemp->next != nullptr)
	{
		if (ptemp->next->data == elem)
		{
			ListNode<T>* t = ptemp->next;
			ptemp->next = ptemp->next->next;
			delete t;
		}
		else //���ɾ������ô������һ���ڵ����µĽڵ���Ҫ�����ж�
		{
			ptemp = ptemp->next;
		}
	}
}




struct Data
{
	int id;
	string name;
};

//����ʹ�õ��ǽṹ�壬Ҫ��һЩ�������������
ostream& operator << (ostream& os, const Data& data)
{
	os << data.id << "  " << data.name;
	return os;
}


bool operator==(const Data& data1, const Data& data2)
{
	//����ID���бȽ�
	return data1.id == data2.id;
}


//����ķ�ת

template <class T>
void LinkList<T>::ReverseLink()
{
	if (m_head->next == nullptr || m_head->next->next == nullptr)
	{
		return m_head;
	}
	ListNode<T>* ptemp = m_head->next;
	ListNode<T>* pre = nullptr;
	ListNode<T>* Next = m_head->next->next;

	while (Next != nullptr)
	{
		pre = Next->next;
		Next->next = ptemp;
		ptemp = Next;
		Next = pre;
	}


	m_head->next->next = nullptr;
	m_head->next = ptemp;
}


template<class T>
void LinkList<T>::ReverseEven()
{
	if (m_head->next == nullptr)
	{
		cout << "����Ϊ��" << endl;
		return;
		}
	ListNode<T>* ptemp = m_head;
	while (ptemp->next && ptemp->next->next)
	{
		ListNode<T>* p1 = ptemp->next;
		ListNode<T>* p2 = ptemp->next->next;
		ptemp->next = p2;
		p1->next = p2->next;
		p2->next = p1;
		ptemp = p1;
	}
	cout << "��ת���" << endl;
}
