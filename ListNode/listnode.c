#include"ListNode.h"

//��ʼ��
void InitListNode(PNode *pHead)
{
	assert(pHead);
	*pHead = NULL;
}

//����һ���ڵ�
static PNode BuyNode(DataType _data)
{
	PNode node = (PNode)malloc(sizeof(Node));
	if (node)
	{
		 node->data = _data;
		 node->next = NULL;
	}
	return node;
}

//β��
void PushBack(PNode *pHead,DataType _data)
{
	assert(pHead);
	PNode newNode = BuyNode(_data);
	if (NULL == (*pHead))
	{
		*pHead = newNode;
		return ;
	}
	PNode pCur = *pHead;
	while (pCur->next)
	{
		pCur = pCur->next;
	}
	pCur->next = newNode;
}

//βɾ
void PopBack(PNode *pHead)
{
	assert(pHead);
	if (NULL == (*pHead))
	{
		return ;
	}
	else if (NULL == (*pHead)->next)
	{
		free(*pHead);
		*pHead = NULL;
	}
	else
	{
		PNode pCur = *pHead;
		PNode prev = pCur;
		while (pCur->next)
		{
			prev = pCur;
			pCur = pCur->next;
		}
		free(pCur);
		prev ->next = NULL;
	}
}


//ͷ��
void PushFront(PNode *pHead,DataType _data)
{
	assert(pHead);
	PNode newNode = BuyNode(_data);
	if (NULL == (*pHead))
	{
		*pHead = newNode;
	}
	else
	{
		if (newNode)
		{
			newNode->next = *pHead;
			*pHead = newNode;
		}
	}
}
//ͷɾ
void PopFront(PNode *pHead)
{
	assert(pHead);
	if (NULL == (*pHead))
	{
		return ;
	}
	PNode pDel = *pHead;
	*pHead = (*pHead)->next;
	free(pDel);
}

//�����ӡ������
void printFromTailToFront(PNode pHead)
{
	if (pHead)
	{
		printFromTailToFront(pHead->next);
		printf("%d->",pHead->data);
	}
}

//����_data����������λ��
PNode Find(PNode pHead, DataType _data)
{
	if (NULL == pHead)
	{
		return NULL;
	}
	PNode pCur = pHead;
	while (pCur)
	{
		if (pCur->data == _data)
		{
			return pCur;
		}
		pCur = pCur->next;
	}
	return NULL;
}
//����һ���ڵ�
void InsertNode(PNode pos,DataType _data)
{
	if (pos)
	{
		PNode newNode = BuyNode(_data);
		if (newNode)
		{
			newNode->next = pos->next;
			pos->next = newNode;
		}
	}
}

//ɾ��ĳ��λ�ô��Ľڵ�
void Erase(PNode* pHead, PNode pos)
{
	assert(pHead);
	if ((NULL == (*pHead)) && (NULL == pos))
	{
		return ;
	}
	if((*pHead) == pos)
	{
		*pHead = pos->next;
		free(pos);
	}
	else
	{
		PNode pCur = *pHead;
		while (pCur ->next != pos)
		{
			pCur = pCur->next;
		}
		pCur->next = pos->next;
		free(pos);
	}
}


//ɾ��ֵΪ_data�Ľڵ�
void Remove(PNode* pHead, DataType _data)
{
	assert(pHead);
	Erase(pHead, Find(*pHead,_data));
}

//ɾ�������������е�_data
void RemoveAll(PNode *pHead, DataType _data)
{
	assert(pHead);
	if (NULL == (*pHead))
	{
		return ;
	}
	PNode pDel = *pHead;
	if ((*pHead)->data == _data)
	{
		*pHead = (*pHead)->next;
		free(pDel);
	}
	PNode pCur = *pHead;
	PNode prev = pCur;
	while (pCur)
	{
		if (pCur->data == _data)
		{
			prev->next = pCur->next;
			free(pCur);
			pCur = prev->next;
		}
		else
		{
			prev = pCur;
			pCur = pCur->next;
		}
	}	 
}


size_t Size(PNode pHead)
{
	size_t count = 0;
	while (pHead)
	{
		pHead = pHead->next;
		count++;
	}
	return count;
}

PNode Front(PNode pHead)
{
	return pHead;
}


//ժ��β�ڵ�
PNode Back(PNode pHead)
{
	if (NULL == pHead)
	{
		return NULL;
	}
	PNode pCur = pHead;
	while (pCur->next)
	{
		pCur = pCur->next;
	}
	return pCur;
}



//is empty-->1  Not empty--->0
int Empty(PNode pHead)
{
	if (pHead)
	{
		return 0;
	}
	return 1;
}

