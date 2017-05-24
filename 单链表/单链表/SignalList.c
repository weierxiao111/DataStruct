#include "SignalList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

Node* BuyNode(DataType data)   //��ȡһ���½ڵ�
{
	PNode PTemp = (PNode)malloc(sizeof(Node));
	if (NULL != PTemp)
	{
		PTemp ->_data = data;
		PTemp ->_pNext = NULL;
		return PTemp;
	}
	printf("out of merroy!\n");
	return NULL;
}

void InitList(PNode* pHead)  //��ʼ������
{
	assert(pHead);
	(*pHead) = NULL; 
}

void PushBack(PNode* pHead, DataType data)  //ͷɾ
{
	PNode pTail = NULL;
	assert(pHead);
	if ((*pHead) == NULL)
		(*pHead) = BuyNode(data);
	else
	{
		pTail = (*pHead);
		while (pTail ->_pNext)
		{
			pTail = pTail ->_pNext;
		}
		pTail ->_pNext = BuyNode(data);
	}
}

void PopBack(PNode* pHead)  //βɾ
{
	PNode pTail = NULL;
	assert(pHead);
	if  (NULL == (*pHead))
	{
		return;
	}
	else if (NULL == (*pHead)->_pNext)
	{
		free(*pHead);
		(*pHead) = NULL;
	}
	else
	{
		PNode pPre = NULL;
		pTail = (*pHead);
		while (pTail ->_pNext ->_pNext)
		{
			pTail = pTail ->_pNext;
		}
		free(pTail ->_pNext);
		pTail ->_pNext = NULL;
	}
}

void PushFront(PNode* pHead, DataType data)  //ͷ��
{
	assert(pHead);
	if (NULL == (*pHead))
	{
		(*pHead) = BuyNode(data);
	}
	else
	{
		PNode pTemp = BuyNode(data);
		pTemp ->_pNext = (*pHead);
		(*pHead) = pTemp;
	}
}

void PopFront(PNode* pHead)  //βɾ
{
	assert(pHead);
	if (NULL == (*pHead))
	{
		return;
	}
	else if (NULL == (*pHead) ->_pNext)
	{
		free(*pHead);
		(*pHead) = NULL;
	}
	else 
	{
		PNode pTemp = (*pHead);
		(*pHead) = (*pHead) ->_pNext;
		free(pTemp);
		pTemp = NULL;
	}

}

Node* Find(PNode pHead, DataType data)   //����ֵΪdata�ĵ�һ���ڵ�
{
	PNode pTemp = NULL;
	pTemp = pHead;
	while (pTemp)
	{
		if (pTemp ->_data == data)
			return pTemp;
		pTemp = pTemp ->_pNext;
	}
	return NULL;
}

void Insert(PNode pos, DataType data)  //posλ�����ֵΪdata�Ľڵ�
{
	PNode pTemp = NULL;
	if (NULL == pos)
		return ;
	pTemp = BuyNode(data);
	pTemp ->_pNext = pos->_pNext;
	pos ->_pNext = pTemp;
}

void Erase(PNode* pHead, PNode pos)   //�Ƴ�posλ�õĽڵ�
{
	assert(pHead);
	if (NULL == pos)
		return;
	if ((*pHead) == pos)
	{
		PopFront(pHead);
	}
	else if (NULL == (pos->_pNext))
	{
		PopBack(pHead);
	}
 	else  //���ﲢʹ��û�б������Ѻ�һ���ڵ��ֵ����pos����posָ��pos->_pNext->_pNext
	{
		pos->_data = pos->_pNext->_data;
		pos->_pNext = pos->_pNext->_pNext;
	}
}

void Remove(PNode* pHead, DataType data) //�Ƴ��������е�һ��ֵΪdata�Ľڵ�
{
	PNode pTemp = NULL;
	assert(pHead);
	pTemp = Find(*pHead, data);
	Erase(pHead, pTemp);
}

void RemoveAll(PNode* pHead, DataType data)  //ɾ������ֵΪdata�Ľڵ�
{
	PNode pTemp = NULL;
	assert(pHead);
    while (pTemp = Find(*pHead, data))
		Erase(pHead, pTemp);	
}

size_t Size(PNode pHead) //������ڵ����
{
	size_t size = 0;
	PNode pTemp = pHead;
	while (pTemp)
	{
		size++;
		pTemp = pTemp ->_pNext;
	}
	return size;
}

