#include"sort.h"
//插入排序-直接排序
void InsertSort(int *a, int n)
{
	assert(a != NULL);
	int i = 0;
	for (; i < n - 1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0 && a[end]>tmp)
		{
			a[end + 1] = a[end];
			--end;
		}
		a[end + 1] = tmp;
		void Printa(int * a, int n);
	}
}
int ShellSort(int *a, int n)
{
	assert(a != NULL);
	int gap = n;
	int i = 0;
	if (gap > 1)
	{
		gap = gap / 3 + 1;
	}
	for (; i < gap; ++i)
	{
		int end = i;
		int tmp = a[end + gap];
		while (end >= 0 && a[end]>tmp)
		{
			a[end + gap] = a[end];
			end -= gap;
		}
		a[end + gap] = tmp;
	}
}
void PrintArray(int * a, int n)
{
	assert(a != NULL);
	int i = 0;
	for (i = 0; i < n - 1; ++i)
	{
		printf("%d", a[i]);
	}
	printf("/n");
}
//二分插入排序
void InsertSort_OP(int *a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		//在已序序列中查找待插入元素的位置
		int left = 0;
		int right = i;
		int key = a[i];
		while (left <= right)
		{
			int mid = left + ((right - left) >> 1);
			if (key < a[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		//搬移元素
		int end = i - 1;
		while (end >= left)
		{
			a[end + 1] = a[end];
			end--;
		}

		//插入元素
		a[left] = key;
	}
}
void Swap(int *x1, int *x2)
{
	int tmp = *x1;
	*x1 = *x2;
	*x2 = tmp;
}
//选择排序
void SelectSort(int *a, int n)
{
	assert(a != NULL);
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int minindex = begin, maxindex = begin;
		int i = 0;
		for (i = begin; i <= end; ++i)
		{
			if (a[i]>a[maxindex])
				maxindex = i;
			if (a[i] < a[minindex])
				minindex = i;
		}
		Swap(&a[begin], &a[minindex]);
		if (begin == maxindex)
			maxindex = minindex;
		Swap(&a[end], &a[maxindex]);
		++begin;
		--end;
	}
}
void AdjustDown(int *a, int n, int root)
{
	int parent = root;
	int child = root * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n&&a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child]>a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
	}
}
//堆排序
void HeapSort(int *a, int n)
{
	assert(a != NULL);
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}
//冒泡排序
void BubbleSort(int *a, int n)
{
	assert(a != NULL);
	int end = n;
	while (end > 0)
	{
		for (int i = 1; i > end; ++i)
		{
				if (a[i - 1]>a[i])
				{
					Swap(a[i - 1], a[i]);
					//flag = true;
				}
		}
		--end;
	}
}
//快速排序
//左右指针法
int PartSort01(int *a,int begin, int end)
{
	//int begin = 0, end = n - 1;
	int key = a[end];
	int keyindex = end;
	
	while (begin < end)
	{
		while (begin < end&&a[begin] <= key)//找大
			begin++;
		while (begin < end&&a[begin] >= key)//找小
			end--;
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyindex]);
	return begin; 
}
//挖坑法
int PartSort02(int *a, int begin, int end)
{
	assert(a != NULL);
	int key = a[end];
	while (begin < end)
	{
		while (begin < end&&a[begin] <= key)//找大
		{
			begin++;
			a[end] = a[begin];
		} 		
		while (begin < end&&a[begin] >= key)//找小
		{
			end--;
			a[begin] = a[end];
		}		
	}
	a[begin] = key;
	return begin; 
}
//前后指针法
int PartSort03(int * a, int begin, int end)
{
	int prev = begin - 1;
	int cur = begin;
	int key = a[end];
	while (cur < end)
	{
		if (a[cur] < key&&++prev != cur)//找小
			Swap(&a[cur], &a[prev]);
			++cur;		
	}
	Swap(&a[++prev], &a[end]);
	return prev;
}
//三数取中法
int GetmidIndex(int *a, int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
			return mid;
		else if (a[begin] < a[end])
			return a[end];
		else
			return a[begin];
	}
	else
	{
		if (a[end] < a[mid])
			return mid;
		else if (a[begin < a[end]])
			return begin;
		else
			return end;
	}
}
int QuickSort_OP(int *a, int begin, int end)//递归
{
	if (begin < end)
	{
		int div = PartSort03(a, begin, end);
		QuickSort(a, begin, div-1);
		QuickSort(a, div+1, end);
	}
}
int QuickSort(int *a, int left, int right)
{
	Stack st;
	StackInit();
	StackPush(&st, left);
	StackPush(&st, right);
	while (!StackEmpty())
	{
		int end = StackTop(&st);
		StackPop(&st);
		int begin = StackTop(&st);
		StackPop(&st);
		int div = PartSort01(a, begin, end);
		if (begin < div - 1)
		{
			StackPush(&st, begin);
			StackPush(&st, div - 1);
		}
		if (end > div + 1)
		{
			StackPush(&st, div + 1);
			StackPush(&st, end);
		}
		
	}
}
//归并排序
void MergeSort(int *a, int n)
{
	assert(a != NULL);
	int *tmp = (int *)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
void _MergeSort(int *a, int begin, int end, int *tmp)
{
	int mid = begin + ((end - begin) >> 1);
	_MergeSort(a, begin, mid , tmp);
	_MergeSort(a, mid + 1, end, tmp);
	Merge(a, begin, mid, mid + 1, end, tmp);
}
void Merge(int *a, int begin1, int begin2, int end1, int end2, int *tmp)
{
	int index = begin1;
	int n = end2 - begin1;
	int start = begin1;
	while (begin1 < end1&&begin2 < end2) //从头开始比较大小，小的放在新空间中，继续往后走
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	while (begin1 < end1)//将a[begin1]-a[end1]的元素放入新空间中
		tmp[index++] = a[begin1++];
	while (begin2 < end2)
		tmp[index++]=a[begin2++];
	memcpy(a + start, start, sizeof(int)*(n + 1));
}
//计数排序
void CountSort(int *a, int n)
{
	assert(a != NULL);
	int max = a[0], min = a[0];
	int i = 0;
	for (; i < n; ++i)
	{
		if (a[i]>max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int range = max - min + 1;
	int *counts = (int*)malloc(range*sizeof(int));
	memset(counts, 0, sizeof(int)*range);
	for (i = 0; i < n;++i)
	{
		//1 2 1 4 1 1 9
		counts[a[i] - min]++; //counts[]++为统计原数组中数字出现的次数
	}
	int index = 0;
	for (i = 0; i < range; ++i)
	{
		while (counts[i]--)
		{
			a[index++] = i + min;
		}
	}
}