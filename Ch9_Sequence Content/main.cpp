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

// 목표) vector와 list의 차이점을 직접 비교해보세요.
// 
// 1. vector push_back 추가, list push_back 추가한 시간을 비교해보세요.: 결과 < > 누가 더 빨랐다. 그 이유?
// 2. 임의의 데이터에 접근하는데 걸리는 시간	: 결과 vector가 더 빠르다. list 개수가 많을수록 더 시간이 걸린다.
// 3. 임의의 데이터를 지우는데 걸리는 시간		: list가 더 빠르다.
// 
//	데이터가 삭제는 적은데, 접근은 많은 경우	: vector 유리
//	데이터의 삭제가 빈번한 경우				: list 유리
// 
// (★★★★★)데이터 삭제도 많고 접근도 많은 경우 : ?? unordered.map
// 
// vector
// unordered.map
//

// vector, list 크게 차이점이 없다.
// vector [ ] 인덱스로 데이터를 출력할 수 있다.
// list [ ] 인덱스로 접근할 수 없다.	// 배열이 아니면 어떻게 자료를 표현할 수 있을까?
// 
// 차이점을 눈으로 확인하기 위해서 환경 설정을 진행한다.
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

	cout << "임의의 데이터 접근 시간" << endl;
	cout << nums[900] << endl;

	// erase함수를 n번 사용하는 함수
}

void ListExample()
{
	list<int> nums;

	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(i);
	}

	cout << "임의의 데이터 접근 시간" << endl;
	auto it = next(nums.begin(), 900);
	cout << *it << endl;

	// erase함수를 n번 사용하는 함수
}

int main()
{
	//Test1_Vector();
	//Test2_List();

	//TimeCheckTest1();
	//TimeCheckTest2();

	//Test();

	// ConsoleUtil::TimeCheck(); 실행하기.
	ConsoleUtil::TimeCheck(VectorExample);
	ConsoleUtil::TimeCheck(ListExample);

	// double 반환
}