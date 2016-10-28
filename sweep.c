#include"sweep.h"
void menu()
{
	printf("*****************\n");
	printf("**1.play 0.exit**\n");
	printf("*****************\n");
}

void init_mine(char mine[][COLS+2], int x, int y)//��ʼ������
{
  int i = 0;
  int j = 0;
  for (i = 0; i<x; i++)
  {
      for (j = 0; j<y; j++)
      {
			mine[i][j] ='+'; 
      }
  }
}

void init_show(char mine[][COLS+2], int x, int y)//��ʼ����ʾ�׸���������
{
		int i = 0;
		int j = 0;
		for (i = 0; i<x; i++)
		{
				for (j = 0; j<y; j++)
				{
						mine[i][j] ='*';
				}
		}
}

void print_mine(char mine[ ][COLS+2], int x, int y)//��ӡ����
{
		int i = 0;
		int j = 0;
		printf("       ");
		for (i = 1; i < x-1; i++)//����еı��
		{
				printf(" %d ",i);
		}
				printf("\n    ");

		for (i = 0; i < x; i++)
		{    
				if (i > 0 && i < 9)
				{
	   					printf("%d ",i);
				}
		if (i == 9)
		{
				printf("  ");
		}
		for (j = 0; j < y; j++)//�������
		{
				printf(" %c ",mine[i][j]);
		}
				printf("\n  ");
		}
				printf("\n");
}

void print_show(char show[ ][COLS+2], int x, int y)
{
		int i = 0;
		int j = 0;
		printf("    ");
		for (i = 0; i < x; i++)
		{
				printf(" %d ",i);
		}
		printf("\n  ");
		for (i = 0; i < x; i++)
		{	
				printf("%d ",i);

		for (j = 0; j < y; j++)
		{
				printf(" %c ",show[i][j]);
		}
				printf("\n  ");
		}
}

void lay_mines( char mine[][COLS+2])//����
{   
		int count = MINES;//�����׵ĸ���
		srand((unsigned int)time(NULL));//Ϊ��ÿ�β�����ͬ�������
flag:
		while (count>0)//����û�в���ʱ��ִ��ѭ��
		{
				int x = rand()%(ROWS)+1;//����������±�
				int y = rand()%(COLS)+1;
				if(mine[x][y] =='@')//������λ���Ѿ������ף������������±�
				{
						goto flag;
				}
				else
				{
						mine[x][y] = '@';
						count--;//��һ����֮���׵ĸ���Ӧ�ü�һ
				}
		}
}

void play(char mine[ ][COLS+2],char show[ ][COLS+2])//ɨ��
{   
		int i = 0;
		int j = 0;
		int x = 0;
		int y = 0;
	/*lay_mines( mine);
	print_mine(mine,ROWS, COLS );*/
		printf("�������һ��Ҫ�����λ��>");
		scanf("%d %d",&x, &y);
	
		if (mine[x][y] == '@')//�����һ�ε���ľ����׵�λ�ã���Ӧ�ð����������
		{	
				for (i=0; i<x; i++)
				{
						for (j = 0; j<y; j++)
						{
								if (mine[i][j] != '@')
								{	
										mine[i][j] = mine[x][y];
										mine[x][y] = '+';
								}
						}
				}
		}
		else
		{
				//��������λ�ò����ף���Ӧ��ͳ���׵ĸ���
						show[x][y] = ((mine[x-1][y-1] == '@') 
						           + (mine[x][y-1] == '@') + (mine[x+1][y-1] == '@') + (mine[x+1][y] == '@') 
								   + (mine[x+1][y+1] == '@') + (mine[x][y+1] == '@') + (mine[x-1][y+1] == '@')
								   + (mine[x-1][y] == '@'))+ '0';


		}
		print_show(show, ROWS, COLS);
		//print_mine(mine, ROWS, COLS);//��ӡ������
		while(1)
		{
				printf("������Ҫ�����λ�ã�С��10��:>");
				scanf("%d %d",&x,&y);
				if(mine[x][y] == '@')
				{	
						printf("ը����\n");
						break;
				}
				else
				{      //��������λ�ò����ף���Ӧ��ͳ���׵ĸ���
						show[x][y] = ((mine[x-1][y-1] == '@') 
						           + (mine[x][y-1] == '@') + (mine[x+1][y-1] == '@') + (mine[x+1][y] == '@') 
								   + (mine[x+1][y+1] == '@') + (mine[x][y+1] == '@') + (mine[x-1][y+1] == '@')
								   + (mine[x-1][y] == '@'))+ '0';

				}
				print_show(show, ROWS+2, COLS+2);//��ӡ��ʾ�׵ĸ���������
			}
}