#pragma once

#include <iostream>
#include <vector>
#include "ConsoleUtility.h"

using namespace std;

// 1. DropItem �����ڸ� ��������.
// 2. Monster �����͸� �޾ƿ� �� �ְ� private �ʵ带 �����Ѵ�.
// 3. public ���̺� ������, vector�� DropItemƲ �߰��غ�����.
// 4. �ڷᱸ���� ����ϴ� �Լ��� ��������.
//

struct DropItem
{
	string index;
	int exp;
	int money;

	DropItem() = default;
	DropItem(int exp, int money) : exp(exp), money(money) {}
};

class Monster
{
private:
	string index;
	int exp;
	int money;
	vector<DropItem> dropTable;
	DropItem currentDropItem;
public:
	Monster(int exp, int money) : exp(exp), money(money)
	{
		dropTable.emplace_back("�� ����", 10, 50);
		dropTable.emplace_back("���� �ݱ�", 20, 100);
		dropTable.emplace_back("�ݱ�", 30, 200);
		dropTable.emplace_back("Ŀ�ٶ� �ݱ�", 40, 300);
		dropTable.emplace_back("�Ŵ��� �ݱ�", 50, 400);

		// ���� � ����ġ ���̺��� �����ߴ°�?
		SetDropItem();
	}

	void SetDropItem()
	{
		int index = ConsoleUtil::GetRandomInt(dropTable.size()-1); // index 0���� �����Ѵ�. size()-1

		currentDropItem = dropTable[index];
	}

	void Drop()
	{
		currentDropItem.index;
		currentDropItem.exp;
		currentDropItem.money;
	}

	void Show() const
	{
		cout << index << " ȹ��!" << endl;
		cout << "����ġ�� " << exp <<" �����." << endl;
		cout << "������ : " << money << endl;
	}
};
