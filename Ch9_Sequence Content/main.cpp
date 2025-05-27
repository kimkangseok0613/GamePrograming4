#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "TimeCheck.h"
#include "FunctionPointer.h"
#include "ConsoleUtility.h"

using namespace std;

// Sequence Container
// vector
// deque
// list

// ��ǥ) vector�� list�� �������� ���� ���غ�����.
// 
// 1. vector push_back �߰�, list push_back �߰��� �ð��� ���غ�����.: ��� < > ���� �� ������. �� ����?
// 2. ������ �����Ϳ� �����ϴµ� �ɸ��� �ð�	: ��� vector�� �� ������. list ������ �������� �� �ð��� �ɸ���.
// 3. ������ �����͸� ����µ� �ɸ��� �ð�		: list�� �� ������.
// 
//	�����Ͱ� ������ ������, ������ ���� ���	: vector ����
//	�������� ������ ����� ���				: list ����
// 
// (�ڡڡڡڡ�)������ ������ ���� ���ٵ� ���� ��� : ?? unordered.map
// 
// vector
// unordered.map
//

// vector, list ũ�� �������� ����.
// vector [ ] �ε����� �����͸� ����� �� �ִ�.
// list [ ] �ε����� ������ �� ����.	// �迭�� �ƴϸ� ��� �ڷḦ ǥ���� �� ������?
// 
// �������� ������ Ȯ���ϱ� ���ؼ� ȯ�� ������ �����Ѵ�.
//

struct Node
{
	int value;
	Node* nextPtr;
	Node* prevPtr;
};

void Test1_Vector()
{
	vector<int> nums;

	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}

	cout << nums[500] << endl;
}

void Test2_List()
{
	list<int> nums;

	nums.push_back(3);
	nums.push_front(2);
	nums.push_back(1);

	for (const auto& num : nums)
	{
		cout << num << " ";
	}
}

void VectorExample()
{
	vector<int> nums;

	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}

	cout << "������ ������ ���� �ð�" << endl;
	cout << nums[900] << endl;

	// erase�Լ��� n�� ����ϴ� �Լ�
}

void ListExample()
{
	list<int> nums;

	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}

	cout << "������ ������ ���� �ð�" << endl;
	auto it = next(nums.begin(), 900);
	cout << *it << endl;

	// erase�Լ��� n�� ����ϴ� �Լ�
}

int main()
{
	//Test1_Vector();
	//Test2_List();

	//TimeCheckTest1();
	//TimeCheckTest2();

	//Test();

	// ConsoleUtil::TimeCheck(); �����ϱ�.
	ConsoleUtil::TimeCheck(VectorExample);
	ConsoleUtil::TimeCheck(ListExample);

	// double ��ȯ
}