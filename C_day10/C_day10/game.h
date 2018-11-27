#ifndef _GAME_H_  
#define _GAME_H_  

#include<stdio.h>  
#include"game.h"  
#include<stdlib.h>  
#include<time.h>  
#include<string.h>  
#pragma warning(disable:4996)  

typedef unsigned int uint;

enum OPTION
{
	EXIT,
	START
};

#define ROW 3  
#define  COL 3  

void menu();
void init_board(char board[ROW][COL], int row, int col);//初始化棋盘
void print_board(char board[ROW][COL], int row, int col);//打印棋盘
void computer_move(char board[ROW][COL], int row, int col);//电脑走
void  palyer_move(char board[ROW][COL], int row, int col);//玩家走
int is_full(char board[ROW][COL], int row, int col);//判断是否下满
char is_win(char board[ROW][COL], int row, int col);//判断输赢


#endif //_GAME_H_  