// ConsoleRPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <fstream>

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
            system("CLS");
            player1.AddHP();
            cout << "HP upgraded." << endl << endl;
            cout << "Player's current stats: " << endl << endl;
            player1.DisplayStats();
        }
        else if (upgradechoice1 == 2)
        {
            system("CLS");
            player1.AddStrength();
            cout << "Strength upgraded." << endl << endl;
            cout << "Player's current stats: " << endl << endl;
            player1.DisplayStats();
        }
        else if (upgradechoice1 == 3)
        {
            system("CLS");
            player1.AddDefense();
            cout << "Defense upgraded." << endl << endl;
            cout << "Player's current stats: " << endl << endl;
            player1.DisplayStats();
        }
        else
        {
            cout << "Invalid Input" << endl << endl;
        }
        system("PAUSE");
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
    system("PAUSE");
}

void SaveGame(ofstream& save1, Player1& player1, int& matchcount)
{
    save1.open("Save.txt");
    if (save1.is_open())
    {
        save1 << player1.MaxHP << " " << player1.Strength << " " << player1.Defense << " " << matchcount << endl;
    }
    else
    {
        cout << "Error. Unable to locate/open file" << endl;
    }
}

void Fight1(Player1& player1, Enemy1& enemy1, int& matchcount)
{
    int player1damage;
    int enemy1damage;

    ofstream save1;

    cout << "Player's stats: \n\n";
    player1.DisplayStats();
    cout << endl;
    cout << "Enemy's stats: \n\n";
    enemy1.DisplayStats();
    cout << endl;
    system("PAUSE");
    system("CLS");
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
        enemy1.TakeDamage(enemy1damage);
        cout << "Enemy's current stats: \n\n";
        enemy1.DisplayStats();
        cout << endl;

        system("PAUSE");
        system("CLS");

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
        player1.TakeDamage(player1damage);
        cout << "Player's current stats: \n\n";
        player1.DisplayStats();
        cout << endl;

        system("PAUSE");
        system("CLS");

        if (player1.HP <= 0)
        {
            cout << "Player is down" << endl << endl;
            GameOver(matchcount);
            SaveGame(save1, player1, matchcount);
            break;
        }
    } while (player1.HP > 0 && enemy1.HP > 0);
}

void LoadGame(ifstream& load1, Player1& player1, int& matchcount)
{
    load1.open("Save.txt");
    if (load1.is_open())
    {
        while (!load1.eof())
        {
            load1 >> player1.MaxHP;
            load1.ignore(0, ' ');
            load1 >> player1.Strength;
            load1.ignore(0, ' ');
            load1 >> player1.Defense;
            load1.ignore(0, ' ');
            load1 >> matchcount;
            load1.ignore(0, '\n');
        }
        player1.HP = player1.MaxHP;
    }
    else
    {
        cout << "Error. Unable to locate/open file" << endl;
    }
}

void StartGame()
{
    Player1 player1;
    Enemy1 enemy1;

    ofstream save1;
    ifstream load1;

    int matchcount;
    int menuchoice2;
    int menuchoice3;

    cout << "1 - New Game\n";
    cout << "2 - Load Game\n";
    cout << "3 - Back to Main Menu\n";
    cout << " >> ";
    cin >> menuchoice2;

    if (menuchoice2 >= 1 && menuchoice2 <= 2)
    {
        if (menuchoice2 == 1)
        {
            matchcount = 1;
        }
        else if (menuchoice2 == 2)
        {
            LoadGame(load1, player1, matchcount);
        }
        system("CLS");
        Fight1(player1, enemy1, matchcount);
        system("CLS");
        do
        {
            cout << endl;
            cout << "1 - Proceed to the next fight\n";
            cout << "2 - Exit Game\n";
            cout << " >> ";
            cin >> menuchoice3;
            system("CLS");
            if (menuchoice3 == 1)
            {
                matchcount++;
                Fight1(player1, enemy1, matchcount);
            }
            else if (menuchoice3 == 2)
            {
                GameOver(matchcount);
                matchcount++;
                SaveGame(save1, player1, matchcount);
            }
            else
            {
                cout << "Invalid Input" << endl;
            }
        } while (menuchoice3 != 2 && player1.HP > 0);
    }
    else if (menuchoice2 == 3)
    {

    }
    else
    {
        cout << "\n";
        cout << "Invalid input" << endl;
        cout << "\n";
    }
}

int main()
{
    Player1 player1;
    Enemy1 enemy1;

    int menuchoice1;

    do
    {
        cout << "Console RPG\n";
        cout << "1 - Start Game\n";
        cout << "2 - Exit\n";
        cout << " >> ";
        cin >> menuchoice1;
        if (menuchoice1 == 1)
        {
            system("CLS");
            StartGame();
            system("CLS");;
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
