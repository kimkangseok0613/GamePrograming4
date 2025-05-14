//
// 자료 구조
// - 일반화 프로그래밍 (Generic Programing)
// - 일반적이다? : 어떤 타입이든 모두 사용할 수 있는 범용적인 코드
// 
// 변수들을 T,N,Q 선언할 것인데, 컴퓨터가 어떠한 형태인지 알 수 있도록 키워드를 사용해야 한다.
// 
// 과거에는 어떻게 일반화 프로그래밍을 했을까?
// - macro로 일반화 프로그래밍을 작성하는 것은 지양합니다.
// - 컴파일 체크를 지원하지 않는다.
// 
// Legacy 코드를 읽고, 옛날 코드인지를 인지할 수 있는것.
// 단점1. 의도하지 않은 결과가 발생할 수 있다.
// 단점2. 컴파일 체크를 지원하지 않는다.
// 
// 컴파일 타임(compile time)	: 컴파일 하는 시점. 컴퓨터가 언어를 번역해서 전달하는 시점. 오류를 검증하는 단계를 거친다.
// 런타임(run time)			: 프로그램이 시작하는 시점.
// 
// template 키워드
// <Type지정 변수의 이름>
// 타입 자체를 받아오는 키워드 : typename, class
// 
// 타입 추론 : 컴파일러 앞 뒤 코드를 보고, 명시되지 않은 타입을 유추하는 것
// 
// auto 이름 = 10;
// 
// 선언한 함수 위에 template 키워드를 사용하여 일반화 함수.
// 함수  template
// 
// 클래스 위에 template< > 사용하여 일반화 클래스.
// 
//

#include <iostream>
#include <array> // #include < 컨테이너 이름 >

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
// Min 함수.
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
// 우리가 직접 만든 person클래스에 접근하는 객체를 만들었다.
// person을 조작하는 함수들을 정의한 코드다.
// 보편적으로 다루는 클래스다.
// Standard Template Library STL
//

// 배열을 흉내낸 클래스
template<int N>
class People // 
{
	int size = N;			// N의 크기를 일반화하고 싶다.
	person HumanInCity[N];	//

	// 연산자 오버로딩을 통해서 배열 기능을 흉내내보기.

	person& operator[](int index)
	{
		return HumanInCity[index];
	}

	void at(int index)
	{
		cout << "나이 : " << HumanInCity[index].age << "이름 : " << HumanInCity[index].name << endl;
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
// 자료 구조에서 공부해야할 것
// 데이터 선언.
// 데이터 저장. '배열' - 크기가 고정되어 있는 컨테이너
// 컨테이너마다 장단점이 있다.
// 
// 배열의 장점과 단점
// 특징 : 크기가 고정되어 있다.
// 장점 : 정해져있는 규칙을 문법적으로 제한할 수 있다. 빠르다.
// 단점 : 배열의 크기를 변경할 때 드는 비용이 크다. 파티 4명, 레이드 8명
// 스킬. 4개 QWER
// 
// 크기를 증가시킬 수 없다? 증가시킬 수 있다.
// 
// 포켓몬 1000개 배열
// 
// 1200개 배열을 다시 만든다. -> 1000개 배열을 1200개 배열로 옮긴다. -> 1000개 배열을 삭제한다.
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

	// 타입 추론 : 완벽하게 작동하지는 않는다.
	cout << Maximum(1.2, 2.4) << endl;
	cout << Maximum(0.1, 0.2) << endl;

	FunC<int, string>(1, "피카츄");

	FunC2<155>();

	FunC3<5, int>;

	// Min Template 예제, Multiply Template 예제
	cout << "Min 예제" << endl;
	cout << Min(1.1, 2.4) << endl;
	cout << Min(1, 2) << endl;
	cout << Min('a', 'b') << endl;

	cout << "Multiply 예제" << endl;
	cout << Multiply(1, 5) << endl;
	cout << Multiply(1.1, 2.2) << endl;
}

int main()
{
	//Ex1(); // 함수 템플릿 예제

	// 보충 예제
	person p1{ 30, "A" };
	person p2{ 20, "B" };

	person p3 = Min<person>(p1, p2);
	cout << p3.name << " 나이가 더 어리다." << endl;

	People<5> busan;
	busan[0] = { 15,"이순신" };
	busan.at(0);
	busan[1] = { 20,"강감찬" };
	busan.at(1);

	cout << "직접 만든 배열 클래스 예제" << endl;

	Array<10, person> seoul;
	seoul[0] = { 13,"장보고" };
	seoul.at(1) = { 15,"고주몽" };

	// 배열 형태의 문법(syntax)
	cout << seoul[0].name << endl;
	cout << seoul[1].name << endl;

	// 배열 클래스 형태의 문법
	cout << seoul.at(0).name << endl;
	cout << seoul.at(1).name << endl;

	Array<10, Pocketmon> myPocketmon;
	myPocketmon[0] = { 1,"이상해씨" };
	cout << myPocketmon.at(0).name << endl;

	//myPocketmon[11]; // out of range

	// STL에 등록되어 있는 배열 클래스를 사용하세요.

	array<Pocketmon, 10> MPocketmon;
	MPocketmon[0] = { 1,"이상해씨" };
	MPocketmon.at(1) = {25,"피카츄"};
	cout << "No." << MPocketmon.at(0).name << endl;
	cout << "No." << MPocketmon.at(1).name << endl;
}