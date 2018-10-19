#pragma once

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include<stdlib.h>


typedef int DataType;
#define DEFAULT_SZ 5
typedef struct QueueNode
{
	struct QueueNode* _next;
	DataType _data;
}QueueNode, *pQueueNode;

typedef struct Queue
{
	QueueNode* _front; // 队头
	QueueNode* _back;  // 队尾
	int _size; //队列当前长度
	int _capacity; //队列总长度
	DataType _data;
}Queue, *pQueue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);

QueueNode* BuyQueueNode(DataType x);
void QueuePush(Queue* pq, DataType x);
void QueuePop(Queue* pq);
DataType QueueFront(Queue* pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);

void TestQueue();