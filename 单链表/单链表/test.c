#include "SignalList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void FunTest1()
{
	int bol;
	size_t size;
	PNode pret;
	PNode pHead;
	PNode pTail;
	InitList(&pHead);
	PushFront(&pHead, 1);
    PushFront(&pHead, 2);
    PushFront(&pHead, 4);
    PushFront(&pHead, 4);
	PushFront(&pHead, 4);
    PushFront(&pHead, 4);
    PushFront(&pHead, 7);
	pret = Find(pHead, 1);
	size = Size(pHead);
	bol = Empty(pHead);
	pTail = Back(pHead);
	PrintList(pHead);
	PrintFromTail2Head(pHead);
}

FunTest2()
{
	PNode pret;
	PNode pHead;
	int ret = 0;
	InitList(&pHead);
	PushBack(&pHead, 1);
	PushBack(&pHead, 2);
	PushBack(&pHead, 3);
	PushBack(&pHead, 4);
	PushBack(&pHead, 5);
	PushBack(&pHead, 6);
	pret = Find(pHead,4);
	resverLsit(&pHead);
	BluesortList(&pHead);
	//CreateCircle(&pHead);
	ret = isCircle(pHead);
}

void FunTest3()
{
	PNode L1;
	PNode L2;
	PNode temp;
	PNode pret;
	int ret = 0;
	InitList(&L1);
	PushBack(&L1, 1);
	PushBack(&L1, 3);
	PushBack(&L1, 3);
	PushBack(&L1, 7);
	InitList(&L2);
	PushBack(&L2, 2);
	PushBack(&L2, 4);
	PushBack(&L2, 6);
	PushBack(&L2, 8);
	pret = CombineList(L1, L2);

}

int main()
{
	FunTest3();
	return 0;
}