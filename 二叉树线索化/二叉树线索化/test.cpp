#include <iostream>
using namespace  std;
#include <assert.h>

enum PointFlag{LINK, THREAD };

template <typename T>
struct BinaryTreeNodeThd
{
	BinaryTreeNodeThd(const T& data = T())
		:_PLeft(NULL)
		, _PRight(NULL)
		, _Parent(NULL)
		, _LeftThread(LINK)
		, _RightThread(LINK)
		,_data(data)
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
		_createTree(_pRoot, arr, sz, invalied, index);
	}

	void PreThreading()
	{
		if (_pRoot)
		{
			Node *prev;
			_preThreading(_pRoot);
		}
	}
private:
	void _createTree(Node* &proot, const T arr[], size_t sz, const T& invalied, size_t &index )
	{
		if (index >= sz  || arr[index] == invalied)
			return;
		proot = new Node(arr[index]);
		if (proot->_PLeft)
		{
			proot->_PLeft->_Parent = proot;
		}
		if (proot->_PRight)
		{
			proot->_PRight->_Parent = proot;
		}
		_createTree(proot->_PLeft, arr, sz, invalied, ++index );
		_createTree(proot->_PRight, arr, sz, invalied, ++index );
	}

	void _preThreading(Node* proot, Node* &prev)
	{
		if (NULL == proot)
			return;
		if (proot->_PLeft == NULL)
		{
			proot->_LeftThread == THREAD;
			proot->_PLeft == prev;
		}

		if (prev && prev->_PRight == NULL)
		{
			prev->_RightThread == THREAD;
			prev->_PRight == proot;
		}
		prev = proot;
		_preThreading(proot->_PLeft, prev);
		_preThreading(proot->_PRight, prev);
	}
private:
	Node*  _pRoot;
};

int main()
{
	char str[] = { '0','1','3', '#', '#', '4', '#', '#', '2','5' };
	size_t size = sizeof(str) / sizeof(str[0]);
	BinaryTreeThd< char> tree(str, size, '#');
	system("pause");
	return 0;
}