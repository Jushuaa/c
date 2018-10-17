#include"heap.h"
void TestHeap()
{
	int ret = 0;
	int size = 0;
	int n = 0;
	int arr[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	Heap hp;
	HeapInit(&hp, arr, sizeof(arr) / sizeof(HPDataType));
	HeapPrint(&hp);
	HeapPush(&hp, 6);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	ret = HeapTop(&hp);
	printf("%d\n", ret);
	size = HeapSize(&hp);
	printf("%d\n", size);
	n = HeapEmpty(&hp);
	if (n == 0)
	{
		printf("¶ÑÎª¿Õ\n");
	}
	else
	{
		printf("¶Ñ²»Îª¿Õ\n");
	}
	
	

}
int main()
{
	TestHeap();
	system("pause");
	return 0;
}