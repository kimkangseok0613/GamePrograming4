#include "GameModel.h"

class BattleManager
{
private:
	Player& player;
	Monster& monster;


	// BattleManager battlemanager(player, monster); battlemanager.Battle();

	// ü���� 0���� ũ�� �ݺ��ض�. while Ż�� ������ ���� �ۼ��ض�.
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

		std::cout << "������ ����Ǿ����ϴ�." << std::endl;
	}
};