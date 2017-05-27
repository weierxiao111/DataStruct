#include <iostream>
using namespace std;
#include "HuffmanZip.hpp"

int main()
{
	//Huffmanzip zip("a.txt");
	char i = 0;
	FILE *fout = fopen( "pressfile", "w");
	fputc(i, fout);
	fclose(fout);
	return 0;
}