#include "Queue.h"
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_front = NULL;
	pq->_back = NULL;
}
void QueueDestory(Queue* pq)
{
	QueueNode *cur = NULL;
	QUDataType *del = NULL;
	assert(pq);
	if (pq->_front == NULL)
		return;
	del = pq->_front;
	cur = pq->_front->_next;
	while (cur) //cur->_back!=NULL   最后一个节点没有释放
	{
		free(del); //节点释放，内存还在，空间还在,空间的值被置位随机值
		del = cur;
		cur = cur->_next;
	}
	pq->_front = pq->_back = NULL;
}
QUDataType* BuyQUDataType(QUDataType x)
{
	QueueNode *newNode = (QUDataType*)malloc(sizeof(QUDataType));
	assert(newNode);
	newNode->_data = x;
	newNode->_next = NULL;
	return newNode;
}

void QueuePush(Queue* pq, QUDataType x)
{
	QUDataType *newNode = NULL;
	assert(pq);
	newNode = BuyQUDataType(x);
	if (pq->_back == NULL)
	{
		pq->_front = newNode;
		pq->_back = newNode;
	}
	else
	{
		pq->_back->_next = pq->_back;

	}
}

void QueuePop(Queue* pq)
{
	QUDataType *cur = NULL;
	assert(pq);
	if (pq->_front == NULL)
		return;
	cur = pq->_front->_next; //先将下一个节点保存，在free front,防止内存泄漏
	free(pq->_front);
	pq->_front = cur;
	if (cur == NULL)
	{
		pq->_back = NULL;
	}
}

//return INT_MAX表示队列为空
QUDataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->_front->_data;
}
QUDataType QueueBack(Queue* pq)
{
	return pq->_back->_data;
}
//空返回0、非空返回1
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_front == NULL ? 0 : 1;
}

int QueueSize(Queue* pq)
{
	int count = 0;
	QueueNode *cur = pq->_front;
	while (cur)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}

void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	while (QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	QueueDestory(&q);
}