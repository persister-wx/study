#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

int  is_sub_str(char *str,char *arr)
{
	char *newstr = NULL;
	int len = strlen(str);
	assert(str);
	assert(arr);
	assert(len > 0);//���len�Ƿ����0
	if (strlen(str) == strlen(arr))
	{
		newstr = (char *)malloc(sizeof(char) * len * 2 +1);//����˫���ַ����Ŀռ�
		strcpy(newstr,str);//��ԭ�ַ����������µ��ַ�����
		strcat(newstr,str);//��ԭ�ַ������ӵ����ַ����У�ʹ֮����˫���ַ���
		if (strstr(newstr,arr) == NULL)//�����˫���ַ�����û���ҵ�arr����ַ���
		{                             //�򷵻�0
			return 0;                     
		}
		return 1;//�����˫���ַ������ҵ���arr�ַ������򷵻�1
	free(newstr);//�ڶ��Ͽ��ٵĿռ���Ҫ�����ͷ�
	newstr = NULL;
   }
	return 0;
}

int main()
{
	char msg[] = "ABCD1234";
	char str[] = "CD1234AB";
	printf("is sub str : %d",is_sub_str(msg,str));//��---����1    ����----����0
	system("pause");
	return 0;
}

