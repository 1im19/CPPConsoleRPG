#include <iostream>

using namespace std;

#ifndef PLAYER1_H
#define PLAYER1_H

class Player1
{
private:
	

public:
	int HP;
	int MaxHP;
	int Strength;
	int Defense;

	Player1();
	void DisplayStats();
	void TakeDamage(int);
	void AddHP();
	void AddStrength();
	void AddDefense();
};

#endif // !PLAYER1_H

Player1::Player1()
{
	HP = 100;
	MaxHP = 100;
	Strength = 10;
	Defense = 5;
}

void Player1::DisplayStats()
{
	cout << "HP: " << HP << " / " << MaxHP << endl;
	cout << "Strength: " << Strength << endl;
	cout << "Defense: " << Defense << endl;
}

void Player1::TakeDamage(int player1damage)
{
	HP -= player1damage;
	if (HP < 0)
	{
		HP = 0;
	}
}

void Player1::AddHP()
{
	MaxHP += 100;
	HP = MaxHP;
}

void Player1::AddStrength()
{
	Strength += 10;
}

void Player1::AddDefense()
{
	Defense += 5;
}