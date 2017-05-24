#include <iostream>
#include <vector>
#include <assert.h>
#include "heap111.hpp"
using namespace std;


template <class T>
struct Node{
	Node(const T& weight, const T& data = T())
		:_weight(weight)
		, _pLeft(NULL)
		, _pRight(NULL)
	{}

	Node*  _pLeft;
	Node*  _pRight;
	T   _weight;
	T   _data;
};

template <class T>
class HuffmanTree {
	typedef Node<T> Node;
public:
	HuffmanTree()
		:_pRoot(NULL)
	{}

	HuffmanTree(const T arr[], size_t size)
		:_pRoot(NULL)
	{
		_CreateTree(arr, size);
	}
protected:
	void _CreateTree(const T arr[],  size_t size)
	{
		assert(arr);
		Heap<T> q;
		for (int i = 0; i < size; ++i)
		{
			q.Insert(arr[i]);
		}

		Node *NewTree = NULL;
		Node *OldTree = NULL;
		Node *RightTree = NULL;
		if (!q.Empty())
		{
			OldTree = new Node(q.Top());
			q.Remove();
		}
		while (!q.Empty())
		{
			RightTree = new Node(q.Top());
			q.Remove();
			NewTree = new Node(OldTree->_weight + RightTree->_weight);
			NewTree->_pLeft = OldTree;
			NewTree->_pRight = RightTree;
			OldTree = NewTree;
		}

		_pRoot = OldTree;

	}
protected:
	Node*  _pRoot;
};

int main()
{
	int arr[] = {4,6,8,2,4,10,32,11 };
	HuffmanTree<int>  huftree(arr, 8);
	return 0;
}

