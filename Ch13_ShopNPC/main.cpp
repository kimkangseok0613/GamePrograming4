// 목표 : (1) 콘솔창에서 플레이어를 움직인다. (2) 특정 위치에 상점 NPC와 조우할 때 상점의 항목을 보여준다. (3) 상점을 이용한다.
// 
// Game Object : Player, Shop
// 자료구조, Item 어떠한 컨테이너에 보관하여 사용할 것인가?
// File Input & Output 메모장에 있는 데이터를 NPC에 전달하는 기능
//

#include <iostream>
#include <map>
#include <conio.h>
#include "ConsoleUtility.h"

#include <fstream> // ifstream ofstream
#include <iomanip> // 입출력 조작 헤더
#include <utility> // pair 클래스가 정의되어있다.

using namespace std;

const int total_width = 60;	 // 전체
const int field1_width = 30; // 이름 길이
const int field2_width = 15; // 가격
const int field3_width = 15; // 타입

class Item
{
public:
	string name;
	int price;
	string type;
public:
	Item() = default;
	Item(string name, int price, string type) : name(name), price(price), type(type) {}
};

#pragma region Player코드
class Player
{
public:
	int posX, posY, money;

	// (1) 플레이어가 소유한 인벤토리를 자료구조를 한가지 선택해서. 그 자료구조에 구매한 아이템을 저장해보세요.
	// (2) 저장한 자료구조를 사용하는 함수를 만들어보세요.

	Player() = default;
	Player(int posX, int posY, int money) : posX(posX), posY(posY), money(money) {}

	void ShowPlayerUI()
	{
		ConsoleUtil::GotoXY(50, 5);
		cout << "플레이어의 정보" << endl;
		ConsoleUtil::GotoXY(50, 6);
		cout << "돈 : " << money;

		// 보유한 아이템..
	}

	void BuyItem(Item& item)
	{
		money -= item.price;

		// vector.push_back(item);
		// map.insert(?,item); // 아이템의 이름으로 검색할 수 있게 map<string, item>
		// unordered_map<string, item>
	}
};
#pragma endregion

#pragma region 상점 코드



class Shop
{
private:
	map<int, Item>items;
public:
	Shop()
	{
		items.insert({ 0, Item("롱소드", 100, "무기") });
		items.insert(make_pair(1, Item("천갑옷", 75, "무기")));
		pair<int, Item> p1(2, Item("나무방패", 80, "무기"));
		items.insert(p1);
		items.insert({ 3, Item("망치", 100, "무기") });
		items.insert({ 4, Item("도끼", 125, "무기") });
	}
	Shop(string filename)
	{
		LoadShopData(filename);
	}
	void LoadShopData(string filename)
	{
		ifstream in_file;
		in_file.open(filename);

		string name;
		int price;
		string type;

		if(!in_file)
		{ 
			cerr << "파일을 여는데 실패했습니다." << endl;
			exit(1);
		}

		int index = 0;

		while (!in_file.eof()) // end of file(파일의 끝에 도달했을 때 true반환)
		{
			in_file >> name >> price >> type;					// 파일에서 name, price, type 읽기
			items.insert({ index, Item(name, price, type) }) ;	// map 자료구조에 저장
			index++;											// 다음 index 넘어가기
		}

		in_file.close();
	}

	void SaveShopData(string filename)
	{
		ofstream out_file;
		out_file.open(filename);

		string name;
		int price;
		string type;

		if (!out_file)
		{
			cerr << "파일을 여는데 실패했습니다." << endl;
			exit(1);
		}

		for (int i = 0; i < items.size(); i++)
		{
			out_file << setw(field1_width) << left << items[i].name << setw(field2_width) << right << items[i].price << setw(field3_width) << right << items[i].type << endl;
		}

		out_file.close();
	}

