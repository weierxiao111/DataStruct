#include <iostream>
#include "typeTraits.h"
using namespace std;
#include <string>


template <typename T>
class Stack
{
public:
	Stack()
		:_capacity(0)
		,_Top(0)
		,_Base(0)
	{}

	Stack(const Stack<T>& st)
	{
		_Base = new T[st.Size()];
		Copy<T>(_Base,st._Base, st.Size());
		_Top = st.Size();
		_capacity = _Top;
	}

	Stack& operator = (const Stack<T> st)
	{
		if(this != &st)
		{
			size_t sz = st.Size();
			if (_capacity >= sz)
			{
				Copy<T>(_Base, st._Base, sz);
				_Top = sz;
			}
			else
			{
				T* temp = new T[sz];
				Copy<T>(temp, st._Base, sz);
				delete []_Base;
				_Base = temp;
				_capacity = sz;
			}			
		}
		return *this ;
	}

	bool Empty()const
	{
		return (0 == _Top);
	}

	void Push(const T& value)
	{
		CheckCapacity();
		_Base[_Top] = value;
		++_Top;
	}

	void Pop()
	{
		if (_Top != 0)
		{
			--_Top;
		}
	}

	const T& Top()const
	{
		if (_Top != 0)
		{
			return _Base[_Top-1];
		}
	}

	const int Size()const
	{
		return _Top;
	}

	~Stack()
	{
		if (_Base)
		{
			delete []_Base;
		}
		_capacity = 0;
		_Top = 0;	
	}

private:
    void CheckCapacity()
	{
		if(( _capacity - _Top) == 0)
		{
			if (_Top == 0)
			{
				_Base = new T[3];
			}
			else
			{
				T* temp = new T[_capacity+3];
				Copy<T>(temp, _Base, _Top);
				delete []_Base;
     			_Base = temp;
			}

			_capacity +=3;
		}

	}

private:
	size_t _capacity;
	size_t _Top;
	T* _Base;   

};

void FunTest1()
{
	Stack<int> st;
	st.Push(1);
	st.Push(2);
	st.Push(4);
	st.Push(2);
	st.Push(3);
	st.Push(4);
	st.Pop();
	Stack<int> sst(st);
	sst.Pop();
	sst = st;
}

int priority(char ch)
{
	switch (ch)
	{
	case '(':
		return 1;
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
	case '%':
		return 3;
	case ')':
		return 4;
	}
}

char* ReversedPolishNotion(const char* num, char* num2)
{
	Stack<char> st;
	memset(num2,0,sizeof(char)*(strlen(num2)+1));
	int count = 0;
	while(*num)
	{
		if(*num == '(' || *num == '+' || *num == '-'
			|| *num == '*' || *num == '/' || *num == '%'
			|| *num == ')')
		{
			if (*num == '(')
				st.Push(*num);
			else if (*num == ')')
			{
				while(st.Top() != '(')
				{
					num2[count ++] = st.Top();
					st.Pop();
				}
				st.Pop();
			}
			else if (st.Empty() || priority(*num) > priority(st.Top()))
				st.Push(*num);
			else 
			{
				while (priority(st.Top()) >= priority(*num) && !st.Empty())
				{
					num2[count++] = st.Top();
					st.Pop();
				}
				st.Push(*num);
			}
		}
		else
		{
			num2[count++] = *num;
		}

		num++;
	}

	while (!st.Empty())
	{
		num2[count++] = st.Top();
		st.Pop();
	}
	return num2;
}

int Jisuan(int &num1, int &num2, char c)
{
	switch(c)
	{
	case '+':return num2+num1;
	case '-':return num2-num1;
	case '*':return num2*num1;
	case '/':return num2/num1;
	case '%':return num2%num1;
	default:
		break;
	}
}

int postfix(const char* num)
{
	Stack<int> st;
	int ret = 0;
	while (*num)
	{
		if( *num == '+' || *num == '-'
			|| *num == '*' || *num == '/' || *num == '%')
		{
			if (st.Size() >= 2)
			{
				int num1 = st.Top();
				st.Pop();
				int num2 = st.Top();
				st.Pop();
				st.Push(Jisuan(num1,num2,*num));
			}
			else
				cout<<"后缀表达式错误"<<endl;
		}
		else
		{
			st.Push((*num) - '0');
		}
		num++;

	}
	if (st.Size() == 1)
		return st.Top();
	else 
	{
		cout<<"后缀表达式错误"<<endl;
		return 0;
	}	
}

int main()
{
	char num[] = "1+2*3+(4+5)/3+7";
	char num2[30] = {0};
	cout<<ReversedPolishNotion(num,num2)<<endl;
	cout<<postfix(num2)<<endl;
	return 0;
}
