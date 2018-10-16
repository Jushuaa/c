#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include"Stack.h"



#define N 6
static int maze[N][N] =
{
	{ 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 0 },
	{ 0, 0, 1, 0, 1, 0 },
	{ 0, 0, 1, 1, 1, 0 },
	{ 0, 0, 1, 0, 1, 1 },
	{ 0, 0, 1, 0, 0, 0 },
};



int GetMazePath(Pos entry, Pos exit);
void MazePrint();
int GetMazePathR(Pos entry,Pos exit);
int CheckAccess(Pos next);
int pathsize = 0;
void  MazeGetShortPath(Pos entry, Pos exit);