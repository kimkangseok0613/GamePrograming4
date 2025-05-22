#pragma once

//
// 데이터 저장.
// 1. 플레이어의 레벨, 경험치
// 
// 2. 데이터 자료구조 형태로 저장.
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

	// file 열어라.
	// 메모장에 exp 와 level 을 저장해라.
	// close
	void SaveData(const string& filename)
	{
		ofstream file(filename); // ofstream : 세이브 ifstream : 로드

		if (file.is_open())
		{
			file << level << " " << exp << endl;
			file.close();
		}
	}

	void LoadData(const string& filename)
	{
		ifstream file(filename); // ofstream : 세이브 ifstream : 로드

		int _exp, _level;

		file >> _level >> _exp;

		level = _level;
		exp = _exp;
	}
};