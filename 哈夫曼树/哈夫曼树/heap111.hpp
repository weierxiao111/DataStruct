#ifndef __HEAP_H_
#define __HEAP_H_
#include <iostream>
using namespace std;
#include <vector>


template <class T>
struct Less {
	bool operator()(const T& Left, const T& Right)
	{
		return Left < Right;
	}
};

template <class T>
struct Greater {
	bool operator()(const T& Left, const T& Right)
	{
		return Left > Right;
	}
};

template <class T, class Compare = Less<T> >
class Heap {
public:
	Heap() {};
	Heap(const T arr[], size_t sz)
	{
		assert(arr);
		for (int i = 0; i < sz; ++i)
			_heap.push_back(arr[i]);
		if (sz > 1)
			for (int j = (sz - 1) / 2; j >= 0; --j)
			{
				_AdjustDown(j);
			}

	}

	T& Top()
	{
		return _heap[0];
	}
	const T& Top()const
	{
		return _heap[0];
	}

	size_t Size()const
	{
		return _heap.size();
	}
	bool Empty()const
	{
		return _heap.empty();
	}

	void Insert(const T& data)
	{
		_heap.push_back(data);
		if (Size() > 1)
			_AdjustUp(Size() - 1);
	}

	void Remove()
	{
		if (Empty())
			return;
		if (Size() == 1)
			_heap.pop_back();
		else
		{
			std::swap(_heap[0], _heap[Size() - 1]);
			_heap.pop_back();
			_AdjustDown(0);
		}
	}
protected:
	void _AdjustDown(size_t parent)
	{
		size_t chlid = 2 * parent + 1;
		while (chlid < _heap.size())
		{
			if (chlid + 1 < _heap.size())
				chlid = (Compare()(_heap[chlid], _heap[chlid + 1])) ? chlid : (chlid + 1);
			if (Compare()(_heap[chlid], _heap[parent]))
				std::swap(_heap[parent], _heap[chlid]);
			parent = chlid;
			chlid = 2 * parent + 1;
		}
	}

	void _AdjustUp(size_t chlid)
	{
		size_t parent = (chlid - 1) / 2;
		while (chlid != 0)
		{
			if (Compare()(_heap[chlid], _heap[parent]))
				std::swap(_heap[chlid], _heap[parent]);
			else
				break;

			chlid = parent;
			parent = (chlid - 1) / 2;
		}
	}


protected:
	std::vector<T> _heap;
};

//template <class T, template<class> class Compare>
template <class T, class Compare = Less<T>>
class PriorityQueue {
public:
	PriorityQueue()
		:_hp()
	{}
	void Push(const T& data)
	{
		_hp.Insert(data);
	}

	void Pop()
	{
		_hp.Remove();
	}

	const T& Top()const
	{
		return _hp._heap[0];
	}

	size_t Size()const
	{
		return _hp.Size();
	}

	bool Empty()const
	{
		return _hp.Empty();
	}

protected:
	Heap<T, Compare > _hp;
};
#endif