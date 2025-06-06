#pragma once

#include <random>
#include "Windows.h"


class ConsoleUtil
{
public:
	static void GotoXY(int x, int y)
	{
		COORD pos = { static_cast<short>(x), static_cast<short>(y) };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	static int GetRandomInt(int max)
	{
		static std::random_device rd; // 시드 생성기
		static std::mt19937 gen(rd()); // Mersenne Twister 엔진
		std::uniform_int_distribution<> dist(1, max); // 1부터 max까지의 균일한 정수 분포
		return dist(gen); // 랜
	}

	static void SetCursorVisible(bool visible)
	{
		CONSOLE_CURSOR_INFO	 c = { 0 };
		c.dwSize = 1;
		c.bVisible = visible;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &c);
	}

};