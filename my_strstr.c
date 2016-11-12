#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

char *mystrstr(char const *dst_str,char const *src_str)//���ַ������Һ���
{
    const char *dst_start = dst_str;
	const char *dst_end = dst_str + strlen(dst_str) - strlen(src_str);//abcdefg---����cd
	const char *src_start = src_str; //ֻ����ҵ�f���ɣ���Ϊcd���ַ�������Ϊ2������ʣ��
	                          //�ַ����ĳ�����С��2����϶������ҵ���
	char *pos = dst_start;  
	assert(dst_str);
	assert(src_str);

	if (strlen(dst_str) < strlen(src_str))//���Ŀ���ַ����ĳ���С��Դ�ַ�����
		                                 //��϶������ҵ�,��ʱӦ����NULL
	{
		return NULL;
	}
	while (dst_start <= dst_end)
	{
		pos = dst_start;//��¼��ʱĿ��ָ���λ��

		while ((*dst_start == *src_start) && (*src_start != '\0'))
		{
			dst_start++,src_start++;
		}
		if (*src_start == '\0')//����������ϣ���˵���ҵ��ˣ���ʱ�������λ��
		{
			return pos;
		}
		dst_start = pos + 1;//���û���ҵ�������Ŀ��ָ��ָ����һ��Ԫ��
		src_start = src_str;//Դָ��ָ��ʼλ��
	}
	return NULL;
}

int main()
{
	const char msg[] = "where are you from";
	const char str[] = "are";
	printf("before : %s\n",msg);
	printf("find after : %s\n",mystrstr(msg,str));
	system("pause");
	return 0;
}