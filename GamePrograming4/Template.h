#pragma once

#include <iostream>

// 더하기 함수

// 함수 오버로딩, 실수

// a:코인 현재 보유 코인 b:추가된 코인
// 0.5 코인이 생겼다.
// 일반화된 코드로 만들면 유지 보수, 가독성에 좋지 않을까? 
//

template<typename T>

T Add(T a, T b) // int : 정수값만 더해준다.
{
	return a + b;
}