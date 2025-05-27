#pragma once

#include <iostream>
using namespace std;

// 1단계 : 함수 선언 ( (반환값)(*호출할 함수 이름) ( ) )
// 2단계 : 호출한 함수의 인자가 있는 경우 ( (반환값)(*호출할 함수 이름) (타입이름, 타입이름), 타입이름, 타입이름 )
//

void Add(int a, int b)
{
	cout << "덧셈 실행" << endl;
	cout << a + b << endl;
}

void Minus(int a, int b)
{
	cout << "뺄셈 실행" << endl;
	cout << a - b << endl;
}

void Times(int a, int b)
{
	cout << "곱셈 실행" << endl;
	cout << a * b << endl;
}

void Division(int a, int b)
{
	if (b == 0)
	{
		return;
	}

	cout << "나눗셈 실행" << endl;
	cout << a / b << endl;
}

void Calculate(void (*FunC)(int a, int b),int a, int b)
{
	FunC(a,b);
}

void Test()
{
	Calculate(Add,150,50);		// 200	덧셈
	Calculate(Minus,150,50);	// 100	뺄셈
	Calculate(Times,150,50);	// 7500	곱셈
	Calculate(Division,150,50);	// 3	나눗셈
}