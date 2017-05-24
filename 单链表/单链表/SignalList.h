#ifndef __LIST__H_
#define __LIST__H_


typedef int  DataType;
typedef unsigned int size_t;

typedef struct Node
{
	DataType _data;
    struct Node *_pNext;
}Node, *PNode;

void InitList(PNode* pHead);
void PushBack(PNode* pHead, DataType data);
Node* BuyNode(DataType data);
void PopBack(PNode* pHead);
void PushFront(PNode* pHead, DataType data);
void PopFront(PNode* pHead);
Node* Find(PNode pHead, DataType data);
void Insert(PNode pos, DataType data);
void Erase(PNode* pHead, PNode pos);
void Remove(PNode* pHead, DataType data);
void RemoveAll(PNode* pHead, DataType data);
size_t Size(PNode pHead);
int Empty(PNode pHead);
PNode Back(PNode pHead);
void PrintList(PNode pHead);
void PrintFromTail2Head(PNode pHead);
void InsertnoHead(PNode* pos, DataType data);
void CreateCircle(PNode* pHead);
void resverLsit(PNode* pHead);
void BluesortList(PNode* pHead);
//void QuicksortList(PNode* pHead, PNode pTail);
void JosephCircle(PNode* pHead, size_t M);
PNode FindBackKNode(PNode pHead, size_t K);
int isCircle(PNode pHead);
int HaveFocus(PNode L1, PNode L2);
PNode FocusCircle(PNode L1, PNode L2);
PNode CombineList(PNode L1, PNode L2); 


#endif