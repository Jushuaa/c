#pragma once
#include "Stack.h"
#include "Queue.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>
typedef char BTDataType;
//孩子兄弟表示法：表示出每一个结点的第一个孩子结点，也表示出孩子结点的兄弟结点
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

// a是一个前序遍历的数组
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
void BinaryTreeDestory(BTNode* root);
BTNode* BuyBTNode(BTDataType x);
int BinaryTreeSize(BTNode* root);  //结点的个数
int BinaryTreeLeafSize(BTNode* root);  //叶子结点的个数
int BinaryTreeLevelKSize(BTNode* root, int k); //第k层的结点数

// 遍历  递归&非递归
void BinaryTreePrevOrder(BTNode* root);  //前序
void BinaryTreeInOrder(BTNode* root);    //中序
void BinaryTreePostOrder(BTNode* root);  //后序
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);  //查找元素
int BinaryTreeHeight(BTNode* root);      //高度
void BinaryTreeLevelOrder(BTNode* root);
int BinaryTreeComplete(BTNode* root); //是否为完全二叉树
void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);

void TestBinaryTree();
