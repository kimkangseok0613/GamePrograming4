#pragma once

#include "ConsoleUtility.h"
#include <iostream>

using namespace std;

// ����. ���� ���. �Լ� �����ͷ� ǥ���ϱ�.

#pragma region (��ȭ1) �Լ� �����Ϳ� �Ϲ�ȭ ���α׷���(Generic Programing) ����

template<typename T>
void Plus(T a, T b)
{
	cout << "���ϱ� ��� : ";
	cout << a + b << endl;
}

template<typename T>
void Minus(T a, T b)
{
	cout << "���� ��� : ";
	cout << a - b << endl;
}

template <typename T>
void Multiply(T a, T b)
{
	cout << "���ϱ� ��� :";
	cout << a * b << endl;
}

template <typename T>
void Divide(T a, T b)
{
	if (b == 0)
	{
		return;
	}

	cout << "������ ��� :";
	cout << a / b << endl;
}

template <typename T>
void Calculate(void (*FunC)(T a, T b),T outA, T outB)
{
	FunC(outA, outB);
}

#pragma endregion

#pragma region (��ȭ2) �������� Ŭ������ �Լ������� Ȱ��

// �������� �̸��� �׻� �빮�ڷ� �ۼ��ؼ�, �̸����� Ÿ���� �˾ƺ� �� �ְ� �����Ͽ���.
// �Լ��� ù���ڰ� �빮�ڷ� ǥ���ϰ� �����Ͽ���.
enum ActorAction
{
	MOVE, TALK
};

class Actor
{
private:
	static void Move()
	{
		cout << "�����Դϴ�." << endl;
	}

	static void Talk()
	{
		cout << "��ȭ�մϴ�." << endl;
	}
public:
	Actor() = default;
	void (*Action)();

	void Think()
	{

		// ������ ���ڸ� �޾Ƽ� 0�� ������ ��������, 1�� ������ Talk, 2�� ������..
		int select = ConsoleUtil::GetRandomInt(2);	// 1, 2�� ������ ������ -1�� ���ش�.

		ActorAction a_action = static_cast<ActorAction>(select-1);

		switch (a_action)
		{
		case MOVE: Action = Move; 
			break;
		case TALK: Action = Talk; 
			break;
		default: cout << "�߸��� �Է��� �޾ƿԽ��ϴ�." << endl; 
			return;
		}
	}
};

#pragma endregion

#pragma region ���������� ���� �����

enum RSP_TYPE
{
	ROCK, SCISSORS, PAPER
};

// �Լ� ������ ����.
// switch(RSP_TYPE) �� Ÿ�Կ� �°� �Լ� �������� �Լ��� �ִ� �ڵ带 ��������.
class RSPgame
{
private:
	static void Rock()
	{
		cout << "�ָ�!" << endl;
	}
	static void Scissors()
	{
		cout << "����!" << endl;
	}
	static void Paper()
	{
		cout << "��!" << endl;
	}

	RSP_TYPE computertype;
	RSP_TYPE usertype;

	int userScore;
	int computerScore;

	void Result()
	{
		if (usertype == computertype)
		{
			cout << "����." << endl;
		}
		else if (usertype == ROCK && computertype == SCISSORS || usertype == SCISSORS && computertype == PAPER || usertype == PAPER && computertype == ROCK)
		{
			cout << "�̰��" << endl;
			userScore++;
		}
		else
		{
			cout << "����." << endl;

		}
	}

public:
	void (*Choose)();
	RSPgame() : userScore(0), computerScore(0) {}

	void StartGame()
	{
		while (true)
		{
			cout << "0.�ָ� 1.���� 2. ��" << endl;
			cout << "�������ּ���." << endl;
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
			default: cout << "�߸��� �Է��� �޾ƿԽ��ϴ�." << endl;
				return;
			}
			cout << "��ǻ�Ͱ� ������ �ൿ : ";
			Choose();
			Result();
			cout << "�÷��̾��� ���� : " << userScore << endl << "��ǻ���� ���� : " << computerScore << endl;
			cout << endl;

			if (userScore >= 3 || computerScore >= 3)
			{
				break;
			}
		}
		if (userScore >= 3)
		{
			cout << "������ �¸��Դϴ�." << endl;
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
	// actor.�ǻ������ �Ѵ�. Think
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

