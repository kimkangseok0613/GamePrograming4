// 
// 자료구조 (Data Structure)
// 
// Data		 : 게임에 등장하는 정보를 컴퓨터가 해석할 수 있도록 작성한 것.
// Structure : 구조, 설계 - 생산성, 안전성
// 
// 데이터를 설계해야 하는 이유?
// STL ( Standard Template Library)
// 표준		 : 신용할 수 있다. 대중적으로 많이 사용한다.
// 템플릿	 : 일반화 프로그래밍을 구현하기 위한 문법
// 라이브러리 : 만들어진 함수, 클래스,
// 
// 컨테이너	: 특정한 목적에 따라 모아놓은 객체
// 알고리즘	: 컨테이너 안에 있는 데이터를 사용하는 함수 라이브러리
// 반복자	: 알고리즘 코드를 용이하게 사용하기 위한 문법
// 
// vector, list, stack, queue, priority queue, hash-set, map
// 어떤 경우에 무엇을 사용해야 하는가?
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "Template.h"
#include "Sample.h"

int main()
{
	cout << "자료 구조 예제" << endl;

	std::vector<int> nums = { 1,5,3,10,2,4 }; // 정수형 데이터를 3개 저장하고 있는 'nums' vector

	// 데이터 출력1. 1,5,3

	cout << "데이터 출력1" << endl;

	for (auto& num : nums) // 'nums' 안에 들어있는 데이터 타입 개별요소들 모두를 실행하라/
	{
		cout << num << " ";
	}
	cout << endl;

	std::sort(nums.begin(), nums.end()); // 데이터를 정렬한다

	// 데이터 출력2. 1,3,5

	cout << "데이터 출력2" << endl;

	for (auto& num : nums) // 'nums' 안에 들어있는 데이터 타입 개별요소들 모두를 실행하라/
	{
		cout << num << " ";
	}
	cout << endl;

	cout << "템플릿 예제" << endl;

	// 타입 유추

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