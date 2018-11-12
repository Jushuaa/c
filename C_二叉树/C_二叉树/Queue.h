#pragma once

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <limits.h>
//顺序结构和链式结构都能实现
//链式结构更好 便于删除
//链式结构需要一个节点  结构体
typedef int QUDataType;
typedef struct QueueNode
{
	struct QueueNode* _next; //节点域
	QUDataType _data;      //数据域
}QueueNode;

typedef struct Queue
{
	QueueNode* _front; // 队头
	QueueNode* _back;  // 队尾
}Queue;
void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
QueueNode* BuyQueueNode(QUDataType x);
void QueuePush(Queue* pq, QUDataType x);
void QueuePop(Queue* pq);
QUDataType QueueFront(Queue* pq);
QUDataType QueueBack(Queue* pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);
void TestQueue();