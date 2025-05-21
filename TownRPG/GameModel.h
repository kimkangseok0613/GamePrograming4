#pragma once

#include <iostream>

// virtual Ű���带 ����ϸ� �ش� Ŭ������ ����ϴ� �ڽ� Ŭ������ �ʿ��մϴ�.
// Combat - Player, Monster
// override ����� ����Ͽ� CombatŸ���ӿ��� Player�� Combat�� Monster�� Combat ����� �� �ִ�.
// 
// virtual �Լ�() = 0; ���� �����Լ�
//


class Combat
{
public:
	virtual ~Combat() = default;

	virtual void attack(Combat& target) = 0;
	virtual void takeDamage(int damage) = 0;
	virtual int getHealth() = 0;
};

class Player : public Combat
{
private:
	int health;
	int ATK;

public:
	Player(int health, int ATK) : health(health), ATK(ATK) {}

	void attack(Combat& target) override
	{
		target.takeDamage(ATK);
	}

	void takeDamage(int damage) override
	{
		health -= damage;
		std::cout << "Player��" << damage << "�� ���ظ� �Ծ����ϴ�." << std::endl;
	}

	int getHealth() override
	{
		return health;
	}
};

class Monster : public Combat
{
private:
	int health;
	int ATK;

public:
	Monster(int health, int ATK) : health(health), ATK(ATK) {}

	void attack(Combat& target) override
	{
		target.takeDamage(ATK);
	}
	void takeDamage(int damage) override
	{
		health -= damage;
		std::cout << "Monster��" << damage << "�� ���ظ� �Ծ����ϴ�." << std::endl;
	}

	int getHealth() override
	{
		return health;
	}
};