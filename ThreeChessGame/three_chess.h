#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#define ROWS 3
#define COLS 3
void menu();
void init_board(char arr[][COLS], int x, int y);//��ʼ������
void print_board(char arr[][COLS], int x, int y);//��ӡ����
void player_move(char arr[][COLS]);//�������
int check_full(char arr[][COLS], int x, int y);//�ж������Ƿ�����
void computer_move(char arr[][COLS]);//��������
char check_win(char arr[][COLS], int x, int y);//�ж�˭Ӯ