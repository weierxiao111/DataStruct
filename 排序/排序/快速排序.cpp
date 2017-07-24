#include <iostream>
#include <assert.h>
using namespace std;

void midofthree(int *arr, int left, int right) //三数中值分割
{
	int mid = left + ((right - left) >> 1);

	if (arr[left] > arr[right])
		swap(arr[left], arr[right]);
	if (arr[right] > arr[mid])
		swap(arr[right], arr[mid]);
	if (arr[right] < arr[left])
		swap(arr[left], arr[right]);
	//arr[left] <= arr[right] <=arr[mid] 把arr[right]作为扭曲元  
}

int partain(int *arr, int left, int right)
{
	int start = left;
	int end = right;
	while (start < end)
	{
		while (start < end  &&  arr[start] <= arr[right])
			start++;
		while (start < end &&   arr[end] >= arr[right])
			end--;
		if (start < end)
			swap(arr[start], arr[end]);
	}
	swap(arr[right], arr[start]);
	return start;
}

void _qsort(int *arr, int left, int right) //闭区间
{
	if (left < right-1 )
	{
		 midofthree(arr, left, right);
		 int div = partain(arr, left , right);
		 _qsort(arr, left, div-1);
		 _qsort(arr, div+1, right);
	}
}

void qsort(int *arr, int sz)
{
	if (sz < 2)
		return;
	_qsort(arr, 0, sz - 1);
}
int main()
{
	int arr[] = {1,4,6,3,7,9,7,5,3,2,6,2,8,5,2,6,1,0,6,9};
	int size = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, size);
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}