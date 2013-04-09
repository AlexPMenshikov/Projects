// A Simple Role-Playing Game
// Author: Michael Hall
//
// This program is available for download through our website XoaX.net with no guarantees.
// Disclaimer: While we have made every effort to ensure the quality of our content, all risks associated
// with downloading or using this solution, project and code are assumed by the user of this material.
//
// Copyright 2008 XoaX - For personal use only, not for distribution
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class CCreature
{
public:

	CCreature() : muiAttack(0), muiDefense(0), muiHitPoints(3)
	{
		for (unsigned int uiIndex = 0; uiIndex < 3; ++uiIndex)
		{
			muiAttack		= muiAttack + (rand() % 34);
			muiDefense		= muiDefense + (rand() % 34);
			muiHitPoints	= muiHitPoints + (rand() % 10);
		}
	}

	void Attack(CCreature& qrDefender)
	{
		// Generate a numbers between 1 and 100
		unsigned int uiAttack1	= (rand() % 100) + 1;
		unsigned int uiDefense1 = (rand() % 100) + 1;
		unsigned int uiAttack2	= (rand() % 100) + 1;
		unsigned int uiDefense2 = (rand() % 100) + 1;
		// Did the attacker (hero) hit?
		if (uiAttack1 < muiAttack && uiDefense1 > qrDefender.muiDefense)
		{
			--qrDefender.muiHitPoints;
			cout << "Monster Hit!" << endl;
		}
		else
		{
			cout << "Monster Missed!" << endl;
		}
		// Did the monster hit
		if (uiAttack2 < qrDefender.muiAttack && uiDefense1 > muiDefense)
		{
			--muiHitPoints;
			cout << "Hero Hit!" << endl;
		}
		else
		{
			cout << "Hero Missed!" << endl;
		}
		cout << "Hero Hitpoints:" << muiHitPoints << endl;
		cout << "Monster Hitpoints:" << qrDefender.muiHitPoints << endl;
	}

	bool IsDead()
	{
		return (muiHitPoints == 0);
	}
private:
	unsigned int muiAttack;
	unsigned int muiDefense;
	unsigned int muiHitPoints;
};

class CDungeon
{
public:

	CDungeon()
	{
		// Create the empty maze
		char caaMaze[10][11] =
		{
			"**********",
			"* **  ** *",
			"* *  **  *",
			"*        *",
			"* *  *** *",
			"* ** * ***",
			"* *  *   *",
			"* **     *",
			"*  * *** *",
			"**********"
        };
		for (unsigned int uiRow = 0; uiRow < 10; ++uiRow)
		{
			for (unsigned int uiCol = 0; uiCol < 10; ++uiCol)
			{
				mcaaMaze[uiRow][uiCol] = caaMaze[uiRow][uiCol];
			}
		}
	}

	char GetMazeSquare(unsigned int uiRow, unsigned int uiCol)
	{
		return mcaaMaze[uiRow][uiCol];
	}
private:
	char mcaaMaze[10][10];
};

class CRolePlayingGame
{
public:
	CRolePlayingGame()
	{
		// Initlialize the random number generator
		time_t qTime;
		time(&qTime);
		srand((unsigned int)qTime);

		// Initialize the dungeon to be empty
		for (unsigned int uiRow = 0; uiRow < 10; ++uiRow)
		{
			for (unsigned int uiCol = 0; uiCol < 10; ++uiCol)
			{
				mqpaaCreatures[uiRow][uiCol]	= 0;
			}
		}

		// Create a hero
		bool bFoundSpot = false;
		while (!bFoundSpot)
		{
			unsigned int uiRow = 1 + (rand() % 8);
			unsigned int uiCol = 1 + (rand() % 8);
			if (QueryLocation(uiRow, uiCol) == ' ')
			{
				bFoundSpot = true;
				mqpaaCreatures[uiRow][uiCol] = &mqHero;
			}
		}
		// Create 10 monsters
		bFoundSpot = false;
		unsigned int uiMonster = 0;
		while (!bFoundSpot)
		{
			unsigned int uiRow = 1 + (rand() % 8);
			unsigned int uiCol = 1 + (rand() % 8);
			if (QueryLocation(uiRow, uiCol) == ' ')
			{
				mqpaaCreatures[uiRow][uiCol] = &mqaMonsters[uiMonster];
				++uiMonster;
				if (uiMonster == 10)
				{
					bFoundSpot = true;
				}
			}
		}
	}

