#pragma once
#ifndef __HUFFMAN_H_
#define __HUFFMAN_H_
#include <iostream>
#include <vector>
#include <assert.h>
#include "Heap.hpp"
using namespace std;


template <class T>
struct Node {
	Node(const T& weight, const T& data = T())
		:_weight(weight)
		, _pLeft(NULL)
		, _pRight(NULL)
		, _parent(NULL)
		, _data(data)
	{}

	Node*  _pLeft;
	Node*  _pRight;
	Node* _parent;
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
	{
		_CreateTree(arr, size);
	}

	Node *GetRoot()
	{
		return _pRoot;
	}
protected:
	void _CreateTree(const T arr[], size_t size)
	{
		struct CompareNode
		{
			bool operator()(Node* pLeft, Node* pRight)
			{
				return (pLeft->_weight < pRight->_weight);
			}
		};
		Heap<Node*, CompareNode> q;
		for (int i = 0; i < size; ++i)
		{
			q.Insert(new Node(arr[i], arr[i]));
		}

		while (q.Size() > 1)
		{
			Node *pLeft = q.Top();
			q.Remove();
			Node *pRight = q.Top();
			q.Remove();

			Node* parent = new Node(pLeft->_weight + pRight->_weight);
			parent->_pLeft = pLeft;
			parent->_pRight = pRight;
			pLeft->_parent = parent;
			pRight->_parent = parent;
			q.Insert(parent);
		}
		_pRoot = q.Top();

	}
protected:
	Node*  _pRoot;
};
#endif __HUFFMAN_H_