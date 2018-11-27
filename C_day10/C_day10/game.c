#include"game.h"

void init_board(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void print_board(char board[ROW][COL], int row, int col)
	{
		int i = 0;
		for (i = 0; i < row; i++)
		{
			printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
			if (i != row - 1)
			{
				printf("---|---|---\n");
			}
		}
	}
void computer_move(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	while (1)
	{
		x = rand() % ROW;
		y = rand() % COL;
		if (board[x][y] = ' ')
		{
			board[x][y] = '*';
			break;
		}
	}
}
void  palyer_move(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("请输入坐标：");
	while (1)
	{
		scanf("%d,%d", &x, &y);
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
			}
			else
			{
				printf("该坐标已被占用，请重新输入：\n");
			}
		}
		else{
			printf("坐标输入不合法，请重新输入：\n");
		}
	}
}
static int is_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (int i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
		return 1;
	}
}
char is_win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][2] != ' '))
		{
			return  board[i][1];
		}
	}
	for (j = 0; j < col; j++)
	{
		if ((board[0][j] == board[1][j]) && (board[1][j] == board[2][j]) && (board[2][j] != ' '))
		{
			return  board[1][j];
		}
	}
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[2][2] != ' '))
	{
		return board[1][1];
	}
	else if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[1][1] != ' '))
	{
		return board[1][1];
	}
	else if (is_full(board, ROW, COL) == 1)
	{
		return 'Q';
	}
	else
		return ' ';
}