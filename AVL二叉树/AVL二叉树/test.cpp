#include <iostream>
using namespace std;
#include <assert.h>
#include <stdlib.h>

template <class K, class V>
struct AVLTreeNode
{
	AVLTreeNode(const K& key = K(), const V& value = V())
		:_key(key)
		, _value(value)
		, _pLeft(NULL)
		, _pRight(NULL)
		, _parent(NULL)
		, _bf(0)
	{}
	AVLTreeNode *_pLeft;
	AVLTreeNode *_pRight;
	AVLTreeNode *_parent;
	K _key;
	V _value;
	int _bf;

}; 

template <class K, class V>
class AVLTree {
	typedef AVLTreeNode<K, V>   Node;
public:
	AVLTree()
		:_pRoot(NULL)
	{}

	bool Insert(const K& key, const V& value)
	{
		if (NULL == _pRoot)
		{
			_pRoot = new Node(key, value);
			return true;
		}
		Node *pCur = _pRoot;
		Node *parent = NULL;
		while (pCur)
		{
			if (key < pCur->_key)
			{
				parent = pCur;
				pCur = pCur->_pLeft;
			}
			else if (key > pCur->_key)
			{
				parent = pCur;
				pCur = pCur->_pRight;
			}
			else
				return false;
		}

		pCur = new Node(key, value);
		if (key < parent->_key)
		{
			parent->_pLeft = pCur;
			--parent->_bf;
		}
		else
		{
			parent->_pRight = pCur;
			++parent->_bf;
		}
		pCur->_parent = parent;

		while (parent && parent->_bf != 0)
		{
			if (parent->_bf == 2)
			{
				if (pCur->_bf == 1)
					_RotateL(parent);
				else
					_RotateRL(parent);
				return true;
			}
			else if (parent->_bf == -2)
			{
				if (pCur->_bf == -1)
					_RotateR(parent);
				else
					_RotateLR(parent);
				return true;
			}

			if (parent->_bf == 1)
			{
				pCur = parent;
				parent = parent->_parent;
				if (parent)
					++parent->_bf;
				else
					return true;
			}
			else if (parent->_bf == -1)
			{
				pCur = parent;
				parent = parent->_parent;
				if (parent)
					--parent->_bf;
				else
					return true;
			}
		}
	}

	bool IsBalance()
	{
		return IsBalanceTree(_pRoot);
	}

 void InOrder()
	{
		cout << "中序：";
		_InOrder(_pRoot);
		cout << "end" << endl;
	}
private:	
	void  _RotateL(Node* parent)
	{
		Node *SubR = parent->_pRight;
		Node *SubRL = SubR->_pLeft;
		
		parent->_pRight = SubRL;
		if (SubRL != NULL)
		SubRL->_parent = parent;

		Node *pPParent = parent->_parent;

		parent->_parent = SubR;
		SubR->_pLeft = parent;
		SubR->_parent = pPParent;

		if (NULL == pPParent)
			_pRoot = SubR;
		else if (pPParent->_pLeft == parent)
		{
			pPParent->_pLeft = SubR;
		}
		else
		{
			pPParent->_pRight = SubR;
		}

		SubR->_bf = 0;
		parent->_bf = 0;
	}

	void  _RotateR(Node* parent)
	{
		Node *SubL = parent->_pLeft;
		Node *SubLR = SubL->_pRight;
		parent->_pLeft = SubLR;
		if (SubLR != NULL)
			SubLR->_parent = parent;

		Node *pPParent = parent->_parent;

		parent->_parent = SubL;
		SubL->_pRight = parent;
		SubL->_parent = pPParent;

		if (NULL == pPParent)
			_pRoot = SubL;
		else if (pPParent->_pLeft == parent)
		{
			pPParent->_pLeft = SubL;
		}
		else
		{
			pPParent->_pRight = SubL;
		}

		SubL->_bf = 0;
		parent->_bf = 0;
	}

	void _RotateRL(Node *parent)
	{
		_RotateR(parent->_pRight);
		_RotateL(parent);
		parent->_pRight->_bf = -1;
	}

	void _RotateLR(Node *parent)
	{
		_RotateL(parent->_pLeft);
		_RotateR(parent);
		parent->_pLeft->_bf = 1;
	}

	void _InOrder(Node *proot)
	{
		if (NULL == proot)
			return;
		_InOrder(proot->_pLeft);
		cout << proot->_value << " ";
		_InOrder(proot->_pRight);
	}

	int Hight(Node *proot)
	{
		if (NULL == proot)
			return 0;
		if (proot->_pLeft == NULL && proot->_pRight == NULL)
			return 1;
		int LeftHight = Hight(proot->_pLeft);
		int RightHight = Hight(proot->_pRight);
		return 1 + ((LeftHight > RightHight) ? LeftHight : RightHight);
	}

	bool IsBalanceTree(Node *proot)
	{
		if (NULL == proot)
			return true;
		if (proot->_bf >= 2 || proot->_bf <= -2)
		{
			cout << proot->_key<<"平衡因子大于2！" << endl;
			return false;
		}
		if (Hight(proot->_pRight) - Hight(proot->_pLeft) != proot->_bf)
		{
			cout <<proot->_key<<"  平衡因子不正确!" << endl;
			return false;
		}
		if (IsBalanceTree(proot->_pLeft) && IsBalanceTree(proot->_pRight))
			return true;
	}
private:
	Node *_pRoot;
};
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	AVLTree<int, int> avtree;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		avtree.Insert(arr[i], arr[i]);
		avtree.IsBalance();
	}
	avtree.InOrder();
	getchar();
	return 0;
}