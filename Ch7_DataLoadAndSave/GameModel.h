#pragma once

// ��ǥ1 : ������ �ý��� ����.
// int exp, maxExp; ���� ����ġ > maxExp		������ 1 �ø���.
// 
// ��ǥ2 : ������ ���� ����ġ �䱸���� �ڷᱸ���� ǥ���ϱ�
// vector<"">
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// �����͸� ǥ���ϱ� ���� Ŭ������ �����ϼ���. LevelExp
// Ư�� Ŭ���� �ȿ� ǥ���ϱ� ���� Ŭ������ �ڷᱸ���� �����ϼ���. Player -> std::vector<LevelExp> levelTable;
// 
// �����ڿ� �����͸� ���� �ۼ��Ѵ�.
// vector.push_back();
// vector.emplace_back();
// 

struct LevelExp
{
	int level;
	int maxExp;

	LevelExp(int level, int maxExp) : level(level), maxExp(maxExp) {}
};

class Player
{
private:
	int exp;
	int maxExp;
	int level;
	vector<LevelExp> levelTable;
public:
	Player() : exp(0), level(1), maxExp(100) {}
	Player(int exp, int maxExp) : level(1), exp(exp), maxExp(maxExp) 
	{
		levelTable.emplace_back(1, 100);
		levelTable.emplace_back(2, 100);
		levelTable.emplace_back(3, 100);
		levelTable.emplace_back(4, 150);
		levelTable.emplace_back(5, 150);
		levelTable.emplace_back(6, 150);
		levelTable.emplace_back(7, 200);
		levelTable.emplace_back(8, 200);
		levelTable.emplace_back(9, 200);
	}

	int GetMaxExpForLevel(int level)
	{
		for (const auto& data : levelTable)
		{
			// ������ Table ������ ���϶�.
			if (level == data.level)
			{
				return data.maxExp;
			}
		}

		return -1; // -1 ��ȯ�ϸ� ������ �ν��ض�.
	}

	void GetExp(int amount)	// ����ġ�� ȹ��
	{
		maxExp = GetMaxExpForLevel(level);

		if (maxExp == -1)
		{
			cout << "�ִ� ������ �����߽��ϴ�. ������ ����մϴ�." << endl;
			return; // ���� ó�� �ڵ� �˸� �� �Լ��� �����Ѵ�.
		}

		exp += amount;		// exp �� ��ġ��ŭ �����ش�.

		if (exp >= maxExp)	// "������ �ִ� ����ġ�� �������� ��
		{
			level++;
			exp -= maxExp;
		}
	}

	void Show() const
	{
		cout << "Level : " << level << endl;
		cout << "Exp : " << exp << endl;
		cout << "MaxExp : " << maxExp << endl;
	}

	void SaveData(const string& filename)
	{
		ofstream file(filename);

		if (file.is_open())
		{
			file << level << " " << exp << " " << maxExp << endl;
			file.close();
		}
	}

	void LoadData(const string& filename)
	{
		ifstream file(filename);

		int _exp, _level, _maxExp;

		file >> _level >> _exp >> _maxExp;

		level = _level;
		exp = _exp;
		maxExp = _maxExp;
	}
};