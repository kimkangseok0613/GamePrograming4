#pragma once

#include <iostream>
#include <chrono> // clock ����� ����ִ� ���
#include <vector>
#include <list>

using namespace std;

// vector�� list�� ������
// 
// 1. ������ �����Ϳ� �����ϴ� �ð��� ���Ѵ�.
// 
// ���	vector�� �ٷ� ������ �����Ϳ� ������ �� �ִ�. ������.			(0(1))
//		list�� n��° �����Ϳ� �����ϴµ� ���̿� ����ؼ� �ð��� �ɸ���.	(linear Time 0(n))
// 
// 2. ù��°�� ���� �����Ͱ� �ƴ� �����͸� ���� �Ǵ� �����ϴµ� �ɸ��� �ð�
// - �����͸� ���� ���� �Ǵ� �����ϴ� ��쿡 vector�� �ð��� ��ȿ�����̴�.
// - 1 ~ N ������ - > 1 ~ N - 1�� ������ �ű�� �۾�.
// 
// �����͸� ����ų�, �����ϴ� �۾��� ������ �������� vector�� �ð��� ��ȿ�����̴�.
// 
// (����) ��� �ڷᱸ���� ������� �� �𸣰����� vector�� ��������.
// vector ������ ������ �ð��� �� �����ɸ���?
//


void TimeCheckTest1()
{
	cout << "Ư�� ����� �󸶳� �ð��� �ɸ����� Ū���ϴ� �ڵ��Դϴ�." << endl;

	auto Start = chrono::high_resolution_clock::now();

	//
	vector<int> nums;
	for (int i = 0; i < 1000000; i++)
	{
		nums.push_back(i);
	}

	for (int i=0; i<1000; i++)
	{
		auto it = nums.begin() + 500;
		nums.erase(it);
	}
	//

	auto End = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = End - Start;

	cout << duration.count() << "ms" << endl;
}

void TimeCheckTest2()
{
	cout << "STL list �Լ��� �ð��� �����մϴ�." << endl;

	auto Start = chrono::high_resolution_clock::now();

	//
	list<int> nums;
	for (int i = 0; i < 1000000; i++)
	{
		nums.push_back(i);
	}

	for (int i = 0; i < 1000; i++)
	{
		auto it = next(nums.begin(), 500);
		nums.erase(it);
	}
	//

	auto End = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = End - Start;

	cout << duration.count() << "ms" << endl;
}