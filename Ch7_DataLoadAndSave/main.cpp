#include "GameModel.h"
#include <conio.h>
//#include "DropTable.h"
#include "DataHandler.h"

// ����ġ ���̺� �����.
// 1���� - 100
// 2���� - 100
// 3���� - 100
// 4���� - 150
// 5���� - 150
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