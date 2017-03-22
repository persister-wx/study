#include"List.h"

//��������
List::List(const List& l)
:_head(NULL)
, _tail(NULL)
{
	Node* cur = l._head;
	while (cur)
	{
		PushBack(cur->_data);
		cur = cur->_next;
	}
}

void List::Swap(List l)
{
	std::swap(_head, l._head);
	std::swap(_tail, l._tail);
}

//��ֵ�������д���ִ���
//List& List::operator=(List l)
//{
//	Swap(l);
//	return *this;
//}


//��ֵ���������ͳд����
List& List::operator=(const List& l)
{
	if (this != &l)
	{
		this->~List();
		Node* cur = l._head;
		while (cur)
		{
			PushBack(cur->_data);
			cur = cur->_next;
		}
	}
	return *this;
}


//β��
void List::PushBack(DataType x)
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
		Node* tmp = new Node(x);
		_tail->_next = tmp;
		tmp->_prev = _tail;
		_tail = tmp;
	}
}

//��ӡ����
void List::Print()
{
	Node* cur = _head;
	while (cur)
	{
		cout << cur->_data << "  ";
		cur = cur->_next;
	}
	cout << endl;
}
//βɾ
void List::PopBack()
{
	//1.����Ϊ��
	//2.��һ���ڵ�
	//3.�ж���ڵ�
	if (NULL == _head)
	{
		return;
	}
	if (NULL == _head->_next)
	{
		delete _head;
		_head = _tail = NULL;
	}
	else
	{
		Node* cur = _tail->_prev;
		delete _tail;
		_tail = cur;
		_tail->_next = NULL;
	}
}

//ͷ��
void List::PushFront(DataType x)
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
		_head->_prev = tmp;
		_head = tmp;
	}
}

//ͷɾ
void List::PopFront()
{
	//1.����Ϊ��
	//2.��һ���ڵ�
	//3.�ж���ڵ�
	if (NULL == _head)
	{
		return;
	}
	if (NULL == _head->_next)
	{
		delete _head;
		_head = _tail = NULL;
	}
	else
	{
		Node* cur = _head->_next;
		delete _head;
		_head = cur;
		_head->_prev = NULL;
	}
}

List::Node* List::Find(DataType x)
{
	Node* cur = _head;
	while (cur && (cur->_data != x))
	{
		cur = cur->_next;
	}
	return cur;
}


//��posλ�õ�ǰ�����
void List::Insert(Node* pos, DataType x)
{
	//1.��ͷ���ǰ����
	//2.����ͷ������
	assert(pos != NULL);
	if (pos == _head)
	{
		PushFront(x);
	}
	else
	{
		Node* tmp = new Node(x);
		Node* tmpPrev = pos->_prev;
		tmp->_next = pos;
		pos->_prev = tmp;
		tmp->_prev = tmpPrev;
		tmpPrev->_next = tmp;
	}
}

//ɾ��ĳ��λ�õĽڵ�
void List::Erase(Node* pos)
{
	//1.����Ϊ��
	//2.ɾ��ͷ���
	//3ɾ��β�ڵ�
	//3.ɾ���м�����ڵ�
	assert(pos != NULL);
	if (NULL == _head)
	{
		return;
	}
	if (pos == _head)
	{
		PopFront();
	}
	else if (pos == _tail)
	{
		PopBack();
	}
	else
	{
		Node* cur = _head;
		while (cur && cur->_next != pos)
		{
			cur = cur->_next;
		}
		if (cur)
		{
			Node *next = pos->_next;
			cur->_next = next;
			next->_prev = cur;
			delete pos;
		}
	}
}


//�ͷſռ�
void List::Destory()
{
	Node* cur = _head;
	while (cur)
	{
		Node* del = cur;
		cur = cur->_next;
		delete del;
	}
	_head = _tail = NULL;
}

List::~List()
{
	Destory();
}

void Test1()
{
	List l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.Print();

}

void Test2()
{
	List l;
	l.PushBack(1);
	l.PushBack(2);
	l.Print();
	l.PopBack();
	l.Print();
	l.PopBack();
	l.PopBack();
	l.Print();
}

void Test3()
{
	List l;
	/*l.PushBack(1);
	l.PushBack(2);
	l.Print();*/
	l.PushFront(9);
	l.PushFront(8);
	l.PushFront(7);
	l.Print();
}

void Test4()
{
	List l;
	l.PushBack(1);
	l.PushBack(2);
	l.Print();
	l.PopFront();
	l.Print();
	l.PopFront();
	l.Print();
	l.PopFront();
	l.Print();
}


void Test5()
{
	List l;
	l.PushBack(1);
	l.PushBack(2);
	l.Insert(l.Find(1), 9);
	l.Print();
	l.Insert(l.Find(2), 8);
	l.Print();
}

void Test6()
{
	List l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.Print();
	//l.Erase(l.Find(1));
	//l.Print();
	l.Erase(l.Find(2));
	l.Print();
}

void Test7()
{
	List l;
	l.PushBack(2);
	List l2(l);
	l2.Print();
}

void Test8()
{
	List l1;
	l1.PushBack(2);
	l1.Print();
	List l;
	l.PushFront(9);
	l.PushFront(8);
	l.PushFront(7);
	l.Print();
	l1 = l;
	l1.Print();
}

int main()
{
	Test8();
	return 0;
}