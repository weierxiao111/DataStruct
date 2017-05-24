#ifndef   __LINKLIST_H_
#define   __LINKLIST_H_
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define  DataType  int

typedef  struct  Node
{
	DataType  data ;
	struct  Node* _PNext;
}Node,  *PNode;

// 初始化单链表
void InitList(PNode* pHead);

// 在单链表的尾部插入一个节点
void PushBack(PNode* pHead, DataType data);
// 打印单链表
void PrintList(PNode pHead);
// 获得节点
Node* BuyNode(DataType data);

#endif   //  __LINKLIST_H_