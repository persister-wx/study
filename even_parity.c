#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//��żУ��
int Even_Parity(int value,int value_bits)
{
	int i = 0;
	int one_bits = 0;

	while (value_bits > 0)
	{
		one_bits += value & 1;//ͳ��1�ĸ���
		value >>= 1;//�������������һλ
		value_bits--;//���������е�λ����һ
	}

	return (one_bits % 2) == 0;//�����ż����1���򷵻�1�����򣬷���0

}
int main()
{
	int num = 0;
	printf("Please Enter a number:>");
	scanf("%d",&num);
	if (Even_Parity(num, 32))
	{
		printf("������Ķ�����������ż����1");
	}
	else
	{
		printf("������Ķ�����������������1");
	}
	system("pause");
	return 0;
}