	char QueryLocation(unsigned int uiRow, unsigned int uiCol)
	{
		for (unsigned int uIndex = 0; uIndex < 10; ++uIndex)
		{
			if (mqpaaCreatures[uiRow][uiCol] == &(mqaMonsters[uIndex]))
			{
				return (char)('0' + uIndex);
			}
		}
		if (mqpaaCreatures[uiRow][uiCol] == &mqHero)
		{
			return 'H';
		}
		else
		{
			return mqDungeon.GetMazeSquare(uiRow, uiCol);
		}
	}

	bool MoveHero(const char kcDirection)
	{
		unsigned int uiHeroRow;
		unsigned int uiHeroCol;
		LocateCreature(uiHeroRow, uiHeroCol, &mqHero);
		unsigned int uiNextRow = uiHeroRow;
		unsigned int uiNextCol = uiHeroCol;
		switch (kcDirection)
		{
			case 'w':
			case 'W':
				{
					--uiNextRow;
					break;
				}
			case 's':
			case 'S':
				{
					++uiNextCol;
					break;
				}
			case 'z':
			case 'Z':
				{
					++uiNextRow;
					break;
				}
			case 'a':
			case 'A':
				{
					--uiNextCol;
					break;
				}
			default:
				{
					return false;
				}
		}
		char cNextLoc = QueryLocation(uiNextRow, uiNextCol);
		if (cNextLoc == ' ')
		{
			mqpaaCreatures[uiNextRow][uiNextCol] = &mqHero;
			mqpaaCreatures[uiHeroRow][uiHeroCol] = 0;
			return true;
		}
		else if (cNextLoc >= '0' && cNextLoc <= '9')
		{
			mqHero.Attack(mqaMonsters[(int)(cNextLoc - '0')]);
			return true;
		}
		else
		{
			return false;
		}
	}

	void PrintBoard()
	{
		using namespace std;
		for (unsigned int uiRow = 0; uiRow < 10; ++uiRow)
		{
			for (unsigned int uiCol = 0; uiCol < 10; ++uiCol)
			{
				cout << QueryLocation(uiRow, uiCol);
			}
			cout << endl;
		}
	}

	bool HeroIsDead()
	{
		return mqHero.IsDead();
	}

	void RemoveDeadMonsters()
	{
		for (unsigned int uiIndex = 0; uiIndex < 10; ++uiIndex)
		{
			if (mqaMonsters[uiIndex].IsDead())
			{
				unsigned int uiRow;
				unsigned int uiCol;
				if (LocateCreature(uiRow, uiCol, &(mqaMonsters[uiIndex]))) {
					mqpaaCreatures[uiRow][uiCol] = 0;
					cout << "Monster Killed!" << endl;
				}
			}
		}
	}
	bool AllMonstersDead()
	{
		bool bAllDead = true;
		for (unsigned int uiIndex = 0; uiIndex < 10; ++uiIndex)
		{
			if (!mqaMonsters[uiIndex].IsDead())
			{
				bAllDead = false;
			}
		}
		return bAllDead;
	}

private:
	bool LocateCreature(unsigned int& uirRow, unsigned int& uirCol, CCreature* qpCreature) {
		for (unsigned int uiRow = 0; uiRow < 10; ++uiRow)
		{
			for (unsigned int uiCol = 0; uiCol < 10; ++uiCol)
			{
				if (mqpaaCreatures[uiRow][uiCol] == qpCreature)
				{
					uirRow = uiRow;
					uirCol = uiCol;
					return true;
				}
			}
		}
		return false;
	}
	CDungeon mqDungeon;
	CCreature mqHero;
	CCreature mqaMonsters[10];
	CCreature* mqpaaCreatures[10][10];//Position of monsters
};


int main()
{
	// Cleared the dungeon
	CRolePlayingGame qGame;
	bool bGameOver = false;
	do {
		qGame.PrintBoard();
		// Get the next move
		char cMove;
		cout << "Enter w, a, s, or z to move:" << endl;
		cin >> cMove;
		// Check the move was valid
		if (qGame.MoveHero(cMove))
		{
			// If the hero is dead
			if (qGame.HeroIsDead())
			{
				cout << "You have Died!" << endl;
				bGameOver = true;
			} else {
				// Remove all dead monsters from game
				qGame.RemoveDeadMonsters();
				// If all of the monsters are dead
				if (qGame.AllMonstersDead())
				{
					cout << "Dungeon Cleared!" << endl;
					bGameOver = true;
				}
			}
		}
	}
	while (!bGameOver);
	return 0;
}