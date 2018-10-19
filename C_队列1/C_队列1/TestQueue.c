#include"Queue.h"
void TestQueue()
{
	Queue pq;
	QueueInit(&pq);
	QueuePush(&pq, 1);
	QueuePush(&pq, 2);
	QueuePush(&pq, 3);
	QueuePush(&pq, 4);
	printf("%d\n", QueueSize(&pq));
	while (QueueEmpty(&pq))
	{
		printf("%d ", QueueFront(&pq));
		QueuePop(&pq);
	}
	printf("\n");
}
int main()
{
	TestQueue();
	system("pause");
	return 0;
}