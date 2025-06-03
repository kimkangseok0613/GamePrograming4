// adapt container
// (Vector, List, Deque) ������� Ư���� �����̳�.
// 
// stack, queue, priority_queue
// ����, ť, �켱���� ť

#include <iostream>

using namespace std;

#pragma region ����
// �޸� ���� LIFO�̴�. Last in First out
// �����͸� ����ϴ� ��Ģ�� �����ϴ� ������ ȿ���� ��� �ڷᱸ���Դϴ�.
// Iterator �������� �ʴ´�. (���������� Iterator Ŭ���� ����.)
// Ctrl + Z (History - Ư�� ��ġ�� ���ư� �� �ִ�.)
//
#include <stack>

void Test1()
{
	cout << "���� ��� ����" << endl;

	stack<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);
	}

	cout << "nums�� ������ ���" << endl;
	// Literator�� �������� �ʱ� ������ ���� ��� loop�� ����� �� ����.

	while (!nums.empty())
	{
		cout << nums.top() << " ";	// top ���� ���� �����͸� ����϶�.
		nums.pop();					// top�� �����͸� �����϶�.
	}
	// size() = nums�� �ִ밪�� ��ȯ

	//for (int i = 0; i < nums.size(); i++)
	//{
	//	cout << nums.top() << " ";
	//	nums.pop();
	//}
}
#pragma endregion

#pragma region ť
// �޸� ���� FIFO�̴�. First in First out
//
#include <queue>
void Test2()
{
	cout << "\n\nť ��� ����" << endl;

	queue<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);
	}

	cout << "nums�� ������ ���" << endl;
	// Literator�� �������� �ʱ� ������ ���� ��� loop�� ����� �� ����.

	while (!nums.empty())
	{
		cout << nums.front() << " ";	// top ���� ���� �����͸� ����϶�.
		nums.pop();					// top�� �����͸� �����϶�.
	}
	// size() = nums�� �ִ밪�� ��ȯ

	//for (int i = 0; i < nums.size(); i++)
	//{
	//	cout << nums.top() << " ";
	//	nums.pop();
	//}
}
#pragma endregion

#pragma region �켱���� ť
// ť : ���� ������� ������.(x) ���� �������� ����� ���� ������.
// ���. �Ϲ� �ʴ��, Ư�� �ʴ��
// �ð�, ��
// �� �Ȱ��� �ð��� ���� ��.
//
// #include <queue> ���ԵǾ� �ִ�.
// heap �˰������� �����Ǿ� �ֽ��ϴ�. ���� ����(ū) ���� Ʈ�� ������ �� ���� ������ ����.
// heapify
//

void Test3()
{
	cout << "\n\n�켱���� ť ��� ����" << endl;

	priority_queue<int> nums;

	nums.push(0);
	nums.push(5);
	nums.push(7);
	nums.push(3);
	nums.push(9);

	cout << "nums�� ������ ���" << endl;
	// Literator�� �������� �ʱ� ������ ���� ��� loop�� ����� �� ����.

	while (!nums.empty())
	{
		cout << nums.top() << " ";	// top ���� ���� �����͸� ����϶�.
		nums.pop();					// top�� �����͸� �����϶�.
	}
	// size() = nums�� �ִ밪�� ��ȯ

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

// vector�� ��������.
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
	// queue�� ��� ���������?
	// vector �̿��ؼ� queue ����� ���

	cout << "\n\n���� ���� ť ��� ����" << endl;

	queue<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);
	}

	cout << "nums�� ������ ���" << endl;
	// Literator�� �������� �ʱ� ������ ���� ��� loop�� ����� �� ����.

	while (!nums.empty())
	{
		cout << nums.front() << " ";	// top ���� ���� �����͸� ����϶�.
		nums.pop();					// top�� �����͸� �����϶�.
	}
	// size() = nums�� �ִ밪�� ��ȯ

	//for (int i = 0; i < nums.size(); i++)
	//{
	//	cout << nums.top() << " ";
	//	nums.pop();
	//}
}

void Test5()
{
	cout << "\n\n���� ���� ���� ��� ����" << endl;

	queue<int> nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push(i);
	}

	cout << "nums�� ������ ���" << endl;
	// Literator�� �������� �ʱ� ������ ���� ��� loop�� ����� �� ����.

	while (!nums.empty())
	{
		cout << nums.front() << " ";	// top ���� ���� �����͸� ����϶�.
		nums.pop();					// top�� �����͸� �����϶�.
	}
	// size() = nums�� �ִ밪�� ��ȯ

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