#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
void InsertSort(int *a, int n);

int ShellSort(int *a, int n);
void PrintArray(int * a, int n);
void InsertSort_OP(int *a, int n);
void SelectSort(int *a, int n);
void HeapSort(int *a, int n);
void BubbleSort(int *a, int n);
int PartSort01(int *a,int begin, int end);
int PartSort02(int *a, int begin, int end);
int PartSort03(int *a, int begin, int end);
int GetmidIndex(int *a, int begin, int end);
int QuickSort_OP(int *a, int begin, int end);//ตÝน้
int QuickSort(int *a, int begin, int end);
void MergeSort(int *a, int n);
void _MergeSort(int *a, int begin, int end, int *tmp);
void Merge(int *a, int begin1, int begin2, int end1, int end2, int *tmp);
void CountSort(int *a, int n);
