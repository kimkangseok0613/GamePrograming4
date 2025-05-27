#pragma once

#include "ConsoleUtility.h"
#include <iostream>

using namespace std;

// 복습. 계산기 기능. 함수 포인터로 표현하기.

#pragma region (심화1) 함수 포인터에 일반화 프로그래밍(Generic Programing) 적용

template<typename T>
void Plus(T a, T b)
{
	cout << "더하기 결과 : ";
	cout << a + b << endl;
}

template<typename T>
void Minus(T a, T b)
{
	cout << "빼기 결과 : ";
	cout << a - b << endl;
}

template <typename T>
void Multiply(T a, T b)
{
	cout << "곱하기 결과 :";
	cout << a * b << endl;
}

template <typename T>
void Divide(T a, T b)
{
	if (b == 0)
	{
		return;
	}

	cout << "나누기 결과 :";
	cout << a / b << endl;
}

template <typename T>
void Calculate(void (*FunC)(T a, T b),T outA, T outB)
{
	FunC(outA, outB);
}

#pragma endregion

#pragma region (심화2) 열거형과 클래스로 함수포인터 활용

// 열겨형의 이름은 항상 대문자로 작성해서, 이름으로 타입을 알아볼 수 있게 설정하였다.
// 함수는 첫글자가 대문자로 표현하게 설정하였다.
enum ActorAction
{
	MOVE, TALK
};

class Actor
{
private:
	static void Move()
	{
		cout << "움직입니다." << endl;
	}

	static void Talk()
	{
		cout << "대화합니다." << endl;
	}
public:
	Actor() = default;
	void (*Action)();

	void Think()
	{

		// 랜덤한 숫자를 받아서 0이 나오면 움직여라, 1이 나오면 Talk, 2가 나오면..
		int select = ConsoleUtil::GetRandomInt(2);	// 1, 2가 나오기 때문에 -1을 해준다.

		ActorAction a_action = static_cast<ActorAction>(select-1);

		switch (a_action)
		{
		case MOVE: Action = Move; 
			break;
		case TALK: Action = Talk; 
			break;
		default: cout << "잘못된 입력을 받아왔습니다." << endl; 
			return;
		}
	}
};

#pragma endregion

#pragma region 가위바위보 예제 만들기

enum RSP_TYPE
{
	ROCK, SCISSORS, PAPER
};

// 함수 포인터 선언.
// switch(RSP_TYPE) 각 타입에 맞게 함수 포인터의 함수를 넣는 코드를 만들어보세요.
class RSPgame
{
private:
	static void Rock()
	{
		cout << "주먹!" << endl;
	}
	static void Scissors()
	{
		cout << "가위!" << endl;
	}
	static void Paper()
	{
		cout << "보!" << endl;
	}

	RSP_TYPE computertype;
	RSP_TYPE usertype;

	int userScore;
	int computerScore;

	void Result()
	{
		if (usertype == computertype)
		{
			cout << "비겼다." << endl;
		}
		else if (usertype == ROCK && computertype == SCISSORS || usertype == SCISSORS && computertype == PAPER || usertype == PAPER && computertype == ROCK)
		{
			cout << "이겼다" << endl;
			userScore++;
		}
		else
		{
			cout << "졌다." << endl;

		}
	}

public:
	void (*Choose)();
	RSPgame() : userScore(0), computerScore(0) {}

	void StartGame()
	{
		while (true)
		{
			cout << "0.주먹 1.가위 2. 보" << endl;
			cout << "선택해주세요." << endl;
			int input;
			cin >> input;
			usertype = static_cast<RSP_TYPE>(input);
			int select = ConsoleUtil::GetRandomInt(3);

			computertype = static_cast<RSP_TYPE>(select - 1);

			switch (computertype)
			{
			case ROCK:Choose = Rock;
				break;
			case SCISSORS:Choose = Scissors;
				break;
			case PAPER:Choose = Paper;
				break;
			default: cout << "잘못된 입력을 받아왔습니다." << endl;
				return;
			}
			cout << "컴퓨터가 선택한 행동 : ";
			Choose();
			Result();
			cout << "플레이어의 점수 : " << userScore << endl << "컴퓨터의 점수 : " << computerScore << endl;
			cout << endl;

			if (userScore >= 3 || computerScore >= 3)
			{
				break;
			}
		}
		if (userScore >= 3)
		{
			cout << "유저의 승리입니다." << endl;
		}
	}
};

#pragma endregion



void FPTest1()
{
	Calculate(Plus, 5, 6);			// 11
	Calculate(Plus, 5.5, 6.5);		// 12
	Calculate(Minus, 6.9, 5.7);		// 1.2
	Calculate(Multiply, 6.9, 5.7);	// 39.33
	Calculate(Divide, 6.9, 5.7);	// 1.21053
}

void FPTest2()
{
	Actor actor;
	// actor.의사결정을 한다. Think
	//actor.ActionTalk();
	actor.Think();
	actor.Action();
}

void RSPGame()
{
	RSPgame rspGame;
	rspGame.StartGame();
	//rspGame.Choose();
}

