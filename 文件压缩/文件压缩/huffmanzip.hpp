#pragma once
#ifndef __ZIP_H_
#define __ZIP_H_
#include "HuffmanTree.hpp"
#include <iostream>
#include <string>
using namespace std;

struct symbol {
	symbol()
		: _char_count(0)
	{}
	char _character;
	size_t _char_count;
	char _huffcode[20];
};

struct filestate {
	filestate()
		:_symbol_count(0)
	{}
	size_t _symbol_count;
	symbol _symbol_arr[256];
};


class Huffmanzip {
public:
	Huffmanzip(const string& zipname)
	{
		FILE* fin = fopen(zipname.c_str(), "r");
		if (NULL == fin)
		{
			cout << "open failed !"<<endl;
			exit(1);
		}
		Getchar(fin);
		GetHuffmanCode();
		
	}
private:
	void Getchar(FILE *fin)
	{
		char *ReadBuff = new char[1024];
		memset(ReadBuff, 0, 1024 * sizeof(char));

		while (true)
		{
			size_t readsize = fread(ReadBuff, 1, 1024, fin);
			if (readsize == 0)
				break;
			for (int i = 0; i < readsize; ++i)
			{
				char c = ReadBuff[i];
				if (_cfile._symbol_arr[c]._char_count++ == 0)
				{
					_cfile._symbol_count++;
					_cfile._symbol_arr[c]._character = c;
				}
			}
		}
		delete []ReadBuff;
	}

	void GetHuffmanCode()
	{
		char CodeArr[256];
		memset(CodeArr, 0, 256 * sizeof(char));
		int count = 0;
		for (int i = 0; i < 256; ++i)
		{
			if (_cfile._symbol_arr[i]._char_count != 0)
				CodeArr[count++] = _cfile._symbol_arr[i]._character;
		}
		HuffmanTree<char> ht(CodeArr, count);
		_GetCode( ht.GetRoot());
	}

	string  StrCode;
	void _GetCode(Node<char> *proot, string & strCode)
	{
		if (NULL == proot)
			return;
		if 
	}

private:
	filestate _cfile;
};



#endif
