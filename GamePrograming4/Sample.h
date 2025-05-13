#pragma once

// int array[100];
// 1. vector<int> vec;
// 
// 2. template ������ �ڵ�� �����غ� ��
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
		// this -> _number : �ڽ��� ���� ��ȣ
		// other.Get_Number(); : �� ����� ���� ��ȣ

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
	PocketMonster pica(25, "��ī��");
	PocketMonster �̻��ؾ�(1, "�̻��ؾ�");
	PocketMonster ���̸�(4, "���̸�");
	PocketMonster ���α�(7, "���α�");
	PocketMonster ����(16, "����");
	PocketMonster ������(25, "������");

	//cout << "No." << pica.Get_Number() << " " << pica.Get_Name() << endl;

	if (pica = ������)
	{
		cout << "��ī��� �������� ������ȣ�� ������ ���" << endl;
	}

	cout <<"�̻��ؾ��� ��ī�򺸴� ������ȣ�� ū����?" << endl;
	
	if(�̻��ؾ� > pica)
	{
		cout << "��" << endl;
	}

	else
	{
		cout << "�ƴϿ�" << endl;
	}

	vector<PocketMonster> pocketDatabase;

	// ������ �Է�
	pocketDatabase.push_back(pica);
	pocketDatabase.push_back(�̻��ؾ�);
	pocketDatabase.push_back(���̸�);
	pocketDatabase.push_back(���α�);
	pocketDatabase.push_back(����);
	pocketDatabase.push_back(������);

	// ����ó �˰��� (����)
	sort(pocketDatabase.begin(), pocketDatabase.end());

	// ������ ���
	for (auto& pocketmon : pocketDatabase)
	{
		cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
	}

	// ������ ã��
	for (auto& pocketmon : pocketDatabase)
	{
		if (pocketmon.Get_Number() == 1)
		{
			cout << "1�� ���͸� ã�Ҵ�." << endl;
			cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
		}
		else
		{
			cout << "��ã�Ҵ�." << endl;
			cout << "No." << pocketmon.Get_Number() << " " << pocketmon.Get_Name() << endl;
		}
	}
}