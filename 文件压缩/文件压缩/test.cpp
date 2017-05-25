#include <iostream>
using namespace std;
#include "HuffmanTree.hpp"

int main()
{
	int arr[] = { 1,3,5,7 };
	HuffmanTree<int> ht(arr, 4);
	return 0;
}