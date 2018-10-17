#include"heap.h"
void swap(HPDataType * x1, HPDataType* x2)
{
	HPDataType * x = x1;
	x1 = x2;
	x2 = x;
}
void AdjustUp(HPDataType * _a, int n, int child)
{
	assert(_a);
	int parent = (child - 1) / 2;
	while (parent >= 0)
	{
		if (_a[parent] < _a[child])
		{
			swap(&_a[parent], &_a[child]);
			child = parent;
			parent = (child - 1) / 2;
			
		}
		else
		{
			break;
		}
	}
	printf("\n");
}

void AdjustDown(HPDataType *_a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (_a[child + 1]>_a[child])
		{
			++child;
		}
		if (_a[child] < _a[parent])
		{
			swap(&_a[child], &_a[parent]);
		}
		else
		{
			break;
		}
	}
}

void HeapInit(Heap* hp, HPDataType* _a, int n)
{
	int i;
	assert(hp != NULL&&_a != 0);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	hp->_size = n;
	hp->_capacity = n;
	for (i = 0; i < n; i++)
	{
		hp->_a[i] = _a[i];
	}
	for (i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}
void HeapDestory(Heap* hp)
{
	assert(hp != NULL);
	free(hp->_a);
	hp->_a = NULL;
	hp->_size = hp->_capacity = 0;
}
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp != NULL);
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_a = (HPDataType*)realloc(hp->_a,sizeof(HPDataType)*hp->_capacity);
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
}
void HeapPop(Heap* hp)
{
	assert(hp != NULL);
	swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_a, hp->_size,0);
}
HPDataType HeapTop(Heap* hp)
{
	assert(hp != NULL);
	return hp->_a[0];
}
int HeapSize(Heap* hp)
{
	assert(hp != NULL);
	return hp->_size;
}
int HeapEmpty(Heap* hp)
{
	assert(hp != NULL);
	return hp->_size = 0 ? 0 : 1;
}
void HeapPrint(Heap* hp)
{
	assert(hp != NULL);
	for (int i = 0; i < hp->_size; ++i)
	{
		printf("%d",hp->_a[i]);
	}
	printf("\n");
}

// 不要直接调Heap
void HeapSort(HPDataType* _a, int n)
{
	int i, end;
	for (i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(_a, n, i);
	}
	end = n - 1;
	while (end)
	{
		swap(&_a[0], &_a[end]);
		AdjustDown(_a, n, i);
		--end;
	}
}