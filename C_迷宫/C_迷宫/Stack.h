
#pragma once


#include <malloc.h>
#include <assert.h>
#include<stdio.h>
#include <stdlib.h>
typedef struct Pos
{
	int _row;
	int _col;
}Pos;

typedef Pos STDataType;
#define DEFAULT_SZ 5

typedef struct Node
{
	STDataType * data;
	struct Node* next;

}NODE, *PNODE;
typedef struct Stack
{
	STDataType * data;
	PNODE _top;		// 栈顶
	PNODE _end;    //栈底
	int _capacity;  // //栈的总大小 
	int _size;//当前栈的大小

}Stack;

void StackInit(Stack* ps);
void StackDestroy(Stack* ps);

void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);
void StackPrint(Stack *ps);

void TestStack();