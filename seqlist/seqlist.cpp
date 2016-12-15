#include"seqlist.h"

void Init_Seqlist(pseqlist seq)
{
	assert(seq);
	seq->data =(DataType *) malloc( MAX_SIZE * sizeof(DataType));
	if (NULL == seq->data)
	{
		
	}
	
}

int isSeqlistFull(pseqlist seq)
{
	assert(seq);




}

//β��
void PushBack(pseqlist seq,DataType x)
{
	assert(seq);
	if (seq->count >= seq->listsize)
	{
		printf("˳�������\n");
		return;
	}
	else
	{
		seq->data[seq->count] = x;
		seq->count++;
		printf("��ӳɹ�\n");
	}
}


//βɾ
void PopBack(pseqlist seq)
{
	assert(seq);
	if (seq->count == 0)
	{
		printf("˳���Ϊ��\n");
		return ;
	}
	else
	{
		seq->data[seq->count-1] = 0;
		seq->count--;
		printf("ɾ���ɹ�\n");
	}
}

//ͷ��
void Pushfront(pseqlist seq,DataType x)
{
	assert(seq);
	if (seq->count >= seq->listsize)
	{
		printf("˳�������\n");
		return;
	}
	else if(seq->count == 0)
	{
		seq->count++;
		seq->data[seq->count - 1] = x;
		printf("����ɹ�\n");
		return ;
	}
	else
	{
		while (seq->count)
		{
			seq->data[seq->count] = seq->data[seq->count - 1];
			seq->count--;
		}
		seq->data[seq->count] = x;
		seq->count++;
		printf("����ɹ�\n");
	}
}



//ͷɾ
void Popfront(pseqlist seq)
{
	assert(seq);
	if (seq->count == 0)
	{
		printf("˳���Ϊ��\n");
		return ;
	}
	else if(seq->count == 1)
	{
		seq->data [seq->count - 1] = 0;
		printf("ɾ���ɹ�\n");
	}
	else
	{
		int i = 0;
		for (i = 0; i < seq->count - 1;i++)
		{
			seq->data[i] = seq->data[i+1];
		}
		seq->count--;
		printf("ɾ���ɹ�\n");
	}
}

void Insert(pseqlist seq,size_t pos,DataType x)
{
	assert(seq);
	if (pos > (seq->count ))
	{
		printf("�����λ�ò��Ϸ�\n");
		return ;
	}
	if (seq->count >= seq->listsize)
	{
		printf("˳�������\n");
		return;
	}
	int i = 0;
	for (i = seq->count; i >= pos; i--)
	{
		seq->data[i] = seq->data[i- 1];
	}
	seq->data[pos - 1] = x;
	seq->count++;
	printf("����ɹ�\n");
}



int  Find(pseqlist seq,DataType x)
{
	assert(seq);
	if (seq->count == 0)
	{
		printf("˳���Ϊ��\n");
		return -1;
	}
	while (seq->count)
	{
		if (seq->data[seq->count - 1] != x)
		{
			seq->count--;
		}
		else
		{
			return (seq->count - 1);
		}
	}
	return -1;
}


void Erase(pseqlist seq,size_t pos)
{
	assert(seq && pos);
	if (pos > seq->count || (pos <= 0))
	{
		printf("ɾ����λ�ò��Ϸ�\n");
		return ;
	}
	int i = 0;
	for (i = pos;i < seq->count; i++)
	{
		seq->data[i] = seq->data[i+1];
	}
	seq->count--;
	printf("ɾ���ɹ�\n");

}


void Remove(pseqlist seq,DataType x)
{
	assert(seq);
	int i = 0;
	while (seq->data[i] != x && (seq->count))
	{

	}
}


void PrintSeqlist(pseqlist seq)
{
	assert(seq);
	int i = 0;
	for (i = 0; i < seq->count; i++)
	{
		printf("%d ",seq->data[i]);
	}
	printf("\n");

}

