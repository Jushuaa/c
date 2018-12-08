#pragma once

#include <malloc.h>
#include <assert.h>
#include<stdio.h>
#include <stdlib.h>



typedef int QUDataType;
#define DEFAULT_SZ 5
typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode, *pQueueNode;

typedef struct QUQueue
{
	QueueNode* _front; // 队头
	QueueNode* _back;  // 队尾
	int _size; //队列当前长度
	int _capacity; //队列总长度
	QUDataType _data;
}Queue, *pQueue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);

QueueNode* BuyQueueNode(QUDataType );
void QueuePush(Queue* pq,QUDataType x);
void QueuePop(Queue* pq);
QUDataType QueueFront(Queue* pq);
QUDataType QueueBack(Queue* pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);

void TestQueue();