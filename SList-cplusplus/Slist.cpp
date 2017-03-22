#include"Slist.h"


//���е�Ĭ�ϳ�Ա����

SList::SList()
:_head(NULL)
, _tail(NULL)
{}

//�������캯��
////���д�������븴�ã�
//SList::SList(const SList& l)
//: _head(NULL)
//, _tail(NULL)
//{
//	Node* cur = l._head;
//	while (cur)
//	{
//		PushBack(cur->_data);
//	    cur = cur->_next;
//	}
//}


//��ͳд�����������캯����
SList::SList(const SList& l)
: _head(NULL)
, _tail(NULL)
{
	Node* cur = l._head;
	while (cur)
	{
		if (_head == NULL)//����ͷ���
		{
			_head = _tail = new Node(cur->_data);
		}
		else
		{
			_tail->_next = new Node(cur->_data);
			_tail = _tail->_next;
		}
		cur = cur->_next;
	}
}



void SList::Swap(SList& l)
{
   std::swap(_head, l._head);
   std::swap(_tail, l._tail);
}

//�ִ�д������ֵ�����������
SList& SList::operator=(SList l)
{
	Swap(l);
	return *this;
}


void SList::Destory()
{
	Node* cur = _head;
	while (cur)
	{
		Node* del = cur;
		cur = cur->_next;
		delete del;
	}
	_head = NULL;
	_tail = NULL;
}

SList::~SList()
{
	Destory();
}

//------------------------------
//β��
void SList::PushBack(DataType x)
{
	//1.����Ϊ��
	//2.�нڵ�
	Node* cur = _head;
	if (cur == NULL)
	{
		_head = _tail = new Node(x);
	}
	else
	{
		_tail->_next = new Node(x);
		_tail = _tail->_next;
	}
}

void SList::Print()
{
	Node* cur = _head;
	while (cur)
	{
		cout << cur->_data << "  ";
		cur = cur->_next;
	}
	cout << endl;
}

//-------------------------------------------------
//βɾ
void SList::PopBack()
{
	//1.����Ϊ��
	//2.ֻ��һ���ڵ�
	//3.�ж���ڵ�
	if (NULL == _head)
	{
		return;
	}
	if (NULL == _head->_next)
	{
		_head = _tail = NULL;
	}
	else
	{
		Node* cur = _head;
		Node* tailPrev = _head;
		while (tailPrev != _tail)
		{
			tailPrev = tailPrev->_next;
		}
		delete _tail;
		_tail = tailPrev;
		_tail->_next = NULL;
	}
}

//ͷɾ
void SList::PopFront()
{
	//1.û�нڵ�
    //2.��һ���ڵ�
	//3.�ж���ڵ�
	Node* cur = _head;
	if (NULL == _head)
	{
		return;
	}
	else if (NULL == _head->_next)//ɾ��ͷ���
	{
		delete _head;
		_head = _tail = NULL;
	}
	else
	{
		Node* cur = _head->_next;
		delete _head;
		_head = cur;
	}
}

//���������е�ֵΪx�Ľڵ�
SList::Node* SList::Find(DataType x)
{
	//1.û�нڵ�
	//2.�нڵ�
	Node* cur = _head;
	if (NULL == cur)
	{
		return NULL;
	}
	while (cur && cur->_data != x)
	{
		cur = cur->_next;
	}
	if (NULL != cur)
	{
		 return cur;
	}
	return NULL;
}

void SList::PushFront(DataType x)
{
	//1.����Ϊ��
	//2.�нڵ�
	Node* cur = _head;
	if (NULL == cur)
	{
		_head = _tail = new Node(x);
	}
	else
	{
		Node* tmp = new Node(x);
		tmp->_next = _head;
		_head = tmp;
	}
}

//��ĳ��λ�ò���һ��ֵΪx��Ԫ��
void SList::Insert(Node* pos, DataType x)
{
	//1.����λ��Ϊͷ����λ��
	//2.λ��pos==tail
	//3.ֻ��һ���ڵ�
	assert(NULL != pos);
	Node* cur = _head;
	if (cur == pos)
	{
		PushFront(x);
	}
	else
	{
		Node* prev = cur;
		while (cur && (cur != pos))
		{
			prev = cur;
			cur = cur->_next;
		}
		if (cur)
		{
			Node* tmp = new Node(x);
			prev->_next = tmp;
			tmp->_next = pos;
		}
	}
}


void SList::Erase(Node* pos)
{
	//1.ɾ��ͷ���
	//2ɾ��β�ڵ�
	//3.ɾ���м�ڵ�
	assert(NULL != pos);
	Node* cur = _head;
	if (_head == pos)
	{
		PopFront();
	}
	else if (_tail == pos)
	{
		PopBack();
	}else
	{
		Node* del = cur;
		while (cur && cur != pos)
		{
			del = cur;
			cur = cur->_next;
		}
		if (cur)
		{
			del->_next = cur->_next;
			delete cur;
			cur = NULL;
		}
	}
}


void Test1()
{
	SList l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushBack(5);
	SList l2(l);
	l.Print();
	l2.Print();
}

void Test2()
{
	SList l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.Print();
	l.PopBack();
	l.Print();
	l.PopBack();
	l.Print();
	l.PopBack();
	l.PopBack();
	l.Print();
	/*SList l2;
	l2.PushBack(9);
	l2.PushBack(8);
	l2.PushBack(7);
	l2.PushBack(6);
	l = l2;
	l.Print();
	l2.Print();*/
}

void Test3()
{
	SList l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.Print();
	l.PopFront();
	l.PopFront();
	l.Print();
	l.PopFront();
	l.Print();
	l.PopFront();
	l.Print();
}

void Test4()
{
	SList l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.Print();
	l.PushFront(9);
	l.PushFront(8);
	l.PushFront(7);
	l.Print();
}

void Test5()
{
	SList l;
	l.PushBack(1);
	l.PushBack(2);
	l.Insert(l.Find(1), 0);
	l.Insert(l.Find(2), 9);
	l.Print();
}

void Test6()
{
	SList l;
	l.PushBack(1);
	l.PushBack(2);
	l.Print();
	l.Erase(l.Find(1));
	l.Print();
	l.Erase(l.Find(2));
	l.Print();
}

int main()
{
	Test1();
	return 0;
}