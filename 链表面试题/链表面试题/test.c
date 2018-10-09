#include"plist.h"
void TestPrintTailToHead()
{
	Node * plist = NULL;
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintLinkList(plist);
	PrintTailToHead(plist);
}
void TestDelNodeNotTail()
{
	Node * pos = NULL;
	Node * plist = NULL;
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintLinkList(plist);
	pos = Find(plist, 3);
	DelNodeNotTail(plist);
	if (pos != NULL)
	{
		DelNodeNotTail(pos);
	}
	PrintLinkList(plist);
}
void TestInsertNode()
{
	Node * pos = NULL;
	Node * plist = NULL;
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintLinkList(plist);
	pos = Find(plist, 3);
	DelNodeNotTail(plist);
	if (pos != NULL)
	{
		InsertNode(pos,5);
	}
	PrintLinkList(plist);
}
void TestJosephCycle()
{
	int i = 0;
	pNode plist = NULL;
	for (i = 1; i <= 10; i++)
	{
		PushBack(&plist, i);
	}
	PrintLinkList(plist);
	//构成环
	Find(plist, 10)->next = plist;
	JosephCycle(&plist,3);
}
void TestReverseList()
{
	int i = 0;
	pNode plist = NULL;
	for (i = 1; i <= 10; i++)
	{
		PushBack(&plist, i);
	}
	PrintLinkList(plist);
	ReverseList(&plist);
	PrintLinkList(plist);
}
void TestBubbleSort()
{
	int i = 0;
	pNode plist = NULL;
	for (i = 1; i <= 10; i++)
	{
		PushBack(&plist, 6-i);
	}
	BubbleSort(plist);
	PrintLinkList(plist);
}
void TestMerge()
{
	pList  plist1 = NULL;
	pList  plist2 = NULL;
	pList  plist = NULL;
	int i = 0;
	for(i = 1; i<=9; i+=2)
	{
		PushBack(&plist1, i);
	}
	PrintLinkList(plist1);
	for(i = 2; i<=6; i+= 2)
	{
		PushBack(&plist2, i);
	}
	PrintLinkList(plist2);
	plist = Merge(plist1, plist2);
	PrintLinkList(plist);
	DestroyLinkList(&plist);
}
void TestFindMidNode()
{
	pList plist = NULL;
	int i = 0;
	pNode pos = NULL;
	for (i = 1; i <= 9; i += 2)
	{
		PushBack(&plist, i);
	}
	PrintLinkList(plist);
	pos = FindMidNode(plist);
	if (pos != NULL)
	{
		printf("%d\n", pos->data);
	}
}
void TestFindLastKNode()
{
	pList plist = NULL;
	int i = 0;
	pNode pos = NULL;
	for (i = 0; i < 10; i++)
	{
		PushBack(&plist, i);
	}
	pos = FindLastKNode(plist, 3);
	if (pos != NULL)
		printf("%d\n", pos->data);
}
void TestCheckCycle()
{
	pList plist = NULL;
	int i = 0;
	pNode pos = NULL;
	for (i = 1; i <= 5; i++)
	{
		PushBack(&plist, i);
	}
	Find(plist, 5)->next = Find(plist, 3);
	pos = CheckCycle(plist);
	if (pos != NULL)
	{
		printf("带环，相遇点是%d\n", pos->data);
		printf("环的长度：\n"，GetCircleLength(pos));
	}
	else
	{
		printf("不带环\n");
	}
}
void TestGetCycleEntryNode()
{
	pList plist = NULL;
	int i = 0;
	pNode pos = NULL;
	for (i = 1; i <= 5; i++)
	{
		PushBack(&plist, i);
	}
	Find(plist, 5)->next = Find(plist, 3);
	pos = CheckCycle(plist);
	if (pos != NULL)
	{
		printf("带环，相遇点是%d\n", pos->data);
		printf("环的长度：%d\n"，GetCircleLength(pos));
		printf("%d\n", GetCycleEntryNode(plist,pos)->data);
	}
	else
	{
		printf("不带环\n");
	}
}
void TestCheckCross()
{
	pList  plist1 = NULL;
	pList  plist2 = NULL;
	pList plist = NULL;
	int i = 0;
	pNode pos = NULL;
	for (i = 1; i <= 9; i += 2)
	{
		PushBack(&plist1, i);
	}
	PrintLinkList(plist1);
	for (i = 2; i <= 6; i += 2)
	{
		PushBack(&plist2, i);
	}
	PrintLinkList(plist2);
	Find(plist2, 6)->next = Find(plist1, 3);
	if (CheckCross(plist1, plist2)==1)
	{
		printf("相交\n");
		pos=GetCrossNode(plist1, plist2);
		printf("交点是%d\n", pos->data);

	}
	else
	{
		printf("不相交\n");
	}
		
}

void TestUnionSet()
{
	pList  plist1 = NULL;
	pList  plist2 = NULL;
	pList  plist = NULL;
	int i = 0;
	for (i = 1; i <= 9; i++)
	{
		PushBack(&plist1, i);
	}
	PrintLinkList(plist1);
	for (i = 2; i <= 6; i++)
	{
		PushBack(&plist2, i);
	}
	PrintLinkList(plist2);
	UnionSet(plist1, plist2);
}
int main()
{
	/*TestPrintTailToHead();
	TestDelNodeNotTail();
	TestInsertNode();
	TestJosephCycle();
	TestReverseList();
	TestBubbleSort();
	TestMerge();
	TestFindMidNode();
	TestFindLastKNode();
	TestCheckCycle();
	TestGetCycleEntryNode();
	TestCheckCross();
	TestUnionSet();*/
	return 0;
}