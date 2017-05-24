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

// ��ʼ��������
void InitList(PNode* pHead);

// �ڵ������β������һ���ڵ�
void PushBack(PNode* pHead, DataType data);
// ��ӡ������
void PrintList(PNode pHead);
// ��ýڵ�
Node* BuyNode(DataType data);

#endif   //  __LINKLIST_H_