#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int Max_Com_Divisor(int x, int y)//��շת����������Լ��
{
	while (x * y)//������һ��Ϊ0ʱ����ֹѭ��
	{
		if (x > y)//������ģС���Ľ���������������ϴ��ֵ��ֱ�����������
		{
			x %= y;
		}
		else if(x < y)
		{
			y %= x;
		}
	}
	return x > y ? x : y;
}


int main()
{
	int a = 0;
	int b = 0;
	int max_com_div = 0;
	int min_com_mult = 0;
	printf("please Enter <a,b>:");
	scanf("%d %d",&a,&b);
	max_com_div = Max_Com_Divisor(a,b);
	min_com_mult = (a * b)/max_com_div;//min_com_multΪ��С������
	printf("max_com_divisor = %d min_com_mult = %d",\
		   max_com_div,min_com_mult);
	system("pause");
	return 0;
}