//ɾ����ͷ������ķ�β���
void DeleteNotTailNode(PNode pos)
{
	if (NULL == pos)
	{
		return ;
	}
	PNode pDel = pos->next;
	pos->data = pDel->data;
	pos->next = pDel->next;
	free(pDel);
}


//����ͷ�������ͷ���ǰ�����½ڵ�
void InsertNotHeadNode(PNode pos, DataType _data)
{
	if (NULL == pos)
	{
		return ;
	}
	PNode newNode = BuyNode(pos->data);
	if (newNode)
	{
		newNode->next = pos->next;
		pos->next = newNode;
		pos->data = _data;
	}
}

// �õ�����ʵ��Լɪ��
PNode JosephCircle(PNode pHead, size_t M)
{
	if (NULL == pHead)
	{
		return NULL;
	}
	PNode pCur = pHead;
	PNode prev = pCur;
	while (pCur != pCur->next)
	{
		size_t k = M;
		while (--k)
		{
			pCur = pCur->next;
		}
		PNode pDel = pCur->next;
		pCur->data = pDel->data;
		pCur->next = pDel->next;
		free(pDel);
	}
	return pCur;
}


//���õ�����--����ָ��
//PNode ReverseList(PNode pHead)
//{
//	if (NULL == pHead || NULL == pHead->next)
//	{
//			return pHead;
//	}
//	PNode prev = pHead;
//	PNode pCur = prev->next;
//	PNode pnext = pCur->next;
//	while (pnext)
//	{
//		pCur->next = prev;
//		prev = pCur;
//		pCur = pnext;
//		pnext = pnext->next;
//	}
//	pCur->next = prev;
//	pHead->next = NULL;
//	return pCur;
//}
//

//���õ�����--ͷ�巨
PNode ReverseList(PNode pHead)
{
	if (NULL == pHead || NULL == pHead->next)
	{
			return pHead;
	}
	PNode pCur = pHead->next;
	PNode newNode = NULL;
	while (pCur)
	{
		pHead->next = newNode;
		newNode = pHead;
		pHead = pCur;
		pCur = pCur->next;
	}
	pHead->next = newNode;
	newNode = pHead;
	return newNode;
}


//���ҵ������е��м�ڵ�
PNode FindMidNode(PNode pHead)
{
	if (NULL == pHead || NULL == pHead->next)
	{
		return pHead;
	}
	PNode pSlow = pHead;
	PNode pFast = pHead;
	while (pFast && pFast->next)
	{
		pSlow = pSlow->next;
		pFast = pFast->next->next;
	}
	return pSlow;
}

//���ҵ�����ĵ�����k���ڵ�
PNode FindLastKNode(PNode pHead, size_t K)
{
	if (NULL == pHead || K == 0)
	{
		return NULL;
	}
	PNode pSlow = pHead;
	PNode pFast = pHead;
	while (--K)
	{
		if (NULL == pFast)
		{
			return NULL;
		}
		pFast = pFast->next;
	}
	while (pFast->next)
	{
		pSlow = pSlow->next;
		pFast = pFast->next;
	}
	return pSlow;
}


PNode DeleteLastKNode(PNode pHead, size_t K)
{
	if (NULL == pHead || K == 0)
	{
		return NULL;
	}
	PNode pos = FindLastKNode(pHead,K);
	Erase(&pHead,pos);
}


PNode MergeList(PNode pHead1, PNode pHead2)
{
	if (NULL == pHead1)
	{
		return pHead2;
	}
	if (NULL == pHead2)
	{
		return pHead1;
	}
	PNode newNode = NULL;
	PNode pTail = newNode;
	if (pHead1->data < pHead2->data)
	{
		newNode = pHead1;
		pHead1 = pHead1->next;
	}
	else
	{
		newNode = pHead2;
		pHead2 = pHead2->next;
	}
	pTail = newNode;
	while (pHead1 && pHead2)
	{
		if (pHead1->data < pHead2->data)
		{
			pTail->next = pHead1;
			pTail = pHead1;
			pHead1 = pHead1->next;
		}
		else
		{
			pTail->next = pHead2;
			pTail = pHead2;
			pHead1 = pHead2->next;
		}
	}
	if (pHead1)
	{
		pTail->next = pHead1;
	}
	else
	{
		pTail->next = pHead2;
	}
	return newNode;

}



//��ӡ������
void printList(PNode phead)
{
	PNode pCur = phead;
	while (pCur)
	{
		printf("%d ",pCur->data);
		pCur = pCur->next;
	}
	printf("\n");
}









