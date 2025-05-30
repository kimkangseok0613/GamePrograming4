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

#pragma region ���� �ڵ�

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
		items.insert({ 0, Item("�ռҵ�", 100, "����") });
		items.insert(make_pair(1, Item("õ����", 75, "����")));
		pair<int, Item> p1(2, Item("��������", 80, "����"));
		items.insert(p1);
		items.insert({ 3, Item("��ġ", 100, "����") });
		items.insert({ 4, Item("����", 125, "����") });
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
	void ShowItems()
	{
		string headersize = "012345678901234567890123456789012345678901234567890123456789";
		// �������� �Ӹ���
		//std::cout << headersize << endl;
		std::cout << setw(field1_width) << left << "�̸�" << setw(field2_width) << right << "����" << setw(field3_width) << right << "Ÿ��" << endl;
		
		// ������ �ߴ� ���
		std::cout << setw(total_width)	// ���� ����
			<< setfill('-') << ""	// ������ '-' ����
			<< endl;				// ���� ���� 2

		std::cout << setfill(' ');		// �⺻�������� ����

		// �������� ����϶�.
		for (int i=0; i<items.size(); i++)
		{
			std::cout << setw(field1_width) << left << items[i].name << setw(field2_width) << right << items[i].price << setw(field3_width) << right << items[i].type << endl;
		}
	}
	//�������� �Ǹ��Ѵ�.
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
		// �Է��� �޾��� �� ��ǥ�� ���ϴ� �ڵ�
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