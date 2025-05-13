// 
// �ڷᱸ�� (Data Structure)
// 
// Data		 : ���ӿ� �����ϴ� ������ ��ǻ�Ͱ� �ؼ��� �� �ֵ��� �ۼ��� ��.
// Structure : ����, ���� - ���꼺, ������
// 
// �����͸� �����ؾ� �ϴ� ����?
// STL ( Standard Template Library)
// ǥ��		 : �ſ��� �� �ִ�. ���������� ���� ����Ѵ�.
// ���ø�	 : �Ϲ�ȭ ���α׷����� �����ϱ� ���� ����
// ���̺귯�� : ������� �Լ�, Ŭ����,
// 
// �����̳�	: Ư���� ������ ���� ��Ƴ��� ��ü
// �˰���	: �����̳� �ȿ� �ִ� �����͸� ����ϴ� �Լ� ���̺귯��
// �ݺ���	: �˰��� �ڵ带 �����ϰ� ����ϱ� ���� ����
// 
// vector, list, stack, queue, priority queue, hash-set, map
// � ��쿡 ������ ����ؾ� �ϴ°�?
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "Template.h"
#include "Sample.h"

int main()
{
	cout << "�ڷ� ���� ����" << endl;

	std::vector<int> nums = { 1,5,3,10,2,4 }; // ������ �����͸� 3�� �����ϰ� �ִ� 'nums' vector

	// ������ ���1. 1,5,3

	cout << "������ ���1" << endl;

	for (auto& num : nums) // 'nums' �ȿ� ����ִ� ������ Ÿ�� ������ҵ� ��θ� �����϶�/
	{
		cout << num << " ";
	}
	cout << endl;

	std::sort(nums.begin(), nums.end()); // �����͸� �����Ѵ�

	// ������ ���2. 1,3,5

	cout << "������ ���2" << endl;

	for (auto& num : nums) // 'nums' �ȿ� ����ִ� ������ Ÿ�� ������ҵ� ��θ� �����϶�/
	{
		cout << num << " ";
	}
	cout << endl;

	cout << "���ø� ����" << endl;

	// Ÿ�� ����

	int num = Add<int>(2, 5);
	cout << num << endl;

	int num1 = Add(1, 4);
	cout << num1 << endl; // num1 = 5
	double num2 = Add(1.5, 4.5);
	cout << num2 << endl; // num2 = 6
	int num3 = Add('b', 'a');
	cout << num3 << endl;

	Example1();
}