int Empty(PNode pHead) //�п�
{
	return (NULL == pHead);
}

PNode Back(PNode pHead)  //����β�ڵ�
{
	PNode pTail = pHead;
	if (Empty(pHead))
		return NULL;
	while (pTail ->_pNext)
	{
		pTail = pTail ->_pNext;
	}
	return pTail;
}

PNode Front(PNode pHead)  //����ͷ�ڵ�
{
	return pHead;
}

void PrintList(PNode pHead)  //˳���ӡ������
{
	PNode pTemp = pHead;
	while (pTemp)
	{
		printf("%d->",pTemp->_data);
		pTemp = pTemp->_pNext;
	}
	printf("NULL\n");
	
}

void PrintFromTail2Head(PNode pHead)   //�����ӡ�������õݹ�ʵ�֣�
{
	PNode pTemp = pHead;
	if (NULL== pTemp)
	{
		printf("NULL");
		return ;
	}
	PrintFromTail2Head(pTemp->_pNext);
	printf("->%d",pTemp->_data);

}

void InsertnoHead(PNode* pos, DataType data)        //��һ����ͷ������ķ�ͷ�ڵ�ǰ����һ���ڵ�
{
	PNode pTemp = NULL;
	PNode pPre = NULL;
	assert(pos);
	if (NULL == (*pos))
		return ;
	pTemp = (*pos) ->_pNext;
	(*pos) ->_pNext = BuyNode((*pos)->_data);
	(*pos) ->_data = data;
	(*pos) = (*pos)->_pNext;
	(*pos) ->_pNext = pTemp;
}

void CreateCircle(PNode* pHead)           //���컷
{
	PNode pTail = NULL;
	assert(pHead);
	if (NULL ==(*pHead))
		return;
	pTail = (*pHead);
	while (pTail->_pNext)
	{
		pTail = pTail ->_pNext;
	}
	pTail ->_pNext = (*pHead);
}

void resverLsit(PNode* pHead)         //��ת������
{
	PNode pPre = NULL;
	PNode pTemp = NULL;
	PNode pLater = NULL;
	assert(pHead);
	pTemp = (*pHead);
	if (NULL == pTemp || pTemp->_pNext == NULL)
		return;
	pPre = pTemp;
	pTemp = pTemp->_pNext;
	pLater = pTemp ->_pNext;
	pTemp ->_pNext = pPre;
	pPre ->_pNext = NULL;
	while (pLater)
	{
		pPre = pTemp;
		pTemp = pLater;
		pLater = pTemp->_pNext;
		pTemp->_pNext = pPre;
	}
	(*pHead) = pTemp;
}

void BluesortList(PNode* pHead)     //������ð������
{
	int flag = 1;
	PNode pTemp = NULL;
	PNode pTail = NULL;
	assert(pHead);
	pTemp = (*pHead);
	if (NULL == pTemp || pTemp->_pNext == NULL)
		return ;
	while (flag && pTemp != pTail)
	{
		flag = 0;
		while (pTemp->_pNext)
		{
			if (pTemp->_data > pTemp->_pNext->_data)
			{
				DataType temp = pTemp->_data;
				pTemp->_data = pTemp->_pNext->_data;
				pTemp->_pNext->_data = temp;
				flag = 1;
			}
			pTemp = pTemp->_pNext;
		}
		pTail = pTemp;
		pTemp = (*pHead);
	}
}
/*
void QuicksortList(PNode* pHead��PNode* pTail)  //������Ŀ�������
{
	DataType temp;
	PNode pStart = NULL;
	PNode pEnd = NULL;
	assert(pEnd && pHead);
	pStart = (*pHead);
	if (NULL==pStart || NULL==pEnd || pStart==pEnd)
		return;

	temp = pStart->_data;
	pStart = pStart->_pNext;
	while (pStart != pEnd->_data)
	{
		if (pStart->_data < temp)
		{
			pStart->_data = pEnd ->_data;
			pEnd ->_data = temp;
			pStart = pStart->_pNext;
		}
	}
}
*/
void JosephCircle(PNode* pHead, size_t M)   //Լɪ������
{  
	int m = 0;
	PNode pTemp = NULL;
	PNode pDelNode = NULL;
	assert(pHead);
	pTemp = (*pHead);
	if (NULL == pTemp)
		return;
	while ( pTemp != pTemp->_pNext )
	{
		m = M;
		while (--m)
		{
			pTemp = pTemp ->_pNext;
		}
		pDelNode = pTemp->_pNext;
		pTemp->_data = pTemp->_pNext->_data;
		pTemp->_pNext = pTemp->_pNext->_pNext;
		free(pDelNode);
		pDelNode = NULL;
	}
	(*pHead) = pTemp;
	(*pHead) ->_pNext = NULL;

}

