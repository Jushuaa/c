#include"Queue.h"
#include"Stack.h"
#include"Topic.h"
void TestQueueByTwoStack()
{
	QueueByTwoStack qts;
	QueueByTwoStackInit(&qts);
	QueueByTwoStackPush(&qts, 1);
	QueueByTwoStackPush(&qts, 2);
	QueueByTwoStackPush(&qts, 3);
	
	QueueByTwoStackPop(&qts);
	QueueByTwoStackPop(&qts);
	QueueByTwoStackPush(&qts, 4);
	QueueByTwoStackPush(&qts, 5);
	while (QueueByTwoStackEmpty(&qts))
	{
		printf("%d", QueueByTwoStackFront(&qts));
		QueueByTwoStackPop(&qts);
	}
	printf("\n");
}
void TestStackByTwoQueue()
{
	StackByTwoQueue stq;
	StackByTwoQueueInit(&stq);
	StackByTwoQueuePush(&stq, 1);
	StackByTwoQueuePush(&stq, 2);
	StackByTwoQueuePush(&stq, 3);
	StackByTwoQueuePush(&stq, 4);
	while (StackByTwoQueueEmpty(&stq))
	{
		printf("%d", StackByTwoQueueTop(&stq));
		StackByTwoQueuePop(&stq);
	}
	printf("\n");
}
void TestMinStack()
{
	MinStack mst;
	MinStackInit(&mst);
	MinStackPush(&mst,1);
	MinStackPush(&mst, 4);
	MinStackPush(&mst, 0);
	MinStackPush(&mst, 0);
	MinStackPush(&mst, 8);
	MinStackPush(&mst, 0);
	printf("min:%d\n", MinStackMin(&mst));
	MinStackPop(&mst);
	printf("min:%d\n", MinStackMin(&mst));
	MinStackPop(&mst);
	printf("min:%d\n", MinStackMin(&mst));
	MinStackPop(&mst);
	printf("min:%d\n", MinStackMin(&mst));
	MinStackPop(&mst);
	
	MinStackDestory(&mst);

}
void TestIsLegalStackOrder()
{
	int in[5] = { 1, 2, 3, 4, 5 };
	int out[5] = { 4, 5, 3, 2, 1 };
	printf("%d\n",IsLegalStackOrder(in,5,out,5));
}
void TestShareStack()
{

		ShareStack pss;
		ShareStackInit(&pss);
		ShareStackPush(&pss, 0, 1);
		ShareStackPush(&pss, 2, 1);
		ShareStackPush(&pss, 4, 1);
		ShareStackPush(&pss, 6, 1);
		ShareStackPush(&pss, 8, 1);
		ShareStackPush(&pss, 1, 2);
		ShareStackPush(&pss, 3, 2);
		ShareStackPush(&pss, 5, 2);
		ShareStackPush(&pss, 7, 2);
		printf("%d", ShareStackTop(&pss, 1));
		printf("%d", ShareStackTop(&pss, 2));

}
int main()
{
	//TestQueueByTwoStack();
	//TestStackByTwoQueue();
	//TestMinStack();
	//TestIsLegalStackOrder();
	void TestShareStack();
	system("pause");
	return;
}