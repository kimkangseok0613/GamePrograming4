#pragma once

#include <iostream>
using namespace std;

// 1�ܰ� : �Լ� ���� ( (��ȯ��)(*ȣ���� �Լ� �̸�) ( ) )
// 2�ܰ� : ȣ���� �Լ��� ���ڰ� �ִ� ��� ( (��ȯ��)(*ȣ���� �Լ� �̸�) (Ÿ���̸�, Ÿ���̸�), Ÿ���̸�, Ÿ���̸� )
//

void Add(int a, int b)
{
	cout << "���� ����" << endl;
	cout << a + b << endl;
}

void Minus(int a, int b)
{
	cout << "���� ����" << endl;
	cout << a - b << endl;
}

void Times(int a, int b)
{
	cout << "���� ����" << endl;
	cout << a * b << endl;
}

void Division(int a, int b)
{
	if (b == 0)
	{
		return;
	}

	cout << "������ ����" << endl;
	cout << a / b << endl;
}

void Calculate(void (*FunC)(int a, int b),int a, int b)
{
	FunC(a,b);
}

void Test()
{
	Calculate(Add,150,50);		// 200	����
	Calculate(Minus,150,50);	// 100	����
	Calculate(Times,150,50);	// 7500	����
	Calculate(Division,150,50);	// 3	������
}