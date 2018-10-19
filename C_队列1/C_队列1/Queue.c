#include"Queue.h"
void QueueInit(Queue* pq)
{
	assert(pq != NULL);
	pq->_front = pq->_back = (DataType*)malloc(sizeof(DataType)*DEFAULT_SZ);
	if (!pq->_front)
	{
		exit(0);
	}
	pq->_front->_next = NULL;
	pq->_size = 0;
	pq->_capacity = DEFAULT_SZ;
}
void QueueDestory(Queue* pq)
{
	assert(pq != NULL);
	if (pq == NULL)
	{
		printf("队列为空，无法销毁\n");
	}
	pQueueNode node = pq->_front;
	while (node)
	{
		pQueueNode cur = node->_next;
		free(node);
		node = cur;
	}
	pq->_front = pq->_back = NULL;
}

QueueNode* BuyQueueNode(DataType x)
{
	pQueueNode node = (pQueueNode)malloc(sizeof(QueueNode));
	node->_data = x;
	node->_next = NULL;
	return node;
}
void QueuePush(Queue* pq, DataType x)
{
	if (pq->_size == pq->_capacity)
	{
		DataType * ptr=NULL;
		ptr = (DataType *)realloc(pq->_data, sizeof(DataType)*(pq->_capacity) + 1);
		pq->_back->_data = x;
		pq->_back->_next = pq->_back;
	}
}
void QueuePop(Queue* pq)
{
	assert(pq != NULL);
	if (pq->_front == NULL)//空队列
	{
		pq->_front = pq->_back = NULL;
	}
	else
	{
		pQueueNode node = pq->_front->_next;
		free(pq->_front);
		pq->_front = node;
		if (pq->_front== NULL)
		{
			pq->_back = NULL;
		}
	}
}
DataType QueueFront(Queue* pq)
{
	assert(pq != NULL);
	if (pq->_size == 0)
	{
		printf("队列为空，无法取出\n");
		return 0;
	}
	return pq->_front->_data;
}
int QueueEmpty(Queue* pq)
{
	assert(pq != NULL);
	if (pq->_front == pq->_back)
	{
		printf("队列已空，无法清空\n");
		return 0;
	}
	else
	{
		pq->_size = 0;
		pq->_capacity = 0;
		pq->_data = NULL;
	}
}
int QueueSize(Queue* pq)
{
	assert(pq != NULL);
	if (QueueEmpty)
	{
		return 0;
	}
	else
	{
		return (pq->_back - pq->_front);
	}
}

