#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int gcd(int data1,int data2)
{
	if (data1 == data2)
	{
		return data1;
	}
	if (data1 < data2)//Ϊ�˱�֤�ϴ����ʼ����ǰ�棬�����˴���
	{
		gcd(data2,data1);
	}
	else
	{//��1������Ϊ���ж���ż
		if (!(data1 & 1) && !(data2 & 1))//��������ż��
		{
			return gcd(data1>>1,data2>>1)<<1;		
		}
		else if(!(data1 & 1) && (data2 & 1))//data1Ϊż����data2Ϊ����
		{
			return gcd(data1>>1,data2);
		}
		else if((data1 & 1) && !(data2 & 1))//data1Ϊ������data2Ϊż��
		{
			return gcd(data1,data2>>1);
		}
		else//����������Ϊ����ʱ��Ӧ�ø������
		{
			return gcd(data2,data1 - data2);
		}
	}
}

int main()
{
	int data1 = 0;
	int data2 = 0;
	int ret = 0;
	printf("Please Enter:<data1,data2>");
	scanf("%d %d",&data1,&data2);
	ret = gcd(data1,data2);
	printf("ret : %d \n",ret);
	system("pause");
	return 0;
}