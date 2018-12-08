#include"Queue.h"
#include"Stack.h"
#include"Topic.h"

////////////////////////////////////////////////////////////////
// 1.两个栈实现一个队列
void QueueByTwoStackInit(QueueByTwoStack* qts)
{
	StackEmpty(&qts->s1);
	StackEmpty(&qts->s2);
}
void QueueByTwoStackDestory(QueueByTwoStack* qts)

{
	StackDestory(&qts->s1);
	StackDestory(&qts->s2);
}

void QueueByTwoStackPush(QueueByTwoStack* qts, STDataType x)
{
	assert(qts != NULL);
	StackPush(&(qts->s1), x);
}
void QueueByTwoStackPop(QueueByTwoStack* qts)
{
	assert(qts != NULL);
	//如果s2有数据直接出
	//如果s2没有数据，就把s1的数据倒过来
	if (StackEmpty(&qts->s2) == 0)
	{
		while (StackEmpty(&qts->s1))
		{
			StackPush(&qts->s2, StackTop(&qts->s1));
			StackPop(&qts->s1);
		}
	}
}
STDataType QueueByTwoStackFront(QueueByTwoStack* qts)
{
	assert(qts != NULL);
	return StackTop(&qts->s2);
}
int QueueByTwoStackSize(QueueByTwoStack* qts)
{
	return StackSize(&qts->s1) + StackSize(&qts->s2);
}
int QueueByTwoStackEmpty(QueueByTwoStack* qts)
{

	return StackEmpty(&qts->s1);//StackEmpty(&qts->s2);
}

////////////////////////////////////////////////
// 2.两个队列实现一个栈
void StackByTwoQueueInit(StackByTwoQueue* stq)
{
	QueueInit(&stq->q1);
	QueueInit(&stq->q2);
}
void StackByTwoQueueDestory(StackByTwoQueue* stq)
{
	QueueDestory(&stq->q1);
	QueueDestory(&stq->q2);
}
QUDataType StackByTwoQueueTop(StackByTwoQueue* stq)
{
	if (QueueEmpty(&stq->q1))
	{
		return QueueBack(&stq->q1);
	}
	else
	{
		return QueueFront(&stq->q2);
	}
}
int StackByTwoQueueEmpty(StackByTwoQueue* stq)
{
	return QueueEmpty(&stq->q1)|QueueEmpty(&stq->q2);
}
int StackByTwoQueueSize(StackByTwoQueue* stq)
{
	return QueueSize(&stq->q1);
}

void StackByTwoQueuePush(StackByTwoQueue* stq, QUDataType x)
{
	assert(stq != NULL);
	if (QueueEmpty(&stq->q1) != 0)
	{
		QueuePush(&stq->q1, x);
	}
	else
	{
		QueuePush(&stq->q2, x);
	}
}
void StackByTwoQueuePop(StackByTwoQueue* stq)
{
	Queue* empty, *nonempty;
	assert(stq != NULL);
	empty = &stq->q1;
	nonempty = &stq->q2;
	if (QueueEmpty(&stq->q1) != 0)
	{
		empty = &stq->q2;
		nonempty = &stq->q1;
	}
	while (QueueSize(nonempty) > 1)
	{
		QueuePush(empty, QueueFront(nonempty));
		QueuePop(nonempty);
	}
	QueuePop(nonempty);
}

//////////////////////////////////////////////////////////////
// Min Stack
void MinStackInit(MinStack* pms)
{
	assert(pms != NULL);
	StackInit(&pms->_st);
	StackInit(&pms->_minst);
}
void MinStackDestory(MinStack* pms)
{
	assert(pms != NULL);
	StackDestory(&pms->_st);
	StackDestory(&pms->_minst);
}

void MinStackPush(MinStack* pms, MSTDataType x)
{
	assert(pms != NULL);
	StackPush(&pms->_st,x);
	if (StackEmpty(&pms->_minst) == 0
		||StackTop(&pms->_minst)>=x)
	{
		StackPush(&pms->_minst, x);
	}
}
void MinStackPop(MinStack* pms)
{
	assert(pms != NULL);
	if (StackTop(&pms->_st) == StackTop(&pms->_minst))
	{
		StackPop(&pms->_minst);
	}
		StackTop(&pms->_st);
}
MSTDataType MinStackMin(MinStack* pms)
{
	assert(pms != NULL);
	return StackTop(&pms->_minst);
}
//不合法 0
//合法 1
int IsLegalStackOrder(int* in, int* insize, int* out, int *outsize)
{
	assert(in&&out&&insize == outsize);
	Stack st;
	StackInit(&st);
	int inindex = 0;
	int outindex = 0;
	while (inindex < insize)
	{
		StackPush(&st, in[inindex]);
		++inindex;
		while(!StackEmpty(&st)
			&& StackTop(&st) == out[outindex])
		{
			StackPop(&st);
			++outindex;

		}
	}
	if (StackEmpty(&st) == 0)

	{
		return 1;
	}
	else
	{
		StackDestory(&st);
		return 0;
	}
}
//////////////////////////////////////////////////////
void ShareStackInit(ShareStack* pss)
{
	assert(pss != NULL);
	pss->_top1 = 0;
	pss->_top2 = 1;
}
void ShareStackInit_01(ShareStack* pss)
{
	assert(pss != NULL);
	pss->max_size = 10;
	pss->_top1 = 0;
	pss->_top2 = pss->max_size;

}
void ShareStackPush1(ShareStack* pss, SSDataType x)
{
	assert(pss != NULL);
	if (pss->_top1 == pss->_top2)
	{
		return;
	}
	pss->_a[pss->_top1] = x;
	pss->_top1++;
	return;
}

void ShareStackPush2(ShareStack* pss, SSDataType x)
{
	assert(pss != NULL);
	if (pss->_top1 == pss->_top2)
	{
		return;
	}
	pss->_top2--;
	pss->_a[pss->_top2] = x;
}


// which 1、2
void ShareStackPush(ShareStack* pss, SSDataType x, int which)
{
	assert(pss&&which==1||which==2);
	
	if (which == 1)
	{
		if (pss->_top1 >= N)
		{
			printf("Stack1 Full\n"); 
			return;
		}
			
		pss->_a[pss->_top1] = x;
		pss->_top1 += 2;
	}
	else if (which == 2)
	{
		if (pss->_top2 >= N)
		{
			printf("Stack2 Full\n");
			return;
		}
		pss->_a[pss->_top2] = x;
		pss->_top2 += 2;
	}

}
void ShareStackPop(ShareStack* pss, int which)
{
	assert(pss&&which == 1 || which == 2);
	if (which == 1)
	{
		if (0 == pss->_top1)
		{
			printf("栈1为空\n");
		}
		pss->_top1 -= 2;
	}
	else
	{
		if (0 == pss->_top2)
		{
			printf("栈2为空\n");
		}
		pss->_top2 -= 2;
	}
}
SSDataType ShareStackTop(ShareStack* pss, int which)
{
	assert(pss&&which == 1 || which == 2);
	if (which == 1)
	{
		return pss->_a[pss->_top1 - 1];
	}
	else
	{
		return pss->_a[pss->_top2 - 1];
	}
}