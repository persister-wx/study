#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//ʹ�õ�������
int factorial(int num)
{
	int result = 1;
	while (num > 1)
	{
		result *= num;//��num��ʼ��
		num--;
	}
	return result;

}

int main()
{
	int num = 0;
	printf("������һ����:>");
	scanf("%d",&num);
	printf("%d\n",factorial(num));
	system("pause");
	return 0;
}