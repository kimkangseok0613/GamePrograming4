#pragma once

#include <iostream>
#include <chrono> // clock 기능이 담겨있는 헤더
#include <vector>
#include <list>

using namespace std;

// vector와 list의 차이점
// 
// 1. 임의의 데이터에 접근하는 시간을 비교한다.
// 
// 결과	vector는 바로 임의의 데이터에 접근할 수 있다. 빠르다.			(0(1))
//		list는 n번째 데이터에 접근하는데 길이에 비례해서 시간이 걸린다.	(linear Time 0(n))
// 
// 2. 첫번째와 끝의 데이터가 아닌 데이터를 삭제 또는 수정하는데 걸리는 시간
// - 데이터를 자주 삭제 또는 수정하는 경우에 vector의 시간이 비효율적이다.
// - 1 ~ N 데이터 - > 1 ~ N - 1개 데이터 옮기는 작업.
// 
// 데이터를 지우거나, 변경하는 작업이 많으면 많을수록 vector가 시간이 비효율적이다.
// 
// (번외) 어떠한 자료구조를 써야할지 잘 모르겠으면 vector로 만들어보세요.
// vector 무엇을 했을때 시간이 더 오래걸릴까?
//


void TimeCheckTest1()
{
	cout << "특정 기능이 얼마나 시간이 걸리는지 큭정하는 코드입니다." << endl;

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
	cout << "STL list 함수의 시간을 측정합니다." << endl;

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