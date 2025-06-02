#include <iostream>
#include <map>
#include <unordered_map>
#include "ConsloeUtility.h"

using namespace std;

#pragma region �ؽ� �Լ��� �����ΰ�?
// Hash Fuction : Hashing �ϴ��� �ǹ�?
// - �����ϴ� Ÿ���� Ư���� ��Ģ���� �ٸ� Ÿ������ ��ȯ�ϴ� �۾�.
// 
// Hashing ����� �����͸� �������ؼ� ����� �� �ִ�.
// 
// Hash�� ���� �ڷᱸ���� ����?
// 
// map���� ������ ������ ������, ������ Ž���� ������.

int HashFuction(int input)
{
	return input % 10; // 0 ~ 9
}

void Test1()
{
	HashFuction(252349429); // 252349429 -> 9

	// unordered_map : [key - value] :: 9��� �ؽ������� 252349429���ڰ� ����ֽ��ϴ�.

	unordered_map<string, int> umap;

	umap.insert({ "�ٳ���", 5 });
	umap.insert({ "���", 3 });
	umap.insert({ "���ξ���", 4 });

	cout << "����1" << endl;
	cout << "�ٳ����� ���� : " << umap["�ٳ���"] << endl;

	cout << "����2" << endl;
	cout << "���ξ����� �����ϳ���?" << endl;

	auto it = umap.find("���ξ���");
	if (it != umap.end())
	{
		cout << "ã�ҽ��ϴ�." << endl;
		cout << "���ξ����� ���� : " << umap["���ξ���"] << endl;
	}
	else
	{
		cout << "ã�����߽��ϴ�." << endl;
	}
}
#pragma endregion


#pragma region map�� unordered_map ��
// Ž���ϴµ� unordered_map�� map���� ������.
// �������� ���� ������ �������� unordered_map�� �����ϴ�.
// unordered_map�� �����ϴ�.
// 
// �� �����Ѱ�?
// �����͸� �ʱ�ȭ�� �� �ɸ��� �ð�
// ���� �����̳� > ���� �����̳� (map) > unordered_map (�ؽ��Լ��� �����Ǿ���, �ؽ��Լ��� �����ϴ� ���� ������)
// 
// �ؽ��Լ��� ����
// - �ؽ��浹�� �߻��� �� �������ϰ� �߻��� �� �ִ�.

void MapTimeTest()
{
	map<string, int> map;
	map.insert({ "A", 1 });
	map.insert({ "B", 1 });
	map.insert({ "C", 1 });
	map.insert({ "D", 1 });
	map.insert({ "E", 1 });

	for (int i = 0; i < 1000; i++)
	{
		map.find("A");
	}
}

void UMapTimeTest()
{
	map<string, int> umap;
	umap.insert({ "A", 1 });
	umap.insert({ "B", 1 });
	umap.insert({ "C", 1 });
	umap.insert({ "D", 1 });
	umap.insert({ "E", 1 });

	for (int i = 0; i < 1000; i++)
	{
		umap.find("A");
	}
}

void Test2()
{
	cout << "ù��° �� - ������ �Է� �ð� ��" << endl;

	ConsoleUtil::TimeCheck(MapTimeTest);
	ConsoleUtil::TimeCheck(UMapTimeTest);

	cout << "map ���� : �������� �ڵ������� �߻��Ѵ�." << endl;
	cout << "������ �� �����͸� �ʿ�� �� �� map�� �����ϴ�." << endl;
	cout << "�� �̿ܿ� �����̳� ���� �����͸� ������ ã�� �����ϰ� �ʹ�." << endl;
	
	cout << "�ι�° �� - ������ �˻� �ð� ��" << endl;
	ConsoleUtil::TimeCheck(MapTimeTest);
	ConsoleUtil::TimeCheck(UMapTimeTest);
}
#pragma endregion


int main()
{
	//Test1();
	Test2();
}