#include <iostream>
#include "Union.hpp"
using namespace std;

int main()
{
	UnionSet un(5);
	un.Union(0, 1);
	un.Union(1, 2);
	cout << un.Size() << endl;
}

