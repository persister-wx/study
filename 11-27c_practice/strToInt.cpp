#pragma warning (disable : 4996)
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>


#if 0
enum status
{
	kValid,
	kInValid,
};

int g_Status = kValid;//����ȫ�ֱ�����Ϊ�����Ƿ���Ч�ı�־

//1.�Ƿ��ַ�
//2.�������
int StrToInt(const char *str)
{
	int s = 1;
	assert(str);
	const char *newStr = str;
	g_Status = kInValid;
	long long sum = 0;
	if (*newStr == '+')
	{
		newStr++;
	}
	else if (*newStr == '-')
	{
		newStr++;
		s = -1;
	}
	while (*newStr != '\0')
	{
		if (*newStr >= '0' && *newStr <= '9')
		{
			sum = sum * 10 + (*newStr - '0') * s;
			if ((s == 1) && (sum >= 0x7fffffff) || (s == -1) && (sum <= (int)0x80000000))
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
		newStr++;
     }
	if (*newStr == '\0')
	{
		 g_Status = kValid;
		 return sum;
	}
}

int main()
{

	const char *str = "-278";
	 int ret = StrToInt(str);
	 if ((ret == 0) && (g_Status == kInValid))
	 {
		 printf("ת�����ַ�����Ч\n");
	 }
	 else
	 {
		 printf("data : %d\n",ret);
	 }
	system("pause");
	return 0;
}
#endif