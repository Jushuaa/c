#include"maze.h"
#include"Stack.h"
void TestMaze()
{
	Pos entry,exit;
	entry._row = 5;
	entry._col = 2;
	
	exit._row = 4;
	exit._col = 5;
	MazePrint();
	printf("是否有出口：%d\n", GetMazePath(entry, exit));
	printf("最短路径：%d\n", pathsize);
	MazePrint();
}
int main()
{	
	TestMaze();
	system("pause");
	return 0;
}