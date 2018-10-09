#ifndef __LINKLIST_H__ 
#define __LINKLIST_H__ 

#include <stdio.h>
#include<assert.h>
#include<stdlib.h>


typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node* next;
}Node, *pNode, List, *pList;
pNode BuyNode(DataType d);
void PushFront(pList* pplist, DataType d);//头部插入
pNode Find(pList plist, DataType d);//查找元素
void PrintLinkList(pList plist);
void PushBack(pList* pplist, DataType d);//尾插
void DestroyLinkList(pList* pplist);//销毁链表

void PrintTailToHead(pList plist);// 从尾到头打印单链表 

void DelNodeNotTail(pNode pos);//删除一个无头单链表的非尾节点 
void InsertNode(pNode pos,DataType d);//在无头单链表的一个节点前插入一个节点 
 
void JosephCycle(pList * pplist, int k);//单链表实现约瑟夫环
 
void ReverseList(pList* pplist);//逆置/反转单链表

void BubbleSort(pList plist);// 单链表排序（冒泡排序） 


pList Merge(pList plist1, pList plist2);//合并两个有序链表,合并后依然有序 

pList  Merge_R(pList plist1, pList plist2);//递归 

pNode FindMidNode(pList plist);// 查找单链表的中间节点，要求只能遍历一次链表 

pNode FindLastKNode(pList plist, int k);// 查找单链表的倒数第k个节点，要求只能遍历一次链表 

pNode CheckCycle(pList plist);// 判断单链表是否带环
int GetCircleLength(pNode meet);//若带环，求环的长度

pNode GetCycleEntryNode(pList plist, pNode meet);//求环的入口点   并计算每个算法的时间复杂度&空间复杂度。
int CheckCross(pList plist1, pList plist2);// 判断两个链表是否相交
pNode GetCrossNode(pList plist1, pList plist2);//若相交，求交点。（假设链表不带环） 

void UnionSet(pList plist1, pList plist2);//求两个有序单链表交集(差集)。

#endif //__LINKLIST_H__ 