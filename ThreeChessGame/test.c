#include"three_chess.h"
void game()//��Ϸ��ʼ
{    
	char ret = 0;
	char arr[ROWS][COLS];
	init_board(arr, ROWS, COLS);//��ʼ������
	print_board(arr, ROWS, COLS);//��ӡ����
    do
	{
			player_move(arr);//�������
			print_board(arr,ROWS, COLS);//��ӡ������
			if (check_win(arr, ROWS, COLS) != ' ')//������̲�Ϊ�յĻ���������ѭ��
			{
					break;
			}
			computer_move(arr);//�����������
			print_board(arr,ROWS,COLS);//�ѵ����¹�������̴�ӡ����
			ret = check_win(arr, ROWS, COLS);//���ж���Ӯ��ķ���ֵ��������
	}
	while (ret == ' ');//�������û������ͬʱҲû���жϳ���Ӯ�Ļ���
	                 //����ִ��ѭ������������ѭ��

	if(check_win(arr, ROWS, COLS) == 'p')//����ж���Ӯ�ķ���ֵΪ����µ��ַ�ʱ
		                                //�����жϳ����Ӯ
	{
			printf("���Ӯ\n");
	}
	else if(check_win(arr, ROWS, COLS) == 'c')//����ж���Ӯ�ķ���ֵΪ������
		                                      //���жϵ���Ӯ
	{
			printf("����Ӯ\n");
			
	}
	else
	{
			if(check_win(arr, ROWS, COLS) == 'q')//������������ˣ������Ƿ���ֵΪ
				                                 //q��ʱ��������ж�Ϊƽ��
	        printf("ƽ��\n");
	}

}




int main()
{
		int choose = 0;
		do
		{
				menu();
				printf("��ѡ��>");
				scanf("%d",&choose);
				switch (choose)
				{
						case 0:
								exit(1);
						case 1:
								game();
				}

		}
		while(choose);
}