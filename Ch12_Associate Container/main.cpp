// 연관 컨테이너 : (multi, unordered) set, map

#include <set>
#include <map>
#include <algorithm>

#include <iostream>
#include <iomanip>
#include <utility>

using namespace std;

// set을 사용했을 때 무슨일이 발생하는가?
#pragma region 연관 컨테이너 사용하기

void Test1()
{
	cout << "Set" << endl;

	set<int> nums;
	
	// 데이터를 어떻게 저장할 수 있나요? push
	// 연관 컨테이너? insert
	// 연관 컨테이너에 데이터를 입력하면 자동으로 정렬이 된다.
	// 탐색을 할때 정렬된 결과로 사용하면 효과적이다.
	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7); // {1,5,2,7,} -> {1,2,5,7} 정렬된다.

	cout << "특징1. Set의 데이터가 자동으로 정렬됨" << endl;
	for (const auto& num : nums)
	{
		cout << num << " ";
	}
	cout << endl;

	// set의 특징. 중복이 안된다.

	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7); // {1,1,2,2,5,5,7,7}

	cout << "특징2. Set의 데이터는 중복이 안된다." << endl;
	for (const auto& num : nums)
	{
		cout << num << " ";
	}
	cout << endl;
}

void Test2()
{
	cout << "Multi set" << endl;

	multiset<int> nums;

	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7); // {1,5,2,7,} -> {1,2,5,7} 정렬된다.

	cout << "특징1. Multiset의 데이터가 자동으로 정렬됨" << endl;
	for (const auto& num : nums)
	{
		cout << num << " ";
	}
	cout << endl;

	// set의 특징. 중복이 안된다.

	nums.insert(1);
	nums.insert(5);
	nums.insert(2);
	nums.insert(7); // {1,1,2,2,5,5,7,7}

	cout << "특징2. Multiset의 데이터는 중복이 안된다." << endl;
	for (const auto& num : nums)
	{
		cout << num << " ";
	}
	cout << endl;
}

#pragma endregion

#pragma region 커스텀 클래스를 set에 넣는 방법

struct Item
{
	int id;
	string name;

	Item() = default;
	Item(int id, string name) : id(id), name(name) {}

	bool operator < (const Item& other) const
	{
		return id < other.id; // 1,2,3...
							  // ㄱ,ㄴ,ㄷ...
	}
};

void Test3()
{
	cout << "커스텀 객체를 Set으로 출력하기" << endl;

	set<Item> items;

	Item item1(1,"유리");
	Item item2(2,"김");
	Item item3(3,"바나나");
	Item item4(100,"칼");
	Item item5(50,"방패");

	items.insert(item1);
	items.insert(item2);
	items.insert(item3);
	items.insert(item4);
	items.insert(item5);

	cout << "중복을 허용 안함" << endl;
	items.insert(Item(3, "투구")); // -> 3이 이미 있어서 출력안됨. name 출력은 나옴.

	for (const auto& item : items)
	{
		cout << item.id << " " << item.name << endl;
	}

	cout << "Set을 사용하면 데이터의 크기에 따라 자동으로 정렬한 결과를 얻을 수 있다." << endl;
	cout << "find 함수를 사용해서 빠르게 데이터를 찾을 수 있다." << endl;

	// item 전체를 items 안에서 찾아야한다.
	// item의 id가 n번인 데이터를 찾고싶다.
	// map을 사용하면 위의 문제점을 쉽게 해결할 수 있다.
}

#pragma endregion

#pragma region map 사용하기

void Test4()
{
	cout << "map 자료구조 사용하기" << endl;

	map<int, Item> items;

	// map에 데이터를 넣는 방법, pair클래스를 선언하는 방법 (1) 중괄호로 사용

	items.insert({ 0,Item(100,"포션") });

	// (2) make_pair함수 사용하기
	items.insert(make_pair(10, Item(1000, "롱소드")));

	// (3) pair클래스를 직접 선언하기. (헤더가 필요 utility)
	pair<int, Item> p1(5, Item(101, "빨간 포션"));

	items.insert(p1);

	cout << "특징1. map은 pair로 이루어진 데이터를 저장하는 컨테이너이다." << endl;
	cout << "특징2. map의 key값으로 자동 정렬이 이루어집니다." << endl;

	for (const auto& item : items)
	{
		cout << item.first << " " << "ID: " << item.second.id << " NAME :" << item.second.name << endl;
	}

	cout << "특징3. 사전(Dictionary)형 자료구조입니다." << endl;

	cout << items[0].id << items[0].name << endl; // items[0] => Item(100,"포션")
}

#pragma endregion


// set으로 데이터를 정렬했을 때의 불편한 점, 그것을 개선한 map
// pair를 정의를 해야한다.

int main()
{
	//Test1();
	//Test2();
	//Test3();
	Test4();
}