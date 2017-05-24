#include <iostream>
using namespace std;

enum COLOR{RED, BLACK};
template <class K, class V>
struct RBTreeNode {
	RBTreeNode(const K& key , const V& value, COLOR color = RED)
		:_key(key)
		, _value(value)
		, _color(color)
		, _pLeft(NULL)
		, _pRight(NULL)
		, _pparent(NULL)
	{}
	RBTreeNode *_pLeft;
	RBTreeNode *_pRight;
	RBTreeNode *_pparent;
	K _key;
	V _value;
	COLOR _color;
};

template <class K, class V>
class RBTree {
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()
		:_pRoot(NULL)
	{}

	bool Insert(const K& key, const V& value)
	{
		//如果根节点是null
		if (NULL == _pRoot)
		{
			_pRoot = new Node(key, value, BLACK);
			return true;
		}

		Node *pCur = _pRoot;
		Node *pParent = NULL;
		Node *pUncle = NULL;
		Node *pgFather = NULL;
		//找到插入位置
		while (pCur)
		{
			if (key < pCur->_key)
			{
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
			else if (key > pCur->_key)
			{
				pParent = pCur;
				pCur = pCur->_pRight;
			}
			else //有key值相同的节点,插入失败
				return false;
		}

		pCur = new Node(key, value);
		if (pParent->_key > key)
		{
			pParent->_pLeft = pCur;
		}
		else
		{
			pParent->_pRight = pCur;
		}
		pCur->_pparent = pParent;

		while (pParent && pParent->_color == RED)
		{
			pgFather = pParent->_pparent;

			if (pgFather->_pLeft == pParent)
			{
				pUncle = pgFather->_pRight;
			}
			else
				pUncle = pgFather->_pLeft;

			//如果插入节点的父节点是红色，unclue是红色
			if (pUncle && pUncle->_color == RED)
			{
				pParent->_color = BLACK;
				pUncle->_color = BLACK;
				if (pgFather == _pRoot)
					return true;
				else
				{
					pgFather->_color = RED;
					pCur = pgFather;
					pParent = pCur->_pparent;

				}
			}
			//如果father为红,uncle为黑或者不存在，gfather为黑
			else
			{
				if (pParent == pgFather->_pLeft)
				{
					if (pCur == pParent->_pLeft)
					{
						_RotateR(pgFather);
						pParent->_color = BLACK;
						pgFather->_color = RED;
						return true;
					}
					else
					{
						_RotateL(pParent);
						std::swap(pParent, pCur);
					}

				}
				else
				{
					if (pCur == pParent->_pRight)
					{
						_RotateL(pgFather);
						pParent->_color = BLACK;
						pgFather->_color = RED;
						return true;
					}
					else
					{
						_RotateR(pParent);
						std::swap(pParent, pCur);
					}
				}
			}
		}
			// 插入节点的父节点是黑色，直接插入
		if (pParent->_color == BLACK)
		{
				return true;
		}
	}

	void InOrder()
	{
		if (_pRoot)
		{
			cout << "中序： ";
			_InOrder(_pRoot);
			cout << endl;
		}
	}

	bool IsRBTree()
	{
		if (NULL == _pRoot)
		{
			cout << "树 为 空!" << endl;
			return false;
		}
		if (_pRoot->_color == RED)
		{
			cout << "根节点为红色" << endl;
			return  false;
		}
		size_t numBlack = 0;
		size_t curBlack = 0;
		Node *pCur = _pRoot;
		while (pCur)
		{
			if (pCur->_color == BLACK)
				numBlack++;
			pCur = pCur->_pLeft;
		}

		return _IsRBTree(_pRoot, numBlack, curBlack);
	}
private:
	void _RotateL(Node *parent)
	{
		if (NULL == parent)
			return;
		Node *SubR = parent->_pRight;
		Node *SubRL = SubR->_pLeft;

		parent->_pRight = SubRL;
		if (SubRL)
			SubRL->_pparent = parent;

		Node *pPParent = parent->_pparent;
		SubR->_pLeft = parent;
		parent->_pparent = SubR;
		
		SubR->_pparent = pPParent;
		if (NULL == pPParent)
			_pRoot = SubR;
		else
		{
			if (parent = pPParent->_pLeft)
				pPParent->_pLeft = SubR;
			else
				pPParent->_pRight = SubR;
		}
	}

	void _RotateR(Node *parent)
	{
		if (NULL == parent)
			return;

		Node *SubL = parent->_pLeft;
		Node *SubLR = SubL->_pRight;

		parent->_pLeft = SubLR;
		if (SubLR)
			SubLR->_pparent = parent;

		Node* pPParent = parent->_pparent;
		SubL->_pRight = parent;
		parent->_pparent = SubL;

		SubL->_pparent = pPParent;
		if (NULL == pPParent)
			_pRoot = SubL;
		else
		{
			if (parent == pPParent->_pLeft)
				pPParent->_pLeft = SubL;
			else
				pPParent->_pRight = SubL;
		}
	}

	void _InOrder(Node *proot)
	{
		if (NULL == proot)
			return;
		_InOrder(proot->_pLeft);
		cout << proot->_key << " ";
		_InOrder(proot->_pRight);
	}

	bool _IsRBTree(Node *proot, const size_t numBlack, size_t curNum)
	{
			if (NULL == proot)
				return (numBlack == curNum);
			if (proot->_color == RED)
			{
				if (proot->_pparent && proot->_pparent->_color == RED)
				{
					cout << proot->_key << "有两个连续的红色" << endl;
					return false;
				}
			}
			else
				curNum++;
			return (_IsRBTree(proot->_pLeft, numBlack, curNum) &&
				_IsRBTree(proot->_pRight, numBlack, curNum));		
	}

private:
	Node* _pRoot;
};

int main()
{
	int arr[] = {10, 85, 15, 70, 20, 60, 30, 50, 65,80, 90, 40,5, 55};
	RBTree<int, int> tree;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		tree.Insert(arr[i], arr[i]);
	}
	tree.InOrder();
	if (tree.IsRBTree())
		cout << "是红黑树" << endl;
	system("pause");
	return 0;
}