#include <iostream>
using namespace  std;
#include <assert.h>

enum PointFlag { LINK, THREAD };

template <typename T>
struct BinaryTreeNodeThd
{
	BinaryTreeNodeThd(const T& data = T())
		:_PLeft(NULL)
		, _PRight(NULL)
		, _Parent(NULL)
		, _LeftThread(LINK)
		, _RightThread(LINK)
		, _data(data)
	{}

	BinaryTreeNodeThd *_PLeft;
	BinaryTreeNodeThd *_PRight;
	BinaryTreeNodeThd *_Parent;
	PointFlag _LeftThread;
	PointFlag _RightThread;
	T _data;
};

template <typename T>
class BinaryTreeThd {
	typedef BinaryTreeNodeThd<T> Node;
public:
	BinaryTreeThd()
		:_pRoot(NULL)
	{}

	BinaryTreeThd(const T arr[], size_t sz, const T& invalied)
	{
		assert(arr);
		size_t index = 0;
		Node* prev = NULL;
		_createTree(_pRoot, arr, sz, invalied, index, prev);
	}

	void PreThreading()
	{
		if (_pRoot)
		{
			Node *prev = NULL;
			_preThreading(_pRoot,prev);
		}
	}

	void InderThreading()
	{
		if (_pRoot)
		{
			Node *prev = NULL;
			_InderThreading(_pRoot, prev);
		}
	}

	void PostThreading()
	{
		if (_pRoot)
		{
			Node *prev = NULL;
			_PostThreading(_pRoot, prev);
		}
	}

	void PreOrder()
	{
		if (_pRoot)
		{
			cout << "Ç°Ðò : ";
			_PreOrder(_pRoot);
			cout << "end" << endl;
		}
	}

	void InderOrder()
	{
		if (_pRoot)
		{
			cout << "ÖÐÐò£º ";
			_InderOrder(_pRoot);
			cout << "end" << endl;
		}
	}
private:
	void _createTree(Node* &proot, const T arr[], size_t sz, const T& invalied, size_t &index, Node* prev)
	{
		if (index >= sz || arr[index] == invalied)
			return;
		proot = new Node(arr[index]);
		proot->_Parent = prev;
		_createTree(proot->_PLeft, arr, sz, invalied, ++index, proot);
		_createTree(proot->_PRight, arr, sz, invalied, ++index, proot);
	}

	void _preThreading(Node* proot, Node* &prev)
	{
		if (NULL == proot)
			return;
		if (proot->_PLeft == NULL)
		{
			proot->_LeftThread = THREAD;
			proot->_PLeft = prev;
		}

		if (prev && prev->_PRight == NULL)
		{
			prev->_RightThread = THREAD;
			prev->_PRight = proot;
		}
		prev = proot;
		if (proot->_LeftThread == LINK)
		_preThreading(proot->_PLeft, prev);
		if (proot->_RightThread == LINK)
		_preThreading(proot->_PRight, prev);
	}

	void _InderThreading(Node* proot, Node* &prev)
	{
		if (NULL == proot)
			return;

		if (proot->_LeftThread == LINK)
		_InderThreading(proot->_PLeft, prev);

		if (proot->_PLeft == NULL || proot->_LeftThread == THREAD)
		{
			proot->_LeftThread = THREAD;
			proot->_PLeft = prev;
		}

		if (prev && (prev->_PRight == NULL || prev->_RightThread == THREAD))
		{
			prev->_RightThread = THREAD;
			prev->_PRight = proot;
		}
		prev = proot;
		if (proot->_RightThread == LINK)
		_InderThreading(proot->_PRight, prev);
	}

	void _PostThreading(Node* proot, Node* &prev)
	{
		if (NULL == proot)
			return;

		if (proot->_LeftThread == LINK)
			_PostThreading(proot->_PLeft, prev);

		
		if (proot->_RightThread == LINK)
			_PostThreading(proot->_PRight, prev);

		if (proot->_PLeft == NULL || proot->_LeftThread == THREAD)
		{
			proot->_LeftThread = THREAD;
			proot->_PLeft = prev;
		}

		if (prev && (prev->_PRight == NULL || prev->_RightThread == THREAD))
		{
			prev->_RightThread = THREAD;
			prev->_PRight = proot;
		}

		prev = proot;
	}

	void _PreOrder( Node* proot)
	{
		while (proot)
		{
            while (proot->_LeftThread == LINK)
			{
				cout << proot->_data << "->";
				proot = proot->_PLeft;
			}
			cout << proot->_data << "->";

			proot = proot->_PRight;
		}
	}

	void _InderOrder(Node *proot)
	{
		while (proot)
		{
			while (proot->_LeftThread == LINK)
				proot = proot->_PLeft;
			cout << proot->_data << "->";
			if (proot->_RightThread == LINK)
				proot = proot->_PRight;
			else
			{
				while (proot->_RightThread == THREAD)
				{
					proot = proot->_PRight;
					cout << proot->_data << "->";
				}
				proot = proot->_PRight;
			}
		}
	}
private:
	Node*  _pRoot;
};

int main()
{
	char str[] = { '1','2', '#','3', '#','#' ,'4', '5','#','6','#' ,'7','#','#','8' };
	size_t size = sizeof(str) / sizeof(str[0]);
	BinaryTreeThd< char> tree(str, size, '#');
	tree.InderThreading();
	tree.InderOrder();
    system("pause");
	return 0;
}