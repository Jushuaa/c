#include"maze.h"
#include"Stack.h"
void MazePrint()
{
	size_t i, j;
	for (i = 0; i < N; ++i)
	{
		for (j = 0; i < N; ++j)
		{
			printf("%d", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int GetMazePath(Pos entry, Pos exit)
{
	Stack path;
	StackInit(&path);
	StackPush(&path, entry);
	while (StackEmpty(&path))
	{
		Pos cur = StackTop(&path);
		Pos next;
		maze[cur._row][cur._col] = 2;
		//if (cur._row == exit._row&&
			//cur._col == exit._col)
		if (cur._col==5)
		{
			StackDestroy(&path);
			return 1;

		}
		//探测下一个可以去的位置
		//上
		next = cur;
		next._row -= 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		//下
		next = cur;
		next._row += 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		//左
		next = cur;
		next._col -= 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		//右
		next = cur;
		next._col += 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		StackPop(&path);
		
	}
	return 0;
}
int GetMazePathR(Pos entry, Pos exit)
{
	Stack path;
	StackInit(&path);
	StackPush(&path, entry);
	while (StackEmpty(&path))
	{
		Pos cur = StackTop(&path);
		Pos next;
		maze[cur._row][cur._col] = 2;
		if (cur._row == exit._row&&
		cur._col == exit._col)		
		{
			StackDestroy(&path);
			return 1;

		}
		//探测下一个可以去的位置
		//上
		next = cur;
		next._row -= 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		//下
		next = cur;
		next._row += 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		//左
		next = cur;
		next._col -= 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		//右
		next = cur;
		next._col += 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		StackPop(&path);

	}
	return 0;
}
int CheckAccess(Pos next)
{
	if (next._row >= 0 && next._row<N
		&&next._col >= 0 && next._col>N
		&&maze[next._row][next._col]==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int CheckAccessShort(Pos cur,Pos next)
{
	if (next._row >= 0 && next._row<N
		&&next._col >= 0 && next._col>N
		&&(maze[next._row][next._col] == 1||maze[next._row][next._col]>maze[cur._row][cur._col]+1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void MazeGetShortPath(Pos entry, Pos exit)
{
	
	Stack path;
	StackInit(&path);
	StackPush(&path, entry);
	maze[entry._row][exit._col];
	while (StackEmpty(&path))
	{
		Pos cur = StackTop(&path);
		Pos next;
		//maze[cur._row][cur._col] = 2;
		
		if (cur._col==5)
		{
			if (pathsize==0||
				StackSize(&path) < pathsize)
			{
				pathsize = StackSize(&path);
			}

		}
		//探测下一个可以去的位置
		//上
		next = cur;
		next._row -= 1;
		if (CheckAccessShort(cur,next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}
		//下
		next = cur;
		next._row += 1;
		if (CheckAccessShort(cur,next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}
		//左
		next = cur;
		next._col -= 1;
		if (CheckAccessShort(cur,next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}
		//右
		next = cur;
		next._col += 1;
		if (CheckAccessShort(cur,next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}
		StackPop(&path);

	}
	//return 0;
}