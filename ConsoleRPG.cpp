// ConsoleRPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cstdlib> 
#include<ctime> 

#include "Player1.h"
#include "Enemy1.h"

using namespace std;

void Player1LevelUp(Player1& player1)
{
    int upgradechoice1;

    do
    {
        cout << "Choose an upgrade:\n";
        cout << "1 - HP +100 (also replenish your health)\n";
        cout << "2 - Strength +10\n";
        cout << "3 - Defense +5\n";
        cout << " >> ";
        cin >> upgradechoice1;
        cout << endl;
        if (upgradechoice1 == 1)
        {
            player1.AddHP();
            cout << "HP upgraded." << endl << endl;
            cout << "Player's current stats: " << endl << endl;
            player1.DisplayStats();
        }
        else if (upgradechoice1 == 2)
        {
            player1.AddStrength();
            cout << "Strength upgraded." << endl << endl;
            cout << "Player's current stats: " << endl << endl;
            player1.DisplayStats();
        }
        else if (upgradechoice1 == 3)
        {
            player1.AddDefense();
            cout << "Defense upgraded." << endl << endl;
            cout << "Player's current stats: " << endl << endl;
            player1.DisplayStats();
        }
        else
        {
            cout << "Invalid Input" << endl << endl;
        }
    } while (upgradechoice1 < 1 || upgradechoice1 > 3);
}

void Enemy1Upgrade(Enemy1& enemy1)
{
    enemy1.UpgradeStats();
}

void GameOver(int& matchcount)
{
    cout << "GAME OVER" << endl << endl;
    cout << "You survived " << matchcount << " round(s)" << endl;
}

void Fight1(Player1& player1, Enemy1& enemy1, int& matchcount)
{
    int player1damage;
    int enemy1damage;

    cout << "Player's stats: \n\n";
    player1.DisplayStats();
    cout << endl;
    cout << "Enemy's stats: \n\n";
    enemy1.DisplayStats();
    cout << endl;
    system("PAUSE");
    cout << "ROUND " << matchcount << " FIGHT" << endl;

    do
    {
        srand(time(NULL));
        cout << "Player Attacking:\n\n";
        enemy1damage = ((rand() % player1.Strength + 4) - (rand() % enemy1.Defense));
        if (enemy1damage <= 0)
        {
            enemy1damage = 1;
        }
        //cout << enemy1damage << endl;
        enemy1.TakeDamage(enemy1damage);
        cout << "Enemy's current stats: \n\n";
        enemy1.DisplayStats();
        cout << endl;

        system("PAUSE");

        if (enemy1.HP <= 0)
        {
            cout << "Enemy is down" << endl << endl;
            cout << "ROUND " << matchcount << " WIN" << endl << endl;
            Player1LevelUp(player1);
            Enemy1Upgrade(enemy1);
            break;
        }

        cout << "Enemy Attacking:\n\n";
        player1damage = ((rand() % enemy1.Strength + 4) - (rand() % player1.Defense));
        if (player1damage <= 0)
        {
            player1damage = 1;
        }
        //cout << player1damage << endl;
        player1.TakeDamage(player1damage);
        cout << "Player's current stats: \n\n";
        player1.DisplayStats();
        cout << endl;

        system("PAUSE");

        if (player1.HP <= 0)
        {
            cout << "Player is down" << endl << endl;
            GameOver(matchcount);
            break;
        }
    } while (player1.HP > 0 && enemy1.HP > 0);
}

void StartGame()
{
    Player1 player1;
    Enemy1 enemy1;

    int matchcount = 1;
    int menuchoice2;

    Fight1(player1, enemy1, matchcount);
    do
    {
        cout << endl;
        cout << "1 - Proceed to the next fight\n";
        cout << "2 - Exit Game\n";
        cout << " >> ";
        cin >> menuchoice2;
        if (menuchoice2 == 1)
        {
            matchcount++;
            Fight1(player1, enemy1, matchcount);
        }
        else if (menuchoice2 == 2)
        {
            GameOver(matchcount);
        }
        else
        {
            cout << "Invalid Input" << endl;
        }
    } while (menuchoice2 != 2 && player1.HP > 0);
}

int main()
{
    Player1 player1;
    Enemy1 enemy1;

    int menuchoice1;

    do
    {
        cout << "1im19's Console RPG\n";
        cout << "1 - Start Game\n";
        cout << "2 - Exit\n";
        cout << " >> ";
        cin >> menuchoice1;
        if (menuchoice1 == 1)
        {
            cout << "\n";
            StartGame();
            cout << "\n";
        }
        else if (menuchoice1 == 2)
        {
            break;
        }
        else
        {
            cout << "\n";
            cout << "Invalid input" << endl;
            cout << "\n";
        }
    } while (menuchoice1 != 2);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
