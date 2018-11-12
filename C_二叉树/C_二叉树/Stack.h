#pragma once
#include <malloc.h>
#include <assert.h>
#include<stdio.h>
#include <stdlib.h>

#ifndef __STACK_H__
#define __STACK_H__

//#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>

#define START_SIZE 3
#define ADD_SIZE 2
typedef int STDataType;


typedef struct Stack
{
	STDataType* _a;
	int _top;		// Õ»¶¥
	int _capacity;  // ÈÝÁ¿ 
} Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, STDataType x);
//STDataType Stackprint(Stack *ps);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);
void TestStack();
#endif // !__STACK_H__