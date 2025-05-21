//#include "GameModel.h"
#include "BattleManager.cpp"

// GameModel���� ���� ����� �׽�Ʈ�մϴ�.
// BattleManager - Player, Monster
//

int main()
{
	Player player(100, 10);
	Monster monster(80, 5);

	// BattleManager battlemanager(player, monster); battlemanager.Battle();

	// ü���� 0���� ũ�� �ݺ��ض�. while Ż�� ������ ���� �ۼ��ض�.

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