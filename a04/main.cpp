#include "adventure.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	Adventure game;
	game.displayRoom();	
	/*
	Creature creature;
	Treasure inventory[MAX_INVENTORY]{};

	int playerCursor = 0;
	int playerMove = 0;
	int playerHP = 100;
	int inventoryLength = 0;

	// game loop

	do
	{
		menu(playerHP);

		playerCursor = intVal(1, 3);
		
		if (playerCursor == 1)
		{
			getCreature(creature);
			printCreature(creature);
			
			do
			{
				battleMenu(playerHP, creature);
				playerMove = intVal(1, 4);
				
				// if player runs

				if (playerMove == 4)
				{
					std::cout << "\nYou ran away...\n";
					break;
				}
				else if (playerMove == 3)
				{
					battleSequence(playerMove, playerHP, creature);
				}

				// if player chooses to atk
				if (playerMove == 1)
				{
					battleSequence(playerMove, playerHP, creature);
				}
				else if (playerMove == 2)
				{
					battleSequence(playerMove, playerHP, creature);
				}
			
				// if player dies or wins give item	
				if (playerHP <= 0)
				{
					std::cout << "\n----- YOU DIED -----\n";
				}
				else if (playerHP > 0 && creature.hp <= 0)
				{
					addTreasure(inventory, inventoryLength);	
				}
			
			} while (playerHP > 0 && creature.hp > 0 && playerMove != 4);
		} 
		
		else if (playerCursor == 2)
		{
			printInventory(inventory, inventoryLength);
		}

	} while (playerHP > 0 && playerCursor != 3);
	
	if (playerCursor == 3)
	{
		std::cout << "\nI totally get it. I woulda done the same.\n";
	}
	gameOver();
*/
	return 0;
}
