#include "GameModel.h"
#include <conio.h>
//#include "DropTable.h"
#include "DataHandler.h"

// 경험치 테이블 만든다.
// 1레벨 - 100
// 2레벨 - 100
// 3레벨 - 100
// 4레벨 - 150
// 5레벨 - 150
//

int main()
{
	Player player(0,100);	// exp0, level1, maxExp10
	//Monster monster(0, 0);

	Data data;
	data.SaveData("data.txt");
	data.LoadData("data.txt");

	cout << "level : " << data.level << ", exp : " << data.exp << endl;

	_getch();

	int count = 0;

	while (true)
	{
		system("cls");

		player.GetExp(30);
		player.Show();
		count++;
		_getch();

		if (count >= 4)
		{
			break;
		}
	}

	player.SaveData("player.txt");
	player.LoadData("player.txt");
}