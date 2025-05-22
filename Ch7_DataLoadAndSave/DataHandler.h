#pragma once

//
// ������ ����.
// 1. �÷��̾��� ����, ����ġ
// 
// 2. ������ �ڷᱸ�� ���·� ����.
// 1 100
// 2 100
//

#include <fstream>
#include <iostream>

using namespace std;

class Data
{
public:
	int exp;
	int level;
public:
	Data() : exp(100), level(1) {}

	// file �����.
	// �޸��忡 exp �� level �� �����ض�.
	// close
	void SaveData(const string& filename)
	{
		ofstream file(filename); // ofstream : ���̺� ifstream : �ε�

		if (file.is_open())
		{
			file << level << " " << exp << endl;
			file.close();
		}
	}

	void LoadData(const string& filename)
	{
		ifstream file(filename); // ofstream : ���̺� ifstream : �ε�

		int _exp, _level;

		file >> _level >> _exp;

		level = _level;
		exp = _exp;
	}
};