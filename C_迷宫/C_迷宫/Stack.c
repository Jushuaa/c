
#include"Stack.h"



void StackInit(Stack* ps)
{
	assert(ps);
	ps->data = (STDataType *)malloc(sizeof(STDataType)* DEFAULT_SZ);
	ps->_capacity = DEFAULT_SZ;
	ps->_top = ps->_end;
	ps->_size = 0;

}
void StackDestroy(Stack* ps)//销毁栈
{
	assert(ps);
	int i, len;
	len = ps->_size;
	if (ps->_top == ps->_end)
	{
		printf("栈为空，无法销毁\n");
		return;
	}
	else
	{
		for (i = 0; i < len; i++)
		{
			free(ps->_end);
			ps->_end++;
		}
		ps->_size = 0;
		ps->_capacity = 0;
		ps->_top = ps->_end = NULL;
	}
}
void StackPush(Stack* ps, STDataType x)
{
	PNODE newNode = (PNODE)malloc(sizeof(NODE));
	newNode->data = x;
	newNode->next = ps->_top;
	ps->_top = newNode;
}
void StackPop(Stack* ps)
{
	PNODE tmp = (PNODE)malloc(sizeof(NODE));
	assert(ps != NULL&&ps->_top != NULL&&ps->_end != NULL);
	tmp = ps->_top->next;
	free(ps->_top);
	ps->_top = NULL;
	ps->_top = tmp;
	ps->_size--;
}
STDataType StackTop(Stack* ps)
{
	assert(ps != NULL);
	STDataType  d = ps->_top->data;
	return d;
}
int StackEmpty(Stack* ps)
{
	
	if (ps->_top = ps->_end)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int StackSize(Stack* ps)
{
	assert(ps != NULL);
	while (ps)
	{
		ps->_top++;
		ps->_size++;
	}
	return ps->_size;
}

void StackPrint(Stack *ps)
{
	PNODE tmp = ps->_top;
	while (tmp != ps->_end)
	{
		printf("%d", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}