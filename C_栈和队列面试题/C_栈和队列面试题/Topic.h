#pragma once

#include "Queue.h"
#include "Stack.h"


////////////////////////////////////////////////////////////////
// 1.两个栈实现一个队列
typedef struct QueueByTwoStack
{
	Stack s1;
	Stack s2;
}QueueByTwoStack;

void QueueByTwoStackInit(QueueByTwoStack* qts);
void QueueByTwoStackDestory(QueueByTwoStack* qts);

void QueueByTwoStackPush(QueueByTwoStack* qts, STDataType x);
void QueueByTwoStackPop(QueueByTwoStack* qts);
STDataType QueueByTwoStackFront(QueueByTwoStack* qts);

int QueueByTwoStackSize(QueueByTwoStack* qts);
int QueueByTwoStackEmpty(QueueByTwoStack* qts);

void TestQueueByTwoStack();

////////////////////////////////////////////////
// 2.两个队列实现一个栈

typedef struct StackByTwoQueue
{
	Queue q1;
	Queue q2;
}StackByTwoQueue;


void StackByTwoQueueInit(StackByTwoQueue* stq);
void StackByTwoQueueDestory(StackByTwoQueue* stq);
QUDataType StackByTwoQueueTop(StackByTwoQueue* stq);
int StackByTwoQueueEmpty(StackByTwoQueue* stq);
int StackByTwoQueueSize(StackByTwoQueue* stq);

void StackByTwoQueuePush(StackByTwoQueue* stq, QUDataType x);
void StackByTwoQueuePop(StackByTwoQueue* stq);

void TestStackByTwoQueue();

//////////////////////////////////////////////////////////////
// Min Stack

typedef int MSTDataType;

typedef struct MinStack
{
	Stack _st;
	Stack _minst;
}MinStack;

void MinStackInit(MinStack* pms);
void MinStackDestory(MinStack* pms);

void MinStackPush(MinStack* pms, MSTDataType x);
void MinStackPop(MinStack* pms);
MSTDataType MinStackMin(MinStack* pms);
void TestMinStack();

void TestIsLegalStackOrder();
//////////////////////////////////////////////////////
#define N 100
typedef int SSDataType;
typedef struct ShareStack
{
	SSDataType _a[N];
	int _top1;
	int _top2;
	int max_size;
}ShareStack;

void ShareStackInit(ShareStack* pss);
void ShareStackInit_01(ShareStack* pss);
void ShareStackPush1(ShareStack* pss, SSDataType x);//左边入栈
void ShareStackPush2(ShareStack* pss, SSDataType x);//右边入栈

// which 1、2
void ShareStackPush(ShareStack* pss, SSDataType x, int which);
void ShareStackPop(ShareStack* pss, int which);
SSDataType ShareStackTop(ShareStack* pss, int which);
void TestShareStack();