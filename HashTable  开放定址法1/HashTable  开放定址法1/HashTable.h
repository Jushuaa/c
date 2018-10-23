#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>


typedef char* HTKeyType;
typedef int HTValueType;

enum State
{
	EMPTY = 0,
	EXIST = 1,
		DELETE = 2,
};

typedef struct HashData
{
	enum State		_state;
	HTKeyType	_key;
	HTValueType _value;
}HashData;

typedef struct HashTable
{
	HashData* _tables;
	int _len;   // 长度
	int _size;  // 有效数据个数
}HashTable;

void HTInit(HashTable* ht,int len);
void HTDestroy(HashTable* ht);

int HTInsert(HashTable* ht, HTKeyType key, HTValueType value);
void CheckCapacity(HashTable * ht);
int HTRemove(HashTable* ht, HTKeyType key);
HashData* HTFind(HashTable* ht, HTKeyType key);

int HTSize(HashTable* ht);
int HTEmpty(HashTable* ht);


