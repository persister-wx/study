#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>


long int fibonacci(int n)
{
	long int previous_result = 1;//����һ��쳲���������ʼ��Ϊ1
	long int result = 1;//��Ϊǰ����������1�����Ե�ѭ������С��2��ʱ�򷵻�1
	long int next_older_result = 1;
	while (n > 2)
	{
		n--;//ѭ��������1
		previous_result = next_older_result;
		next_older_result = result;
		result = previous_result + next_older_result;

	}
	return result;
}
 int main()
 {	
	 int number = 0;
	 printf("������ :>");
	 scanf("%d",&number);
	 printf("�� %d ��쳲��������ǣ�%ld\n",number,fibonacci(number));
	 system("pause");
	 return 0;
  }