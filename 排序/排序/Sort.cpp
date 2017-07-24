#include <iostream>
using namespace std;

void InsertSort_1(int *arr, int sz) //≤Â»Î≈≈–Ú1
{
	for (int i = 1; i < sz; ++i)
	{
		int pos = i;
		while (pos > 0 && arr[i] < arr[pos-1])
			pos--;
		int temp = arr[i];
		for (int j = i; j > pos; --j)
		{
			arr[j] = arr[j - 1];
		}
		swap(temp,arr[pos]);
	}
}

void InsertSort_2(int arr[], int sz) //≤Â»Î≈≈–Ú2
{

	for (int i = 1; i < sz; ++i)
	{
		int left = 0;
		int right = i - 1;
		int mid = 0;
		int temp = arr[i];

		while (left <= right)
		{
			mid = left + ((right - left) >> 1);
			if (arr[mid] < temp)
			{
				left = mid + 1;
			}
			else if (mid > 0 && arr[mid] > temp)
			{
				right = mid - 1;
			}
			else
				break;
		}

		if (left > mid)
			mid = left;

		for (int j = i; j > mid; --j)
		{
			arr[j] = arr[j - 1];
		}
		swap(temp, arr[mid]);				        //                  - +
	}                                          //q w e r t y u i o p {}
}  

												//a s d f g h j k l ;
												 //z x c v b n m , . < 
void SelectSort(int *arr, int sz)
{
	for (int i = 0; i < sz/2; ++i)
	{
		int max = i;
		int min = i;

		for (int j = i+1; j < sz - i; ++j)
		{
			if (arr[j] < arr[min])
				min = j;
			else if (arr[j] > arr[max])
				max = j;
		}
		
		if (arr[min] != arr[i])
		swap(arr[i], arr[min]);
		if (arr[max] != arr[sz - 1 - i])
		swap(arr[sz - i - 1], arr[max]);
	}
}

void PrintArr(int *arr, int sz)
{
	for (int i = 0; i < sz; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void AdjustDown(int *arr, int parent, int sz)
{
	int Lchlid = parent * 2 + 1;
	int Rchlid = Lchlid + 1;
	int Maxchlid = Lchlid;
	if (Rchlid < sz)
		Maxchlid = (arr[Lchlid] > arr[Rchlid]) ? Lchlid: Rchlid;
	while (Lchlid < sz && arr[Maxchlid] > arr[parent])
	{
		swap(arr[Maxchlid], arr[parent]);
		parent = Maxchlid;
		 Lchlid = parent * 2 + 1;
		 Rchlid = Lchlid + 1;
		 Maxchlid = Lchlid;
		 if (Rchlid < sz )
			 Maxchlid = (arr[Lchlid] > arr[Rchlid]) ? Lchlid : Rchlid;
	}

	
}

void HeapSort(int *arr, int sz)
{
	int parent = (sz - 2) / 2;
	for (int i = 0; i <= parent; --parent)
		AdjustDown(arr,parent,sz);

	for (int j = sz-1; j >0 ; --j)
	{
		swap(arr[0], arr[j]);
		AdjustDown(arr, 0, j);
	}
}

int getmidnum(int *arr, int left, int right)
{
	if ((right - left) < 3)
	{
		return right-1;
	}
	int mid = left + ((right - left) >> 1);

	if (arr[left] < arr[right-1])
	{
		if (arr[mid] > arr[left])
		{
			if (arr[mid] < arr[right-1])
				return mid;
			else
				return right-1;
		}
		else
			return left;
	}
	else
	{
		if(arr[mid] > arr[right-1])
		{
			if (arr[mid] < arr[left])
				return mid;
			else
				return left;
		}
		else
			return right-1;
	}
}

int division_1(int *arr, int left, int right)
{
	int start = left;
	int end = right - 1;
	while (start < end)
	{
		while (start < end && arr[start] <= arr[right - 1])
			start++;
		while (start < end && arr[end] >= arr[right - 1])
			end--;
		if (start != end)
			swap(arr[start], arr[end]);
	}
	if (start != right - 1)
		swap(arr[right - 1], arr[start]);
	return start;
}

int division_2(int *arr, int left, int right)
{
	int start = left;
	int end = right - 1;
	int k = arr[end];
	while (start < end)
	{

		while (start < end && arr[end] >= k)
			end--;
		arr[start] = arr[end];

		while (start < end && arr[start] <= k)
			start++;
		arr[end] = arr[start];

	

		if (start < end)
		arr[start] = arr[end];
	}

	arr[right - 1] = k;
	return start;

}
int division_3(int *arr, int left, int right)
{
	int key = arr[right - 1];
	int i = left;
	for (int j = left + 1; j < right; ++j)
	{
		if (arr[j] <= key)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[right - 1], arr[i]);
	return i;

}

void QuickSort(int *arr, int left, int right)
{
	if ( left < right)
	{
		int std = getmidnum(arr, left, right);
		swap(arr[std], arr[right - 1]);
		int div = division_2(arr, left, right);
		QuickSort(arr, left, div);
		QuickSort(arr, div+1, right);

	}
}


//int main()
//{
//	int arr[] = { 3,1,4,3,7,13,6,8,4,2,5,9,6};
//	int size = sizeof(arr) / sizeof(arr[0]);
//	PrintArr(arr, size);
//	//InsertSort_1(arr, size);
//	//PrintArr(arr, size);
//	//SelectSort(arr, size);
//	//HeapSort(arr, size);
//	QuickSort(arr, 0, size);
//	PrintArr(arr, size);
//  	return 0;
//}