#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//------˫���ַ���
//1234------1 2341234---����һλ----(str+1,str+len-1)
                     //����2λ-----��str +2,str+ 2 +len -1��
					// ����stepλ----��str + k,str + step -1��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//------˫���ַ���
//1234------1 2341234---����һλ----(str+1,str+len-1)
                     //����2λ-----��str +2,str+ 2 +len -1��
					// ����stepλ----��str + k,str + step -1��

void str_shift(char *str,int len, int step)
{
	char *newstr = NULL;
	assert(str);
	assert(len > 1);//���len�Ƿ����1
	assert(step > 0 );//���Ҫ������λ���Ƿ����0
    step %= len;               
	newstr = (char *)malloc(sizeof(char) * len * 2 +1);//����˫���ַ����Ŀռ�
	strcpy(newstr,str);//��ԭ�ַ����������µ��ַ�����
	strcat(newstr,str);//��ԭ�ַ������ӵ����ַ����У�ʹ֮����˫���ַ���
	strncpy(str,newstr + step,len);//��������λ����ʼ�������ַ������ȸ��ַ�
	free(newstr);//�ڶ��Ͽ��ٵĿռ���Ҫ�����ͷ�
	newstr = NULL;
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

int main()
{
	char msg[] = "ABCD1234";
	int k = 0;
	printf("Please Enter:>");
	scanf("%d",&k);
	printf("before      : %s\n",msg);
	strShift(msg, strlen(msg),k);
	
	printf("shift_after : %s\n",msg);
	system("pause");
	return 0;
}
