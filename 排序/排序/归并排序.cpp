#include <iostream>
#include <string.h>
using namespace std;
void _MergSort(int *arr, int left, int right, int *temp)
{
	if (right > left)
	{
		int mid = left + ((right - left) >> 1);
		int index = left;
		int start = left;
		_MergSort(arr, left, mid, temp );
		_MergSort(arr, mid+1, right, temp);
		while (left < right)
		{
			while (arr[left] < arr[mid + 1] && left <= mid)
			{
				temp[index++] = arr[left];
				left++;
			}
			while (arr[mid + 1] <= arr[left] && (mid + 1) <= right)
			{
				temp[index++] = arr[mid + 1];
				mid++;
			}
			if (left > mid || (mid + 1) > right)
				break;
		}

		while (left <= mid )
		{ 
			temp[index++] = arr[left];
			left++;
		}
		while ((mid + 1) < right)
		{
			temp[index++] = arr[mid + 1];
			mid ++;
		}
		memcpy(arr+start, temp+start, (right-start + 1)*sizeof(arr[0]));
	}
}

void MergSort(int *arr, int sz)
{
	if (sz < 2)
		return;
	int *temp = new int[sz];
	_MergSort(arr, 0, sz-1, temp);
	delete[] temp;
}

void PrintArr_(int *arr, int sz)
{
	for (int i = 0; i < sz; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


//
//int main()
//{
//	int arr[] = { 3,1,4,3,7,13,6,8,4,2,5,9,6 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	PrintArr_(arr, size);
//	MergSort(arr, size);
//	PrintArr_(arr, size);
//
//	return 0;
//}
