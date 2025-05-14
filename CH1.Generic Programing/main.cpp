//
// �ڷ� ����
// - �Ϲ�ȭ ���α׷��� (Generic Programing)
// - �Ϲ����̴�? : � Ÿ���̵� ��� ����� �� �ִ� �������� �ڵ�
// 
// �������� T,N,Q ������ ���ε�, ��ǻ�Ͱ� ��� �������� �� �� �ֵ��� Ű���带 ����ؾ� �Ѵ�.
// 
// ���ſ��� ��� �Ϲ�ȭ ���α׷����� ������?
// - macro�� �Ϲ�ȭ ���α׷����� �ۼ��ϴ� ���� �����մϴ�.
// - ������ üũ�� �������� �ʴ´�.
// 
// Legacy �ڵ带 �а�, ���� �ڵ������� ������ �� �ִ°�.
// ����1. �ǵ����� ���� ����� �߻��� �� �ִ�.
// ����2. ������ üũ�� �������� �ʴ´�.
// 
// ������ Ÿ��(compile time)	: ������ �ϴ� ����. ��ǻ�Ͱ� �� �����ؼ� �����ϴ� ����. ������ �����ϴ� �ܰ踦 ��ģ��.
// ��Ÿ��(run time)			: ���α׷��� �����ϴ� ����.
// 
// template Ű����
// <Type���� ������ �̸�>
// Ÿ�� ��ü�� �޾ƿ��� Ű���� : typename, class
// 
// Ÿ�� �߷� : �����Ϸ� �� �� �ڵ带 ����, ��õ��� ���� Ÿ���� �����ϴ� ��
// 
// auto �̸� = 10;
// 
// ������ �Լ� ���� template Ű���带 ����Ͽ� �Ϲ�ȭ �Լ�.
// �Լ�  template
// 
// Ŭ���� ���� template< > ����Ͽ� �Ϲ�ȭ Ŭ����.
// 
//

#include <iostream>
#include <array> // #include < �����̳� �̸� >

#define Max( a, b ) ( (a > b) ? a : b )
#define Square( a ) a * a 

using namespace std;

template<typename T1>

T1 Maximum(T1 a, T1 b)
{
	return (a > b) ? a : b;
}

template<typename T1, typename T2>
void FunC(T1 a, T2 b)
{
	cout <<"No." << a << " " << b << endl;
}

template<int N>
void FunC2()
{
	cout<< N << endl;
}

template<int N, typename T>
T FunC3()
{
	for (int i = 0; i < N; i++)
	{
		cout << typeid(T).name() << endl;
	}
}

// 
// Min �Լ�.
// 
// Multiply
//

template<class T>
T Min(T a, T b)
{
	return ( a < b ) ? a : b;
}

template<class T>
T Multiply(T a, T b)
{
	return a * b;
}

struct person
{
	int age;
	string name;

	bool operator<(const person& other)
	{
		return this->age < other.age;
	}
};

// int sums[10]; sums[0]
// 
// �츮�� ���� ���� personŬ������ �����ϴ� ��ü�� �������.
// person�� �����ϴ� �Լ����� ������ �ڵ��.
// ���������� �ٷ�� Ŭ������.
// Standard Template Library STL
//

// �迭�� �䳻�� Ŭ����
template<int N>
class People // 
{
	int size = N;			// N�� ũ�⸦ �Ϲ�ȭ�ϰ� �ʹ�.
	person HumanInCity[N];	//

	// ������ �����ε��� ���ؼ� �迭 ����� �䳻������.

	person& operator[](int index)
	{
		return HumanInCity[index];
	}

	void at(int index)
	{
		cout << "���� : " << HumanInCity[index].age << "�̸� : " << HumanInCity[index].name << endl;
	}
};

struct Pocketmon
{
private:

public:

};

template<int N, typename T>
class Array
{
private:
	int size = N;
	T value[N];
public:
	T& operator[](int index)
	{
		return value[index];
	}

	T at(int index)
	{
		return value[index];
	}
};

// 
// �ڷ� �������� �����ؾ��� ��
// ������ ����.
// ������ ����. '�迭' - ũ�Ⱑ �����Ǿ� �ִ� �����̳�
// �����̳ʸ��� ������� �ִ�.
// 
// �迭�� ������ ����
// Ư¡ : ũ�Ⱑ �����Ǿ� �ִ�.
// ���� : �������ִ� ��Ģ�� ���������� ������ �� �ִ�. ������.
// ���� : �迭�� ũ�⸦ ������ �� ��� ����� ũ��. ��Ƽ 4��, ���̵� 8��
// ��ų. 4�� QWER
// 
// ũ�⸦ ������ų �� ����? ������ų �� �ִ�.
// 
// ���ϸ� 1000�� �迭
// 
// 1200�� �迭�� �ٽ� �����. -> 1000�� �迭�� 1200�� �迭�� �ű��. -> 1000�� �迭�� �����Ѵ�.
//

void Ex1()
{
	int result1 = Max(5, 1); // ( ( 5 > 1 ) ? 5 : 1 )
	double result2 = Max(1.1, 2.2); // ( ( 1.1 > 2.2 ) ? )
	int result3 = 100 / Square(5); // 100 / 5 * 5

	cout << result1 << endl;
	cout << result2 << endl;
	cout << result3 << endl;

	cout << Maximum<int>(10, 20) << endl;
	cout << Maximum<double>(0.1, 0.2) << endl;

	// Ÿ�� �߷� : �Ϻ��ϰ� �۵������� �ʴ´�.
	cout << Maximum(1.2, 2.4) << endl;
	cout << Maximum(0.1, 0.2) << endl;

	FunC<int, string>(1, "��ī��");

	FunC2<155>();

	FunC3<5, int>;

	// Min Template ����, Multiply Template ����
	cout << "Min ����" << endl;
	cout << Min(1.1, 2.4) << endl;
	cout << Min(1, 2) << endl;
	cout << Min('a', 'b') << endl;

	cout << "Multiply ����" << endl;
	cout << Multiply(1, 5) << endl;
	cout << Multiply(1.1, 2.2) << endl;
}

int main()
{
	//Ex1(); // �Լ� ���ø� ����

	// ���� ����
	person p1{ 30, "A" };
	person p2{ 20, "B" };

	person p3 = Min<person>(p1, p2);
	cout << p3.name << " ���̰� �� ���." << endl;

	People<5> busan;
	busan[0] = { 15,"�̼���" };
	busan.at(0);
	busan[1] = { 20,"������" };
	busan.at(1);

	cout << "���� ���� �迭 Ŭ���� ����" << endl;

	Array<10, person> seoul;
	seoul[0] = { 13,"�庸��" };
	seoul.at(1) = { 15,"���ָ�" };

	// �迭 ������ ����(syntax)
	cout << seoul[0].name << endl;
	cout << seoul[1].name << endl;

	// �迭 Ŭ���� ������ ����
	cout << seoul.at(0).name << endl;
	cout << seoul.at(1).name << endl;

	Array<10, Pocketmon> myPocketmon;
	myPocketmon[0] = { 1,"�̻��ؾ�" };
	cout << myPocketmon.at(0).name << endl;

	//myPocketmon[11]; // out of range

	// STL�� ��ϵǾ� �ִ� �迭 Ŭ������ ����ϼ���.

	array<Pocketmon, 10> MPocketmon;
	MPocketmon[0] = { 1,"�̻��ؾ�" };
	MPocketmon.at(1) = {25,"��ī��"};
	cout << "No." << MPocketmon.at(0).name << endl;
	cout << "No." << MPocketmon.at(1).name << endl;
}