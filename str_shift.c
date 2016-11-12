#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

void swap(char *start, char *end)//���������ַ�
{
	*start ^= *end;
	*end ^= *start;
	*start ^= *end;
}

void reverse(char *start, char *end)
{
	assert(start);
	assert(end);
	while (start < end)//���ַ�������
	{
		swap(start,end);
		start++,end--;
	}
}

void str_shift(char *str,int len, int step)
{
	char *middle = NULL;
	step %= len;//ʹ����λ�Ĳ���С���ַ����ĳ���
	middle = str + step - 1;//middle���ַ�����Ϊ������
    assert(str);
	assert(len > 1);
	assert(step > 0);
	reverse(str,middle);//���ֿ�����벿������
	reverse(middle +1, str + len - 1);//���ֿ����Ұ벿������
	reverse(str,str + len -1);//����������
}

int main()
{
	char msg[] = "ABCD1234";
	int k = 0;
	printf("Please Enter:>");
	scanf("%d",&k);
	printf("before      : %s\n",msg);
	str_shift(msg,strlen(msg), k);
	printf("shift_after : %s\n",msg);
	system("pause");
	return 0;
}
