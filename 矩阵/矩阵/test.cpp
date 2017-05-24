#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

//∂‘≥∆æÿ’Û
/*  
template <typename T>
class SymmerticMatrix
{
public:
	SymmerticMatrix( const T *arr, size_t N)
		:_pData(new T[N*(N+1)/2])
		,_clo(N)
		,_row(N)
	{
		int k = 0;
		for(size_t i = 0; i< N; ++i)
		{
			for(size_t j = 0; j<= i; ++j)
			{
				_pData[k++] = arr[i*_row+j];
			}
		}
	}

	const T& Acess(size_t row, size_t clo)const
	{
		assert(clo<5 && row<5);
		return (row>clo)?_pData[row*(row+1)/2 + clo]
		:_pData[clo*(clo+1)/2 + row] ;
	}

	T& Acess(size_t row, size_t clo)
	{
		assert(clo<5 && row<5);
		return (row>clo)?_pData[row*(row+1)/2 + clo]
		:_pData[clo*(clo+1)/2 + row] ;
	}


	~SymmerticMatrix()
	{
		if (_pData)
		{
			delete []_pData;
		}
		_clo = 0;
		_row = 0;
	}

	template <typename T>
	friend ostream& operator<<(ostream& cout, const SymmerticMatrix<T>& sm);
private:
	T* _pData;
	size_t _row;
	size_t _clo;
};

template <typename T>
ostream& operator<<(ostream& cout, const SymmerticMatrix<T>& sm)
{
		for (size_t i = 0; i<sm._row; ++i)
		{
			for (size_t j = 0; j<sm._clo; ++j)
			{
				cout<<sm.Acess(i,j)<<" ";
			}
			cout<<endl;
		}
		return cout;
}

int main()
{
	int a[5][5] = {
	{0, 1, 2, 3, 4},
	{1, 0, 1, 2, 3},
	{2, 1, 0, 1, 2},
	{3, 2, 1, 0, 1},
	{4, 3, 2, 1, 0}};
	SymmerticMatrix<int> sm((int*)a,5);
	int ret = sm.Acess(4,1);
	cout<<sm;

	return 0;
}

*/

template <typename T>
class SparseMartix{
	template <typename T>
	struct Trituple{
		Trituple(int row = 0, int clo = 0, const T& value = T())
			:_row(row)
			,_clo(clo)
			,_value(value)
		{}
		size_t _row;
		size_t _clo;
		T _value;
	};

	template<class T>
	friend ostream& operator<<(ostream& _cout, const SparseMatrix<T>& sm);

public:
	SparseMartix(const T* arr, int row, int clo, const T& invailed)
		:rows(row)
		,clos(clo)
		,_invailed(invailed)
	{
		for (int i = 0; i< row; ++i)
			for (int j = 0; j< clo; ++j)
			{
				if (arr[i*clo+j] != invailed)
				{
					Trituple<T> temp(i,j,arr[i*clo+j]);
					_sm.push_back(temp);
				}
			}
	}

	SparseMartix()
		:rows(0)
		,clos(0)
		,_invailed(0)
	{}

	T& Acess(int row, int clo)
	{
		vector<Trituple<T>>::iterator it = _sm.begin();
		while (it != _sm.end())
		{
			if (row == it->_row && clo == it->_clo)
				return (it->_value);
			++it;
		}
		return _invailed;
	}

private:
	vector<Trituple<T>> _sm;
	size_t rows;
	size_t clos;
	T _invailed;
};

ostream& operator<<(ostream& _cout, const SparseMatrix<T>& sm)


int main()
{
	int	arr[6][5]={
	{1,0,3,0,5},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{1,0,3,0,5},
	{0,0,0,0,0},
	{0,0,0,0,0}};
	SparseMartix<int> m1((int*)arr, 6,5,0);
	SparseMartix<int> m2;
	int ret = m1.Acess(3,4);
	return 0;
}