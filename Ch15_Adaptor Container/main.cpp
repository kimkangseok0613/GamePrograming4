// adapt container
// (Vector, List, Deque) 만들어진 특별한 컨테이너.
// 
// stack, queue, priority_queue
// 스택, 큐, 우선순위 큐

#include <iostream>

using namespace std;

#pragma region 스택
// 메모리 구조 LIFO이다. Last in First out
// 데이터를 사용하는 규칙을 제한하는 것으로 효율을 얻는 자료구조입니다.
// Iterator 지원하지 않는다. (내부적으로 Iterator 클래스 없다.)
// Ctrl + Z (History - 특정 위치로 돌아갈 수 있다.)
//
#include <stack>

void Test1()
{
	cout << "스택 사용 예시" << endl;

	stack<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);
	}

	cout << "nums의 데이터 출력" << endl;
	// Literator를 지원하지 않기 때문에 범위 기반 loop를 사용할 수 없다.

	while (!nums.empty())
	{
		cout << nums.top() << " ";	// top 제일 위에 데이터를 출력하라.
		nums.pop();					// top의 데이터를 삭제하라.
	}
	// size() = nums의 최대값을 반환

	//for (int i = 0; i < nums.size(); i++)
	//{
	//	cout << nums.top() << " ";
	//	nums.pop();
	//}
}
#pragma endregion

#pragma region 큐
// 메모리 구조 FIFO이다. First in First out
//
#include <queue>
void Test2()
{
	cout << "\n\n큐 사용 예시" << endl;

	queue<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);
	}

	cout << "nums의 데이터 출력" << endl;
	// Literator를 지원하지 않기 때문에 범위 기반 loop를 사용할 수 없다.

	while (!nums.empty())
	{
		cout << nums.front() << " ";	// top 제일 위에 데이터를 출력하라.
		nums.pop();					// top의 데이터를 삭제하라.
	}
	// size() = nums의 최대값을 반환

	//for (int i = 0; i < nums.size(); i++)
	//{
	//	cout << nums.top() << " ";
	//	nums.pop();
	//}
}
#pragma endregion

#pragma region 우선순위 큐
// 큐 : 들어온 순서대로 나간다.(x) 먼저 나가야할 사람이 빨리 나간다.
// 사람. 일반 초대권, 특별 초대권
// 시간, 돈
// 다 똑같은 시간에 왔을 때.
//
// #include <queue> 포함되어 있다.
// heap 알고리즘으로 구현되어 있습니다. 가장 작은(큰) 값을 트리 구조의 맨 위로 보내는 형태.
// heapify
//

void Test3()
{
	cout << "\n\n우선순위 큐 사용 예시" << endl;

	priority_queue<int> nums;

	nums.push(0);
	nums.push(5);
	nums.push(7);
	nums.push(3);
	nums.push(9);

	cout << "nums의 데이터 출력" << endl;
	// Literator를 지원하지 않기 때문에 범위 기반 loop를 사용할 수 없다.

	while (!nums.empty())
	{
		cout << nums.top() << " ";	// top 제일 위에 데이터를 출력하라.
		nums.pop();					// top의 데이터를 삭제하라.
	}
	// size() = nums의 최대값을 반환

	//for (int i = 0; i < nums.size(); i++)
	//{
	//	cout << nums.top() << " ";
	//	nums.pop();
	//}
}
#pragma endregion

#include <vector>
#include <deque>

template <typename  T>
class MyDuque
{
private:
	int _size;
	deque<T> data;	

public:
	MyDuque() : _size(0) {}

	void push(T& e)
	{
		_size++;
		data.push_back(e);
	}
	T front()
	{
		return data[0];
	}
	void pop()
	{
		_size--;
		data.pop_front();
	}
	void size()
	{
		return _size;
	}
	bool empty()
	{
		return _size == 0;
	}
};

// vector로 만들어보세요.
template <typename T>
class MyStack
{
private:
	int _size;
	vector<T> data;
public:
	MyStack() : _size(0) {}

	void push(T& e)
	{
		_size++;
		data.push_back(e);
	}
	T top()
	{
		return data[data.size()];
	}
	void pop()
	{
		_size--;
		data.pop_back();
	}
	int size()
	{
		return _size;
	}
	bool empty()
	{
		return _size == 0;
	}
};

void Test4()
{
	// queue가 어떻게 만들어질까?
	// vector 이용해서 queue 만드는 방법

	cout << "\n\n직접 만든 큐 사용 예시" << endl;

	queue<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);
	}

	cout << "nums의 데이터 출력" << endl;
	// Literator를 지원하지 않기 때문에 범위 기반 loop를 사용할 수 없다.

	while (!nums.empty())
	{
		cout << nums.front() << " ";	// top 제일 위에 데이터를 출력하라.
		nums.pop();					// top의 데이터를 삭제하라.
	}
	// size() = nums의 최대값을 반환

	//for (int i = 0; i < nums.size(); i++)
	//{
	//	cout << nums.top() << " ";
	//	nums.pop();
	//}
}

void Test5()
{
	cout << "\n\n직접 만든 스택 사용 예시" << endl;

	queue<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);
	}

	cout << "nums의 데이터 출력" << endl;
	// Literator를 지원하지 않기 때문에 범위 기반 loop를 사용할 수 없다.

	while (!nums.empty())
	{
		cout << nums.front() << " ";	// top 제일 위에 데이터를 출력하라.
		nums.pop();					// top의 데이터를 삭제하라.
	}
	// size() = nums의 최대값을 반환

	//for (int i = 0; i < nums.size(); i++)
	//{
	//	cout << nums.top() << " ";
	//	nums.pop();
	//}
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	Test5();
}