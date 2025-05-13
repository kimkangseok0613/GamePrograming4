#pragma once

// int array[100];
// 1. vector<int> vec;
// 
// 2. template 간단한 코드로 구현해볼 것
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class PocketMonster
{
private:
	int _number;
	string _name;
public:
	PocketMonster(int number, string name)
		:_number(number), _name(name) {}
	int Get_Number() const
	{
		return _number;
	}
	string Get_Name() const
	{
		return _name;
	}

	bool operator<(const PocketMonster& other)
	{
		// this -> _number : 자신의 도감 번호
		// other.Get_Number(); : 비교 대상의 도감 번호

		return this->_number < other.Get_Number();
		//return this->_name.length() < other.Get_Name().length();
	}
	bool operator>(const PocketMonster& other)
	{
		return this->_number > other.Get_Number();
	}
	bool operator=(const PocketMonster& other)
	{
		return this->_number = other.Get_Number();
	}
};

class Player
{
	vector<PocketMonster> myPocketmon;
};

void Example1()
{
	PocketMonster pica(25, "피카츄");
	PocketMonster 이상해씨(1, "이상해씨");
	PocketMonster 파이리(4, "파이리");
	PocketMonster 꼬부기(7, "꼬부기");
	PocketMonster 구구(16, "구구");
	PocketMonster 버터플(25, "버터플");

	//cout << "No." << pica.Get_Number() << " " << pica.Get_Name() << endl;

	if (pica = 버터플)
	{
		cout << "피카츄와 버터플의 도감번호가 같으면 출력" << endl;
	}

	cout <<"이상해씨가 피카츄보다 도감번호가 큰가요?" << endl;
	
	if(이상해씨 > pica)
	{
		cout << "네" << endl;
	}

	else
	{
		cout << "아니요" << endl;
	}

	vector<PocketMonster> pocketDatabase;

	// 데이터 입력
	pocketDatabase.push_back(pica);
	pocketDatabase.push_back(이상해씨);
	pocketDatabase.push_back(파이리);
	pocketDatabase.push_back(꼬부기);
	pocketDatabase.push_back(구구);
	pocketDatabase.push_back(버터플);

	// 데이처 알고리즘 (정렬)
	sort(pocketDatabase.begin(), pocketDatabase.end());

	// 데이터 출력
	for (auto& pocketmon : pocketDatabase)
	{
		cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
	}

	// 데이터 찾기
	for (auto& pocketmon : pocketDatabase)
	{
		if (pocketmon.Get_Number() == 1)
		{
			cout << "1번 몬스터를 찾았다." << endl;
			cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
		}
		else
		{
			cout << "못찾았다." << endl;
			cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
		}
	}
}