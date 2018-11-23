#include"Stack.h"
void TestStack()
{
	Stack ps;
	StackPush(&ps, 1);
	StackPush(&ps, 2);
	StackPush(&ps, 3);
	StackPush(&ps, 4);
	StackPrint(&ps);
	StackPop(&ps);
	StackPrint(&ps);
	int top = StackTop(&ps);
	printf("%d\n", top);
	int n = StackSize(&ps);
	printf("%d\n", n);
}
int main()
{
	TestStack();
	system("pause");
	return 0;
}