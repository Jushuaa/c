#include"plist.h"
pNode BuyNode(DataType d)
{
	pNode tmp = (pNode)malloc(sizeof(Node));
	if (tmp == NULL)
	{
		perror("BuyNode::malloc");
		return NULL;
	}
	tmp->data = d;
	tmp->next = NULL;
	return tmp;
}
void PushFront(pList* pplist, DataType d)
{
	assert(pplist != NULL);
	pNode newNode = NULL;
	newNode = BuyNode(d);
	newNode->next = *pplist;
	*pplist = newNode;
}
void PushBack(pList* pplist, DataType d)
{
	pNode newNode = BuyNode(d);
	assert(pplist != NULL);
	if (newNode == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (*pplist == NULL)
	{
		*pplist = newNode;
	}
	else
	{
		pNode cur = *pplist;
		while ((cur->next) != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}
pNode Find(pList plist, DataType d)
{
	pNode cur = NULL;
	assert(plist != NULL);
	cur = plist;
	if (plist == NULL)
	{
		return NULL;
	}
	else
	{
		if (cur->data == d)
		{
			return cur;
			cur = cur->next;
		}
	}
	return NULL;
}
void PrintLinkList(pList plist)
{
	pNode cur = plist;
	while (cur)
	{
		printf("&d-->", cur->data);
		cur = cur->next;
	}
	printf("over\n");
}
void DestroyLinkList(pList* pplist)//销毁链表
{
	assert(pplist != NULL);
	pNode cur = *pplist;
	while (cur != NULL)
	{
		pNode del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	*pplist = NULL;
}
void PrintTailToHead(pList plist)
{
	pNode cur = plist;
	pNode tail = NULL;
	if (plist == NULL)
	{
		return;
	}
	if ((plist->next) == NULL)
	{
		printf("%d", (plist->data));
		return;
	}
	while (plist != tail)
	{
		cur = plist;
		while (cur->next != tail)
		{
			cur = cur->next;
		}
		printf("%d", cur->data);
		tail = cur;
	}
}
void DelNodeNotTail(pNode pos)
{
	pNode del = NULL;
	assert(pos != NULL&&pos->next != NULL);
	del = pos->next;
	pos->data = pos->next->data;
	del->next = pos->next;
	free(del);
	del = NULL;
}
void InsertNode(pNode pos,DataType d)
{
	pNode newNode = NULL;
	assert(pos != NULL);
	DataType tmp = 0;
	newNode = BuyNode(d);
	newNode->next = pos->next;
	pos->next = newNode;
	tmp = pos->data;
	pos->data = newNode->data;
	newNode->data = tmp;
}
void JosephCycle(pList * pplist, int k)//单链表实现约瑟夫环
{
	pNode cur = *pplist;
	while (cur != cur->next)
	{
		int count = k;
		pNode del = NULL;
		while (--count)
		{
			cur = cur->next;
		}
		printf("删除\n", cur->data);
		cur->data = cur->next->data;
		del = cur->next;
		cur->next = del->next;
		free(del);
		del = NULL;
	}
	printf("幸存者\n", cur->data);
}
void ReverseList(pList* pplist)
{
	////第一种
	//assert(pplist != NULL);
	//pNode n1, n2, n3;
	//if (*pplist == NULL)
	//	return;
	//if (*pplist->next == NULL)
	//	return;
	//while (n2)
	//{
	//	n2->next = n1;
	//	n1 = n2;
	//	n2 = n3;
	//	if (n3 != NULL)
	//		n3 = n3->next;
	//}
	//(*pplist)->next = NULL;
	//*pplist = n1;
	//第二种
	assert(pplist != NULL);
	pNode head = NULL;
	pNode cur = NULL;
	pNode tmp = NULL;
	if ((*pplist == NULL) || ((*pplist)->next== NULL))
		return;
	while (cur != NULL)
	{
		cur->next = head;
		head = cur;
		cur = tmp;
		if (tmp != NULL)
			tmp = tmp->next;
	}
	*pplist = head;
}
void BubbleSort(pList plist)
{
	pNode tail = NULL;
	int flag = 0;
	if ((plist == NULL) || (plist->next) == NULL)
	{
		return;
	}
	while (plist != tail)
	{
		pNode cur = NULL;
		pNode next = cur->next;
		while (next != tail)
		{
			if (cur->data > next->data)
			{
				DataType tmp = cur->data;
				cur->data = next->data;
				next->data = tmp;
				flag = 1;
			}
			cur = cur->next;
			next = cur->next;
		}
		tail = cur;
		if (flag == 0)
			return;
	}
}
pList  Merge(pList plist1, pList plist2)
{
	pList newlist = NULL;
	pNode tail = NULL;
	if (plist1 == plist2)
		return NULL;
	if (plist1 == NULL)
		return plist2;
	if (plist2 == NULL)
		return plist1;
	if (plist1->data < plist2->data)
	{
		newlist = plist1;
		plist1 = plist1->next;
	}
	else
	{
		newlist = plist2;
		plist2 = plist2->next;
	}
	tail = newlist;
	while ((plist1 != NULL) && (plist2 != NULL))
	{
		if (plist1->data < plist2->data)
		{
			tail->next = plist1;
			plist1 = plist1->next;
		}
		else
		{
			tail->next = plist2;
			plist2 = plist2->next;
		}
		tail = tail->next;
	}
	if (plist1 == NULL)
	{
		tail->next = plist2;
	}
	else if (plist2 == NULL)
	{
		tail->next = plist1;
	}
	return newlist;
}
pList  Merge_R(pList plist1, pList plist2)
{
	pList newlist = NULL;
	pNode tail = NULL;
	if (plist1 == plist2)
		return NULL;
	if (plist1 == NULL)
		return plist2;
	if (plist2 == NULL)
		return plist1;
	if ((plist1->data )< (plist2->data))
	{
		newlist = plist1;
		newlist->next = Merge_R(plist1->next, plist2);
	}
	else
	{
		newlist = plist2;
		newlist->next = Merge_R(plist1, plist2->next);
	}
	return newlist;
}
pNode FindMidNode(pList plist)
{
	pNode fast = plist;
	pNode slow = plist;
	if ((plist == NULL) || (plist->next) == NULL)
		return plist;
	while ((fast != NULL) && (fast->next) != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
pNode FindLastKNode(pList plist, int k)
{
	pNode fast = NULL;
	pNode slow = NULL;
	if (k == 0)
		return;
	if (plist == NULL)
		return plist;
	while (k--)
	{
		if (fast == NULL)
		{
			return NULL;
		}
		fast = fast->next;
	}
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
pNode CheckCycle(pList plist)
{
	pNode fast = NULL;
	pNode slow = NULL;
	if (plist == NULL)
		return plist;
	while ((fast != NULL) && (fast->next) != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return slow;
	}
	return NULL;
	
}
int GetCircleLength(pNode meet)
{
	pNode cur = NULL;
	assert(meet != NULL);
	cur = meet->next;
	int len = 1;
	while (cur != meet)
	{
		len++;
		cur = cur->next;
	}
	return len;
}
pNode GetCycleEntryNode(pList plist, pNode meet)
{
	pNode cur = plist;
	if (plist == NULL);
	return NULL;
	assert(meet != NULL);
	while (cur != meet)
	{
		cur = cur->next;
		meet = meet->next;
	}
	return meet;
}
int CheckCross(pList plist1, pList plist2)
{
	pNode end1 = plist1;
	pNode end2 = plist2;
	if ((plist1 == NULL) && (plist2 == NULL))
		return NULL;
	while (end1->next != NULL)
	{
		end1 = end1->next;
	}
	while (end2->next != NULL)
	{
		end2 = end2->next;
	}
	return end1 = end2;
}
pNode GetCrossNode(pList plist1, pList plist2)
{
	int len1 = 0;
	int len2 = 0;
	pNode cur1 = plist1;
	pNode cur2 = plist2;
	int gap = 0;
	while (cur1)
	{
		len1++;
		cur1 = cur1->next;
	}
	while (cur2)
	{
		cur2 = cur2->next;
	}
	gap = abs(len1 - len2);
	cur1 = plist1;//长
	cur2 = plist2;//短
	if (len1 < len2)
	{
		cur1 = plist2;
		cur2 = plist1;
	}
	while (cur1 != cur2)
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur2;
}
void UnionSet(pList plist1, pList plist2)
{
	if ((plist1 == NULL) || (plist2) == NULL)
		return;
	while (plist1&&plist2)
	{
		if (plist1->data > plist2->data)
		{
			plist1 = plist1->next;
		}
		else if (plist1->data > plist2->data)
		{
			plist2 = plist2->next;
		}
		else
		{
			printf("%d", plist1->data);
			plist1 = plist1->next;
			plist2 = plist2->next;
		}
	}
}