#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

void reverse(char *pstr)
{
	char tmp = 0;
	char *pstr_end = pstr + strlen(pstr) - 1;
	assert(pstr);
	if (strlen(pstr) < 2)//���ַ����ĳ���С��2��ʱ�ݹ�ĳ�������
	{
		return;
	}
	else
	{
		tmp =  *pstr;//���ַ�������Ԫ���ȱ����ڶ�ջ��
		*pstr = *pstr_end;//����ʱ�ַ��������һ��Ԫ�ظ����ַ�������Ԫ��
		*pstr_end = '\0';//���ַ���������Ǹ�����ʱ�����һ��Ԫ�أ�
		                //�ַ����ĳ��Ȳ��ϼ�С
		reverse(++pstr);
		*pstr_end = tmp;//�ݹ���������ַ�������Ԫ���ٸ�����ʱ�����һ��Ԫ�أ�
		                //Ҳ���Ǵ�ʱΪ'\0'��Ԫ��
	}
}

int main()
{
	char msg[] = "abcdefg";
	printf("before : %s\n",msg);
	reverse(msg);
	printf("after : %s\n",msg);
	system("pause");
	return 0;
}