#include"list.h"
ListNode* BuyListNode(LTDataType x)
{
	ListNode *newnode = NULL;
	newnode = (LTDataType*)malloc(sizeof(LTDataType));
	if (newnode != NULL)
	{
		newnode->_data = x;
		newnode->_prev = NULL;
		newnode->_next = NULL;
	}
	return newnode;
}
void ListInit(List* lt)
{
	assert(lt != NULL);
	lt->_head = BuyListNode(0);
	lt->_head->_next = lt->_head;
	lt->_head->_prev = lt->_head;
	int size = 0;
}
void ListDestory(List* lt)
{
	ListNode* temp;
	ListNode* p;

	p = lt->_head->_prev;

	while (!ListEmpty(lt))

	{

		temp = p->_prev;

		free(p);

		p = temp;

		lt->_head->_prev = temp;

		lt->_size--;

	}
}
void ListPushBack(List* lt, LTDataType x)
{
	ListInsert(lt->_head, x);
}
void ListPushFront(List* lt, LTDataType x)
{
	ListInsert(lt->_head->_next, x);
}
void ListErase(List* lt, ListNode* pos, LTDataType x)
{
	if (lt == NULL&&pos < 1)
	{
		return;
	}
	if (pos>ListSize(lt))
	{
		return;
	}
	ListNode *pNode = lt;
	int count = 0;
	while (count < ListSize(lt))
	{
		pNode = pNode->_next;
		count++;
	}
	if (count != pos)
		return;
	x = pNode->_data;
	pNode->_prev->_next = pNode->_next;
	pNode->_next->_prev = pNode->_prev;
	free(pNode);
	pNode = NULL;

}
void ListPopBack(List* lt,ListNode* pos,LTDataType x)
{
	assert(lt != NULL);
	ListErase(lt->_head, pos, x);
}
void ListPopFront(List* lt, ListNode* pos, LTDataType x)
{
	assert(lt != NULL);
	ListErase(lt->_head->_next, pos, x);
}


ListNode* ListFind(List* lt, LTDataType x)
{
	int i = 1;
	while (lt != NULL && lt->_head->_data != x)//寻找值为x的元素**注意这里循环的条件不能写反。原因，当L == NULL 时候 L->data会出错
	{
		i++;
		lt = lt->_head->_next;
	}
	if (lt == NULL)               //如果没找到返回-1
		return -1;
	else
		return i;
}
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos != NULL);
	ListNode * newnode = BuyListNode(3);
	newnode->_data = x;
	ListNode* prev = pos->_prev;
	prev->_next = newnode;
	newnode->_next = pos;
	newnode->_prev = prev;
	pos->_prev = newnode;
}

int ListSize(List* lt)
{
	assert(lt != NULL);
	return (lt->_head->_prev) - (lt->_head->_next);
}
int ListEmpty(List* lt)
{
	if (ListSize(lt) == 0 && lt->_head->_next == lt->_head->_prev)
		return 1;
	else
		return 0;
	
}
void ListPrint(List* lt)
{
	ListNode *cur = lt->_head->_next;
	while (cur != lt->_head)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}