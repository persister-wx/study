#pragma warning (disable :4996)
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

typedef int DataType;

typedef struct Node
{
	DataType data;
	struct Node *next;
}Node,*PNode;


void printList(PNode phead);
void InitListNode(PNode *pHead);
void PushBack(PNode *pHead,DataType _data);
void PopBack(PNode *pHead);
PNode Find(PNode pHead, DataType data);

void PushFront(PNode *pHead,DataType _data);
void PopFront(PNode *pHead);
void printFromTailToFront(PNode pHead);

void InsertNode(PNode pos,DataType _data);
void Erase(PNode* pHead, PNode pos);

void Remove(PNode* pHead, DataType data);
void RemoveAll(PNode* pHead, DataType data);
size_t Size(PNode pHead);
PNode Front(PNode pHead);
PNode Back(PNode pHead);
int Empty(PNode pHead);

void DeleteNotTailNode(PNode pos);
void InsertNotHeadNode(PNode pos, DataType data);
//�õ�����ʵ��Լɪ��
PNode JosephCircle(PNode pHead, size_t M);
//���õ�����--����ָ��
PNode ReverseList(PNode pHead);
// �Ե��������ð������--����
void BubbleSort(PNode pHead);
// ���ҵ�������м��㣬Ҫ��ֻ�ܹ�����һ������
PNode FindMidNode(PNode pHead);

// ���ҵ�����ĵ�����K����㣬ֻ�ܹ�����һ������
PNode FindLastKNode(PNode pHead, size_t K);

// ɾ��������ĵ�����K�����
PNode DeleteLastKNode(PNode pHead, size_t K);

// �ϲ��������������ϲ�֮����Ȼ����
PNode MergeList(PNode pHead1, PNode pHead2);

