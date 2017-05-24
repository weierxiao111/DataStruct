#include <iostream>
using namespace std;
#include <assert.h>

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
		
		return _Insert(_pRoot, key, value);
	}

	void InOrder()
	{
		cout << "ÖÐÐò£º";
		_InOrder(_pRoot);
		cout << "end" << endl;
	}
private:
	bool _Insert(Node* proot, const K& key, const V& value)
	{
		if (proot->_pLeft == NULL && key<proot->_key)
		{
			proot->_pLeft = new Node(key, value);
			proot->_pLeft->_parent = proot;
			-- proot->_bf;
			_Rotate(proot);
			return true;
		}
		if (proot->_pRight == NULL && key > proot->_key)
		{
			proot->_pRight = new Node(key, value);
			proot->_pRight->_parent = proot;
			++proot->_bf;
			_Rotate(proot);
			return true;
		}

		if (key == proot->_key)
			return false;

		if (key < proot->_key)
			return _Insert(proot->_pLeft, key, value);
		if (key > proot->_key)
			return _Insert(proot->_pRight, key, value);
	}

	void _Rotate(Node *proot)
	{
		assert(proot);
		if (0 == proot->_bf)
			return;
		while ((proot->_bf != 2) && (proot->_bf != -2))
		{
			if (proot == _pRoot)
				return;
			proot = proot->_parent;

			if (proot->_bf == 1)
				++proot->_bf;
			if (proot->_bf == -1)
				--proot->_bf;
		}

		if (proot->_bf == 2)
		{
			if (proot->_pRight->_bf == 1)
				return _RotateL(proot);
			else
				return _RotateRL(proot);
		}
		else if (proot->_bf == -2)
		{
			if (proot->_pLeft->_bf == -1)
				return _RotateR(proot);
			else
				return _RotateLR(proot);
		}
		
	}

	void  _RotateL(Node* parent){
		Node *SubL = parent->_pRight;
		Node* LeftNode = SubL->_pLeft;
		Node *pParent = parent->_parent;

		SubL->_pLeft = parent;
	
		parent->_pRight = LeftNode;
		if (LeftNode != NULL)
		LeftNode->_parent = parent;
	
		  
		if (NULL == pParent)
			_pRoot = SubL;
		else if (pParent->_pLeft == parent)
		{
			pParent->_pLeft = SubL;
			SubL->_parent = pParent;
		}
		else
		{
			pParent->_pRight = SubL;
			SubL->_parent = pParent;
		}

		parent->_parent = SubL;
		SubL->_bf = 0;
		parent->_bf = 0;
	}

	void  _RotateR(Node* parent) {
		Node *SubR = parent->_pLeft;
		Node* RightNode = SubR->_pRight;
		Node *pParent = parent->_parent;

		SubR->_pRight = parent;
		if (NULL != RightNode)
		{
			parent->_pLeft = RightNode;
			RightNode->_parent = parent;
		}

		if (NULL == pParent)
			_pRoot = SubR;
		else if (pParent->_pLeft == parent)
		{
			pParent->_pLeft = SubR;
			SubR->_parent = pParent;
		}
		else
		{
			pParent->_pRight = SubR;
			SubR->_parent = pParent;
		}

		parent->_parent = SubR;
		SubR->_bf = 0;
		parent->_bf = 0;
	}

	void _RotateRL(Node *proot)
	{
		_RotateR(proot->_pRight);
		_RotateL(proot->_pLeft);
		proot->_bf = -1;
	}

	void _RotateLR(Node *proot)
	{
		_RotateL(proot->_pLeft);
		_RotateR(proot->_pRight);
		proot->_bf = 1;
	}

	void _InOrder(Node *proot)
	{
		if (NULL == proot)
			return;
		_InOrder(proot->_pLeft);
		cout << proot->_value << " ";
		_InOrder(proot->_pRight);
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
	}
	avtree.InOrder();
	system("puase");
	return 0;
}