	// 데이터를 사용하여 기능을 구현한다.
	void ShowItems(int x, int y)
	{
		string headersize = "012345678901234567890123456789012345678901234567890123456789";
		// 아이템의 머릿말
		//std::cout << headersize << endl;

		ConsoleUtil::GotoXY(x, y); // 원하는 위치에 상점UI를 출력한다.

		std::cout << setw(field1_width) << left << "이름" << setw(field2_width) << right << "가격" << setw(field3_width) << right << "타입" << endl;
		
		ConsoleUtil::GotoXY(x + 1, y);
		// 라인을 긋는 방법
		std::cout << setw(total_width)	// 길이 설정
			<< setfill('-') << ""	// 공백을 '-' 설정
			<< endl;				// 길이 설정 2

		std::cout << setfill(' ');		// 기본버전으로 리셋

		// 아이템을 출력하라.
		for (int i=0; i<items.size(); i++)
		{
			ConsoleUtil::GotoXY(x, y + 2 + i);
			std::cout << setw(field1_width) << left << items[i].name << setw(field2_width) << right << items[i].price << setw(field3_width) << right << items[i].type << endl;
		}
	}
	
	//아이템을 판매한다. (플레이어가 돈이 없으면..)
	bool BuyItem(int index, Player& player)
	{
		if (items.find(index) != items.end()) // 해당하는 아이템을 찾았다.
		{
			Item itemInstance = items[index];
			if (player.money >= itemInstance.price) // 플레이어가 소지금이 충분할 때
			{
				player.BuyItem(itemInstance);
				return true;
			}
			else
			{
				cout << "소지금이 부족합니다." << endl;
			}
		}
		else
		{
			cout << "아이템을 찾지 못했습니다." << endl;
		}
	}

	void Interact(Player& player)
	{
		int select;
		cout << "번호를 입력하여 아이템을 구매할 수 있습니다." << endl;
		cin >> select;

		BuyItem(select, player);
	}
};

#pragma endregion

#pragma region NPC 코드

class NPC
{
private:
	Shop shop;
public:
	int posX;
	int posY;
	bool isActivate;

	NPC() = default;
	NPC(string filename, int posX, int posY) : posX(posX), posY(posY), isActivate(true)
	{
		shop = Shop(filename);
	}

	void ShowItems(int x, int y)
	{
		shop.ShowItems(x, y);
	}

	void Interact(Player& player)
	{
		shop.Interact(player);
		isActivate = false;
	}

	void ShowNPC()
	{
		if (isActivate == false) { return; }

		ConsoleUtil::GotoXY(posX, posY);
		cout << "$";
	}
};

void Interact(Player& player, NPC& npc, int UI_X, int UI_Y)
{
	if (player.posX == npc.posX && player.posY == npc.posY)
	{
		if (!npc.isActivate) { return; }// npc.isActivate==false // 상점이 비활성화 되면 사용 불가능

		npc.ShowItems(UI_X, UI_Y);
		npc.Interact(player);
	}
}

void ShopPhase(Shop&)
{

}

#pragma endregion

int main()
{
	ConsoleUtil::SetCursorVisible(false);

	Player player(10, 10, 1000); // 플레이어의 시작 설정

	//int playerX = 10;
	//int playerY = 10;

	NPC npc1("Shop1.txt",3,5);
	NPC npc2("Shop2.txt",10,2);
	NPC npc3("Shop3.txt",8,6);

	//shop.SaveShopData("Shop3.txt");

	while (true)
	{
		// 입력을 받았을 때 좌표가 변하는 코드
		if (_kbhit())
		{
			system("cls");

			if (GetAsyncKeyState(VK_UP))
			{
				player.posY--;
				if (player.posY <= 0) { player.posY = 0; }
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				player.posY++;
			}
			if (GetAsyncKeyState(VK_LEFT))
			{
				player.posX--;
				if (player.posX <= 0) { player.posX = 0; }
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				player.posX++;
			}
			
		}
		//shop.ShowItems();

		player.ShowPlayerUI();

		npc1.ShowNPC();
		npc2.ShowNPC();
		npc3.ShowNPC();

		Interact(player, npc1, 0, 10);
		Interact(player, npc2, 0, 10);
		Interact(player, npc3, 0, 10);

		ConsoleUtil::GotoXY(player.posX, player.posY);
		std::cout << "a";

		_getch();		
	}
	
	
}