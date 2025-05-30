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

#pragma region 상점 코드

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
	void ShowItems()
	{
		string headersize = "012345678901234567890123456789012345678901234567890123456789";
		// 아이템의 머릿말
		//std::cout << headersize << endl;
		std::cout << setw(field1_width) << left << "이름" << setw(field2_width) << right << "가격" << setw(field3_width) << right << "타입" << endl;
		
		// 라인을 긋는 방법
		std::cout << setw(total_width)	// 길이 설정
			<< setfill('-') << ""	// 공백을 '-' 설정
			<< endl;				// 길이 설정 2

		std::cout << setfill(' ');		// 기본버전으로 리셋

		// 아이템을 출력하라.
		for (int i=0; i<items.size(); i++)
		{
			std::cout << setw(field1_width) << left << items[i].name << setw(field2_width) << right << items[i].price << setw(field3_width) << right << items[i].type << endl;
		}
	}
	//아이템을 판매한다.
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

	NPC() = default;
	NPC(string filename, int posX, int posY) : posX(posX), posY(posY)
	{
		shop = Shop(filename);
	}

	void ShowItems()
	{
		shop.ShowItems();
	}

	void ShowNPC()
	{
		ConsoleUtil::GotoXY(posX, posY);
		cout << "@";
	}
};

void Interact(int x1, int y1, NPC& npc)
{
	if (x1 == npc.posX && y1 == npc.posY)
	{
		npc.ShowItems();
	}
}

void ShopPhase(Shop&)
{

}

#pragma endregion




int main()
{
	ConsoleUtil::SetCursorVisible(false);

	int playerX = 10;
	int playerY = 10;

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
				playerY--;
				if (playerY <= 0) { playerY = 0; }
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				playerY++;
			}
			if (GetAsyncKeyState(VK_LEFT))
			{
				playerX--;
				if (playerX <= 0) { playerX = 0; }
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				playerX++;
			}
			
		}
		//shop.ShowItems();

		npc1.ShowNPC();
		npc2.ShowNPC();
		npc3.ShowNPC();

		Interact(playerX, playerY, npc1);
		Interact(playerX, playerY, npc2);
		Interact(playerX, playerY, npc3);

		ConsoleUtil::GotoXY(playerX, playerY);
		std::cout << "a";

		_getch();		
	}
	
	
}