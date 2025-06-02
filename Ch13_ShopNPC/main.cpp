// ��ǥ : (1) �ܼ�â���� �÷��̾ �����δ�. (2) Ư�� ��ġ�� ���� NPC�� ������ �� ������ �׸��� �����ش�. (3) ������ �̿��Ѵ�.
// 
// Game Object : Player, Shop
// �ڷᱸ��, Item ��� �����̳ʿ� �����Ͽ� ����� ���ΰ�?
// File Input & Output �޸��忡 �ִ� �����͸� NPC�� �����ϴ� ���
//

#include <iostream>
#include <map>
#include <conio.h>
#include "ConsoleUtility.h"

#include <fstream> // ifstream ofstream
#include <iomanip> // ����� ���� ���
#include <utility> // pair Ŭ������ ���ǵǾ��ִ�.

using namespace std;

const int total_width = 60;	 // ��ü
const int field1_width = 30; // �̸� ����
const int field2_width = 15; // ����
const int field3_width = 15; // Ÿ��

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

#pragma region Player�ڵ�
class Player
{
public:
	int posX, posY, money;

	// (1) �÷��̾ ������ �κ��丮�� �ڷᱸ���� �Ѱ��� �����ؼ�. �� �ڷᱸ���� ������ �������� �����غ�����.
	// (2) ������ �ڷᱸ���� ����ϴ� �Լ��� ��������.

	Player() = default;
	Player(int posX, int posY, int money) : posX(posX), posY(posY), money(money) {}

	void ShowPlayerUI()
	{
		ConsoleUtil::GotoXY(50, 5);
		cout << "�÷��̾��� ����" << endl;
		ConsoleUtil::GotoXY(50, 6);
		cout << "�� : " << money;

		// ������ ������..
	}

	void BuyItem(Item& item)
	{
		money -= item.price;

		// vector.push_back(item);
		// map.insert(?,item); // �������� �̸����� �˻��� �� �ְ� map<string, item>
		// unordered_map<string, item>
	}
};
#pragma endregion

#pragma region ���� �ڵ�



class Shop
{
private:
	map<int, Item>items;
public:
	Shop()
	{
		items.insert({ 0, Item("�ռҵ�", 100, "����") });
		items.insert(make_pair(1, Item("õ����", 75, "����")));
		pair<int, Item> p1(2, Item("��������", 80, "����"));
		items.insert(p1);
		items.insert({ 3, Item("��ġ", 100, "����") });
		items.insert({ 4, Item("����", 125, "����") });
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
			cerr << "������ ���µ� �����߽��ϴ�." << endl;
			exit(1);
		}

		int index = 0;

		while (!in_file.eof()) // end of file(������ ���� �������� �� true��ȯ)
		{
			in_file >> name >> price >> type;					// ���Ͽ��� name, price, type �б�
			items.insert({ index, Item(name, price, type) }) ;	// map �ڷᱸ���� ����
			index++;											// ���� index �Ѿ��
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
			cerr << "������ ���µ� �����߽��ϴ�." << endl;
			exit(1);
		}

		for (int i = 0; i < items.size(); i++)
		{
			out_file << setw(field1_width) << left << items[i].name << setw(field2_width) << right << items[i].price << setw(field3_width) << right << items[i].type << endl;
		}

		out_file.close();
	}

	// �����͸� ����Ͽ� ����� �����Ѵ�.
	void ShowItems(int x, int y)
	{
		string headersize = "012345678901234567890123456789012345678901234567890123456789";
		// �������� �Ӹ���
		//std::cout << headersize << endl;

		ConsoleUtil::GotoXY(x, y); // ���ϴ� ��ġ�� ����UI�� ����Ѵ�.

		std::cout << setw(field1_width) << left << "�̸�" << setw(field2_width) << right << "����" << setw(field3_width) << right << "Ÿ��" << endl;
		
		ConsoleUtil::GotoXY(x + 1, y);
		// ������ �ߴ� ���
		std::cout << setw(total_width)	// ���� ����
			<< setfill('-') << ""	// ������ '-' ����
			<< endl;				// ���� ���� 2

		std::cout << setfill(' ');		// �⺻�������� ����

		// �������� ����϶�.
		for (int i=0; i<items.size(); i++)
		{
			ConsoleUtil::GotoXY(x, y + 2 + i);
			std::cout << setw(field1_width) << left << items[i].name << setw(field2_width) << right << items[i].price << setw(field3_width) << right << items[i].type << endl;
		}
	}
	
	//�������� �Ǹ��Ѵ�. (�÷��̾ ���� ������..)
	bool BuyItem(int index, Player& player)
	{
		if (items.find(index) != items.end()) // �ش��ϴ� �������� ã�Ҵ�.
		{
			Item itemInstance = items[index];
			if (player.money >= itemInstance.price) // �÷��̾ �������� ����� ��
			{
				player.BuyItem(itemInstance);
				return true;
			}
			else
			{
				cout << "�������� �����մϴ�." << endl;
			}
		}
		else
		{
			cout << "�������� ã�� ���߽��ϴ�." << endl;
		}
	}

	void Interact(Player& player)
	{
		int select;
		cout << "��ȣ�� �Է��Ͽ� �������� ������ �� �ֽ��ϴ�." << endl;
		cin >> select;

		BuyItem(select, player);
	}
};

#pragma endregion

#pragma region NPC �ڵ�

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
		if (!npc.isActivate) { return; }// npc.isActivate==false // ������ ��Ȱ��ȭ �Ǹ� ��� �Ұ���

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

	Player player(10, 10, 1000); // �÷��̾��� ���� ����

	//int playerX = 10;
	//int playerY = 10;

	NPC npc1("Shop1.txt",3,5);
	NPC npc2("Shop2.txt",10,2);
	NPC npc3("Shop3.txt",8,6);

	//shop.SaveShopData("Shop3.txt");

	while (true)
	{
		// �Է��� �޾��� �� ��ǥ�� ���ϴ� �ڵ�
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