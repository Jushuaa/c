#include"Stack.h"

void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = (STDataType*)malloc(sizeof(STDataType)*START_SIZE);
	ps->_capacity = START_SIZE;
	ps->_top = 0;
}

void StackDestory(Stack* ps)
{
	assert(ps);
	if (ps->_a)
	{
		free(ps->_a);
		ps->_a = NULL;
		ps->_top = ps->_capacity = 0;
	}
}
void StackPush(Stack* ps,STDataType x)
{
	assert(ps);
	if (ps->_capacity == ps->_top)
	{
		ps->_a = (STDataType*)realloc(ps->_a, sizeof(STDataType)*(ps->_capacity + ADD_SIZE));
		ps->_capacity += ADD_SIZE;
		assert(ps->_a);
		ps->_capacity += ADD_SIZE;
	}
	ps->_a[ps->_top++] = x;
	ps->_top++;
}
	
void StackPop(Stack* ps)
{
	assert(ps->_a);
	assert(ps->_top > 0);
	ps->_top--;
}
STDataType StackTop(Stack* ps)
{
	assert(ps->_a);
	assert(ps->_top>0);
	return ps->_a[ps->_top - 1];
}

//0表示空、1表示非空
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}

int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
void TestStack()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 11);
	StackPush(&s, 22);
	StackPush(&s, 33);
	StackPush(&s, 44);
	while (StackEmpty(&s))
	{
		printf("%d ", StackTop(&s));
		StackPop(&s);
	}
	StackDestory(&s);
}
