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
	string strcode;
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
		fclose(fin);
		FILE *fout = fopen("pressfile.txt", "w");
		WriteCode(fout);
		fclose(fout);
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
		string StrCode;
		_GetCode(ht.GetRoot(), StrCode);
			
	}

	void _GetCode(Node<char> *proot, string  &strCode)
	{
		if (NULL == proot)
			return;
		if (NULL == proot->_pLeft && NULL == proot->_pRight)
		{
			_cfile._symbol_arr[proot->_weight].strcode = strCode;
		}
		_GetCode(proot->_pLeft, strCode + '0');
		_GetCode(proot->_pRight, strCode + '1');
	}

	void WriteCode(FILE *fout)
	{
		int i = 0;
		//char *writeBuff = new char[1024];
		char c = 0;
		int cnumber = 0;
		for (int i = 0; i < 256; ++i)
		{
			if (_cfile._symbol_arr[i]._char_count > 0)
			{
				string code = _cfile._symbol_arr[i].strcode;
				int len = code.length();
				for (int j = 0; j < len; ++j)
				{
					c &= (code[j] - '0');
					c << 1;
					cnumber++; 
					if (cnumber == 8)
					{
						fputc(c, fout);
						cnumber = 0;
					}
				}
			}
		} 
		c << (8 - cnumber);
	}

private:
	filestate _cfile;
};



#endif
