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
		fseek(fin, 0, SEEK_SET);
		FILE *fout = fopen("pressfile.txt", "w");
		WriteCode(fin, fout);
		fclose(fin);
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

	void WriteCode(FILE* fin, FILE *fout)
	{
		char *writeBuff = new char[1024];
		char *readBuff = new char[1024];
		int writecount = 0;
		int readsize = 0;
		char code = 0;
		int pos = 0;
		while (true)
		{
			readsize = fread(readBuff, 1, 1024, fin);
			if (readsize)
			{
				for (int i = 0; i < readsize; ++i)
				{
					char c = readBuff[i];
					string Strcode = _cfile._symbol_arr[c].strcode;
					for (int j = 0; j < Strcode.length(); ++j)
					{
						if (Strcode[j] == '1')
							code |= 1;
						code <<= 1;
						if (++pos == 8)
						{
							writeBuff[writecount++] = c;
							code = 0;
							pos = 0;
							if (writecount == 1024)
							{
								fwrite(writeBuff, 1, 1024, fout);
								writecount = 0;
							}
						}
					}
				}
			}
			else
				break;
		}

		if (pos)
		{
			code <<= (8 - pos);
			writeBuff[writecount++] = code;
		}
		if (writecount)
			fwrite(writeBuff, 1, writecount-1, fout);

		delete []writeBuff;
		delete []readBuff;
	}
private:
	filestate _cfile;
};



#endif
