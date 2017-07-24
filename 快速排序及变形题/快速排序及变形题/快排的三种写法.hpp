#pragma once
#include <iostream>
using namespace std;
/*
int partition_1(int *arr, int left, int right)
{
	int start = left;
	int end = right - 1;
	int key = arr[right - 1];
	while (start < end)
	{
		while (start < end && arr[start] <= key)
			start++;
		if (start < end)
			arr[end] = arr[start];
		while (start < end && arr[end] >= key)
			end--;
		if (start < end)
			arr[start] = arr[end];
	}
	arr[end] = key;
	return end;

}

int partition(int *arr, int left, int right)
{
	int start = left;
	int end = right - 1;
	int key = arr[right - 1];
	while (start < end)
	{
		while (start < end && arr[start] <= key)
			start++;
		while (start < end && arr[end] >= key)
			end--;
		if (start < end)
			swap(arr[start], arr[end]);
	}
	swap(arr[start], arr[right - 1]);
	return start;
}

int partition_3(int *arr, int left, int right)
{
	int slow = left-1;
	int quick = left;
	int key = arr[right - 1];
	while (quick < right)
	{
		if (arr[quick] < key && (++slow != quick))
			swap(arr[quick], arr[slow]);
		quick++;
	}
	swap(arr[++slow], arr[right - 1]);
	return slow;
}

void qSort(int *arr, int left, int right)// ×ó¿ªÓÒ±Õ
{
	if (left < right)
	{
		int div = partition_3(arr, left, right);
		qSort(arr, left, div);
		qSort(arr, div + 1, right);
	}
}

void adjustdown(int *arr, int parent,int sz)
{
	int lchlid = 2 * parent + 1;
	while (lchlid < sz)
	{
		if (lchlid + 1 < sz && arr[lchlid + 1] > arr[lchlid])
			lchlid += 1;
		if (arr[lchlid] > arr[parent])
		{
			swap(arr[lchlid], arr[parent]);
			parent = lchlid;
			lchlid = 2 * parent + 1;

		}
		else
			break;
	}
}

void heapSort(int *arr, int sz)
{
	if (sz < 2)
		return;
	for (int i = (sz-1)/2; i >= 0; --i)
		adjustdown(arr,i,sz);
	for (int j = sz - 1; j >= 1; --j)
	{
		swap(arr[0], arr[j]);
		adjustdown(arr, 0, j);
	}
}

*/


int partain_1(int *arr, int left, int right)
{
	int start = left;
	int end = right;
	int key = arr[right];

	while (start < end)
	{
		while (start <= end && arr[start] <= key)
			start++;
		while (start <= end && arr[end] >= key)
			end--;
		if (start < end)
			swap(arr[start], arr[end]);
	}
	swap(arr[right], arr[start]);
	return start;
}

int partain_2(int *arr, int left, int right)
{
	int start = left;
	int end = right;
	int key = arr[right];
	while (start < end)
	{
		while (start < end && arr[start] <= key)
			start++;
		if (start < end)
		arr[end] = arr[start];

		while (start < end && arr[end] >= key)
			end--;
			if (start < end)
				arr[start] = arr[end];

	}
}

void qsort(int *arr, int left, int right)
{
	if (left < right)
	{
		int div = partain_1(arr, left, right);
		qsort(arr, left, div - 1);
		qsort(arr, div + 1, right);
	}
}
