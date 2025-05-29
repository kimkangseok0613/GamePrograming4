// ���� �����̳� : (multi, unordered) set, map

#include <set>
#include <map>
#include <algorithm>

#include <iostream>
#include <iomanip>
#include <utility>

using namespace std;

// set�� ������� �� �������� �߻��ϴ°�?
#pragma region ���� �����̳� ����ϱ�

void Test1()
{
	cout << "Set" << endl;

	set<int> nums;
	
	// �����͸� ��� ������ �� �ֳ���? push
	// ���� �����̳�? insert
	// ���� �����̳ʿ� �����͸� �Է��ϸ� �ڵ����� ������ �ȴ�.
	// Ž���� �Ҷ� ���ĵ� ����� ����ϸ� ȿ�����̴�.
	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7); // {1,5,2,7,} -> {1,2,5,7} ���ĵȴ�.

	cout << "Ư¡1. Set�� �����Ͱ� �ڵ����� ���ĵ�" << endl;
	for (const auto& num : nums)
	{
		cout << num << " ";
	}
	cout << endl;

	// set�� Ư¡. �ߺ��� �ȵȴ�.

	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7); // {1,1,2,2,5,5,7,7}

	cout << "Ư¡2. Set�� �����ʹ� �ߺ��� �ȵȴ�." << endl;
	for (const auto& num : nums)
	{
		cout << num << " ";
	}
	cout << endl;
}

void Test2()
{
	cout << "Multi set" << endl;

	multiset<int> nums;

	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7); // {1,5,2,7,} -> {1,2,5,7} ���ĵȴ�.

	cout << "Ư¡1. Multiset�� �����Ͱ� �ڵ����� ���ĵ�" << endl;
	for (const auto& num : nums)
	{
		cout << num << " ";
	}
	cout << endl;

	// set�� Ư¡. �ߺ��� �ȵȴ�.

	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7); // {1,1,2,2,5,5,7,7}

	cout << "Ư¡2. Multiset�� �����ʹ� �ߺ��� �ȵȴ�." << endl;
	for (const auto& num : nums)
	{
		cout << num << " ";
	}
	cout << endl;
}

#pragma endregion

#pragma region Ŀ���� Ŭ������ set�� �ִ� ���

struct Item
{
	int id;
	string name;

	Item() = default;
	Item(int id, string name) : id(id), name(name) {}

	bool operator < (const Item& other) const
	{
		return id < other.id; // 1,2,3...
							  // ��,��,��...
	}
};

void Test3()
{
	cout << "Ŀ���� ��ü�� Set���� ����ϱ�" << endl;

	set<Item> items;

	Item item1(1,"����");
	Item item2(2,"��");
	Item item3(3,"�ٳ���");
	Item item4(100,"Į");
	Item item5(50,"����");

	items.insert(item1);
	items.insert(item2);
	items.insert(item3);
	items.insert(item4);
	items.insert(item5);

	cout << "�ߺ��� ��� ����" << endl;
	items.insert(Item(3, "����")); // -> 3�� �̹� �־ ��¾ȵ�. name ����� ����.

	for (const auto& item : items)
	{
		cout << item.id << " " << item.name << endl;
	}

	cout << "Set�� ����ϸ� �������� ũ�⿡ ���� �ڵ����� ������ ����� ���� �� �ִ�." << endl;
	cout << "find �Լ��� ����ؼ� ������ �����͸� ã�� �� �ִ�." << endl;

	// item ��ü�� items �ȿ��� ã�ƾ��Ѵ�.
	// item�� id�� n���� �����͸� ã��ʹ�.
	// map�� ����ϸ� ���� �������� ���� �ذ��� �� �ִ�.
}

#pragma endregion

#pragma region map ����ϱ�

void Test4()
{
	cout << "map �ڷᱸ�� ����ϱ�" << endl;

	map<int, Item> items;

	// map�� �����͸� �ִ� ���, pairŬ������ �����ϴ� ��� (1) �߰�ȣ�� ���

	items.insert({ 0,Item(100,"����") });

	// (2) make_pair�Լ� ����ϱ�
	items.insert(make_pair(10, Item(1000, "�ռҵ�")));

	// (3) pairŬ������ ���� �����ϱ�. (����� �ʿ� utility)
	pair<int, Item> p1(5, Item(101, "���� ����"));

	items.insert(p1);

	cout << "Ư¡1. map�� pair�� �̷���� �����͸� �����ϴ� �����̳��̴�." << endl;
	cout << "Ư¡2. map�� key������ �ڵ� ������ �̷�����ϴ�." << endl;

	for (const auto& item : items)
	{
		cout << item.first << " " << "ID: " << item.second.id << " NAME :" << item.second.name << endl;
	}

	cout << "Ư¡3. ����(Dictionary)�� �ڷᱸ���Դϴ�." << endl;

	cout << items[0].id << items[0].name << endl; // items[0] => Item(100,"����")
}

#pragma endregion


// set���� �����͸� �������� ���� ������ ��, �װ��� ������ map
// pair�� ���Ǹ� �ؾ��Ѵ�.

int main()
{
	//Test1();
	//Test2();
	//Test3();
	Test4();
}