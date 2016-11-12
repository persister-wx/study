#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

int getline(char *arr,int limits)//����һ���ַ����Իس�����
{
	int c = 0;
	int i = 0;
	assert(arr);
	assert(limits > 0);
	while (( limits-- > 0) && ((c = getchar()) != EOF) && (c != '\n'))//����ȡ���ַ�
		                                                             //�浽arr������
	{
		arr[i++] = c;
	}
	if ( '\n' == c)//�������س�ʱ���ַ�����������Ѿ�������
		          //��ʱ������س�������������
	{
		arr[i++] = c;
	}
	arr[i] = '\0';
	return i;
}


int my_strstr(char *dest,char *src)//�ж�src�Ƿ�Ϊdest���Ӵ�����--����1����--����0
{
	char *dest_start = dest;
	char *src_start = src;
	char *pos = NULL; 
	assert(dest);
	assert(src);
	for (dest_start = dest; *dest_start != '\0';dest_start++ )
	{
		for (src_start = src,pos = dest_start; (*src_start != '\0') \
			&& (*pos != '\0') &&( *src_start == *pos); pos++,src_start++)
		{
			;	
		}
		if (*src_start == '\0')
		{
			return 1;
		}
	}

	return 0;
}


int main()
{
	char arr[1024];
	int len = 1024;
    
	if (getline(arr,len) > 0)
	{
		if (my_strstr(arr,"1234"))
		{
			printf("%s",arr);
		}
	}
	system("pause");
	return 0;
}