#pragma once

#include <iostream>
#include <vector>
#include "ConsoleUtility.h"

using namespace std;

// 1. DropItem 생성자를 만들어보세요.
// 2. Monster 데이터를 받아올 수 있게 private 필드를 선언한다.
// 3. public 레이블에 생성자, vector의 DropItem틀 추가해보세요.
// 4. 자료구조를 사용하는 함수를 만들어보세요.
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
		dropTable.emplace_back("금 조각", 10, 50);
		dropTable.emplace_back("작은 금괴", 20, 100);
		dropTable.emplace_back("금괴", 30, 200);
		dropTable.emplace_back("커다란 금괴", 40, 300);
		dropTable.emplace_back("거대한 금괴", 50, 400);

		// 내가 어떤 경험치 테이블을 선택했는가?
		SetDropItem();
	}

	void SetDropItem()
	{
		int index = ConsoleUtil::GetRandomInt(dropTable.size()-1); // index 0부터 시작한다. size()-1

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
		cout << index << " 획득!" << endl;
		cout << "경험치를 " << exp <<" 얻었다." << endl;
		cout << "소지금 : " << money << endl;
	}
};
