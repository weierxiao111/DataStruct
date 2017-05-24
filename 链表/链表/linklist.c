#include  "linklist.h"


Node* BuyNode(DataType data)
{
	PNode PNewNode = (Node*) malloc (sizeof(Node));
	if (PNewNode != NULL)
	{
		PNewNode->_PNext = NULL;
		PNewNode->data = data ;
        return PNewNode ;
	}

	return ;
 
}

// 初始化单链表
void InitList(PNode* pHead)
{
	  assert (pHead);

	 (*pHead) = (PNode) malloc (sizeof(Node));
      if (NULL == pHead)
	  {
		  return ;
	  }

	  else 
	  {
		  (*pHead) ->_PNext = NULL;
	  }
}

// 在单链表的尾部插入一个节点
void PushBack(PNode* pHead, DataType data)
{
	PNode pTail ; 
	assert (pHead);
	pTail = (*pHead) ;

	while ( pTail->_PNext != NULL )
	{
		pTail = pTail->_PNext;
	}

	pTail = BuyNode(data);

}
//打印链表
void PrintList(PNode  pHead)
{
	if (NULL == pHead)
	{
		return ;
	}
	while ( pHead )
	{
		printf ("%d", pHead->data);
		pHead = pHead->_PNext;
	}

	printf("\n");
}