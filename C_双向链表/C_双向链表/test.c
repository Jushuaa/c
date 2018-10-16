#include"list.h"
void Testlist()
{
	ListNode * lt;
	ListInit(&lt);
    //ListDestory(&lt);
	//ListInsert(&pos, x);
	ListPushBack(&lt, 1);
	ListPushBack(&lt, 2);
	ListPushBack(&lt, 3);
	ListPushBack(&lt, 4);
	ListPrint(&lt);
	////ListPushFront(&lt, 1);
	//ListPopBack(&lt);
	//ListPopBack(&lt);
	//ListPopBack(&lt);
	//ListPrint(&lt);
	////ListPopFront(&lt);
	int x = ListFind(&lt,2);
	if (x == -1)
	{
		printf("没找到\n");
	}
	else
	{
		printf("%d\n", x);
	}
	
	//ListErase(&lt, 2,3);
	int size=ListSize(&lt);
	printf("%d\n", size);
	int ret = ListEmpty(&lt);
	if (ret == 1)
	{
		printf("链表为空\n");
	}
	else
	{
		printf("链表不为空\n");
	}
	
}

int main()
{
	Testlist();
	system("pause");
	return;
}