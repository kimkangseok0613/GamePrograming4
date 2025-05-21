#include "GameModel.h"

class BattleManager
{
private:
	Player& player;
	Monster& monster;


	// BattleManager battlemanager(player, monster); battlemanager.Battle();

	// 체력이 0보다 크면 반복해라. while 탈출 조건을 먼저 작성해라.
public:


	void Battle()
	{
		while (player.getHealth() > 0 && monster.getHealth() > 0)
		{
			player.attack(monster);
			if (monster.getHealth() > 0)
			{
				monster.attack(player);
			}

		}

		std::cout << "전투가 종료되었습니다." << std::endl;
	}
};