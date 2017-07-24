#include <iostream>
#include "快排的三种写法.hpp"
using namespace std;

int main()
{
	int arr[] = { 1,4,7,7,3,5,4,7,8,3,2,6,8,3,2,7,9,7,3,6,2,5,1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	//qSort(arr, 0, size);
	qsort(arr, 0,size-1);
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}