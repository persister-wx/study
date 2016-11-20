#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int find_first_char(char const *str)
{
	unsigned int ascii[255] = {0};//����һ�����飬����ÿ����ĸ���ֵĸ���
	char const *ret = str;
	int i = 0;
	assert(str);
	while (*str)
	{
		ascii[*str++]++;//��¼ÿ���ַ����ֵĸ���
	}
	while(*ret != '\0')//���ҵ�һ��ֻ����һ�ε���ĸ
	{
		if (1 == ascii[*ret])
		{
			return *ret;
		}
		ret++;
	}
	return -1;//û��ֻ����һ�ε���ĸ������-1
}

int main()
{
	char *msg = "abche1235ehcab532";
    int flag = find_first_char(msg);
	if (-1 != flag)
	{
		printf("this character is %c\n",flag);
	}
	system("pause");
	return 0;
}