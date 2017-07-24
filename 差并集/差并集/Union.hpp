#pragma once
#include <iostream>
#include <vector>

using namespace std;

class UnionSet {
public:
	UnionSet(size_t n)
		:_ufs(n, -1)
	{ }

	int Getparent(size_t index)
	{
		int parent = index;
		while (_ufs[parent] >= 0)
		{
			parent = _ufs[parent];
		}
		return parent;
	}

	bool IsUnion(size_t index1, size_t index2)
	{
		return Getparent(index1) == Getparent(index2);
	}

	void Union(size_t index1, size_t index2)
	{
		size_t root1 = Getparent(index1);
		size_t root2 = Getparent(index2);

		if (root1 != root2)
		{
			_ufs[root1] += _ufs[root2];
			_ufs[root2] = root1;
		}
	}

	size_t Size() //返回有多少个集合
	{
		size_t count = 0;
		for (int i = 0; i < _ufs.size(); ++i)
		{
			if (_ufs[i] < 0)
				count++;
		}
		return count;
	}
private:
	vector<int> _ufs;
};
