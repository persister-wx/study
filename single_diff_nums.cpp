#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void find_diff_nums(int *arr,int *single1,int *single2,int len)
{
	int tmp = arr[0];
	int i = 0;
	int flag = 1;//����һ����־λ����¼1��λ��
	assert(arr);
	assert(single1);
	assert(single2);
	assert(len > 0);
	for (i = 1; i < len; i++)//���һ�����飬���õ��Ľ��������tmp��
	{
		tmp ^= arr[i];
	}
	while (1)//�ҵ�������ͬ��������д����λ��ʼ��1��λ��
	{
		if (flag & tmp)
		{
			break;
		}
		else
		{
			flag <<= 1;
		}
	}
	for(i = 0; i < len; i++)//�������е����ݸ���flag����Ϊ���飬
		                   //�ֱ��ҳ����������еĵ���
	{
		if (flag & arr[i])
		{
			*single1 ^= arr[i];
		}
		else
		{
			*single2 ^= arr[i];
		}
	}
}

int main()
{
	int arr[] = {2,3,4,5,6,1111,2222,6,5,4,3,2};
	int len = sizeof(arr)/sizeof(int);
	int single1 = 0;
	int single2 = 0;
	find_diff_nums(arr,&single1,&single2,len);
	printf("single1 : %d\nsingle2 : %d",single1,single2);
	system("pause");
	return 0;
}