PNode FindBackKNode(PNode pHead, size_t K)  //����
{
	PNode pfast = NULL;
	PNode pslow = NULL;
	if (NULL == pHead || K == 0)
		return NULL;
	pfast = pHead;
	pslow = pHead;

	while (--K && (pfast=pfast->_pNext))
		;
	if (pfast == NULL)
		return NULL;
	while (pfast->_pNext)
	{
		pfast = pfast->_pNext;
		pslow = pslow->_pNext;
	}
	return pslow;
}

int isCircle(PNode pHead)  //�ж��Ƿ�Ϊ��
{
	PNode pTemp = NULL;
	if (NULL == pHead)
		return 0;
	pTemp = pHead->_pNext;

	while (pTemp)
	{
		if (pTemp == pHead)
			return 1;
		pTemp = pTemp->_pNext;
	}
	return 0;
}

int HaveFocus(PNode L1, PNode L2)  //�ж��������Ƿ��н��㣨��������
{
	PNode pEnd1 = NULL;
	PNode pEnd2 = NULL;
	if (NULL == L1 || NULL == L2)
		return 0;
	pEnd1 = L1;
	pEnd2 = L2;
	while ( pEnd1->_pNext)
		pEnd1 = pEnd1->_pNext;
	while ( pEnd2->_pNext)
		pEnd2 = pEnd2 ->_pNext;
	if (pEnd1 == pEnd2)
		return 1;
	return 0;
}

PNode FocusCircle(PNode L1, PNode L2)  //����������Ľ��㣨��������
{
	PNode pTemp1 = NULL;
	PNode pTemp2 = NULL;
	int size1 = 0;
	int size2 = 0;
	int K = 0;
	if (HaveFocus(L1, L2) == 0)
		return NULL;
	if (NULL == L1 || NULL == L2)
		return NULL;
	pTemp1 = L1;
	pTemp2 = L2;
	size1 = Size(L1);
	size2 = Size(L2);
	K= size1 - size2;

	if (K>0)
	{
		while (K--)
		{
			pTemp1 = pTemp1->_pNext;
		}
	}
	else 
	{
		K = size2 - size1;
		while (K--)
		{
			pTemp2 = pTemp2->_pNext;
		}
	}

	while (pTemp1 != pTemp2)
	{
		pTemp1 = pTemp1->_pNext;
		pTemp2 = pTemp2->_pNext;
	}

	return pTemp1;
}

PNode CombineList(PNode L1, PNode L2)  //�ϲ�����������������������
{
	PNode pTemp1 = NULL;
	PNode pTemp2 = NULL;
	PNode NewList = NULL;
	PNode NewTail = NULL;
	pTemp1 = L1;
	pTemp2 = L2;
	if (NULL == pTemp1)
		return L2;
	if (NULL == pTemp2)
		return L1;

	if (pTemp1->_data <= pTemp2->_data)
	{
		NewList = pTemp1;
		NewTail = NewList;
		pTemp1 = pTemp1->_pNext;
	}
	else
	{
		NewList = pTemp2;
		NewTail = NewList;
		pTemp1 = pTemp1->_pNext;
	}

	while (pTemp1 && pTemp2)
	{
		if (pTemp1->_data >= pTemp2->_data )
		{
			NewTail->_pNext = pTemp2;
			pTemp2 = pTemp2->_pNext;
			NewTail = NewTail->_pNext;
		}
		else
		{
			NewTail->_pNext = pTemp1;
			pTemp1 = pTemp1->_pNext;
			NewTail = NewTail->_pNext;
		}
	}

	if (NULL == pTemp1)
	{
		while(pTemp2)
		{
			NewTail->_pNext = pTemp2;
			pTemp2 = pTemp2->_pNext;
			NewTail = NewTail->_pNext;
		}
	}
	else 
	{
		while(pTemp1)
		{
			NewTail->_pNext = pTemp2;
			pTemp2 = pTemp2->_pNext;
			NewTail = NewTail->_pNext;
		}
	}
	return NewList;
}
