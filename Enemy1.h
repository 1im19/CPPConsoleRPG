#include <iostream>

using namespace std;

#ifndef ENEMY1_H
#define ENEMY1_H

class Enemy1
{
private:
	

public:
	int HP;
	int MaxHP;
	int Strength;
	int Defense;

	Enemy1();
	void DisplayStats();
	void TakeDamage(int);
	void UpgradeStats();
};

#endif // !ENEMY1_H

Enemy1::Enemy1()
{
	HP = 50;
	MaxHP = 50;
	Strength = 5;
	Defense = 2;
}

void Enemy1::DisplayStats()
{
	cout << "HP: " << HP << " / " << MaxHP << endl;
	cout << "Strength: " << Strength << endl;
	cout << "Defense: " << Defense << endl;
}

void Enemy1::TakeDamage(int enemy1damage)
{
	HP -= enemy1damage;
	if (HP < 0)
	{
		HP = 0;
	}
}

void Enemy1::UpgradeStats()
{
	MaxHP += 25;
	HP = MaxHP;
	Strength += 2;
	Defense += 2;
}
