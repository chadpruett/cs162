#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;

const int MAX = 50;
const int MAX_ATK_TXT = 20;
const int MAX_INVENTORY = 3;
const int MAX_CREATURES = 5;
const int MAX_TREASURES = 5;

struct Creature
{
	char name[MAX];
	char atkTxt[MAX_ATK_TXT];
	int hp;
	int atkDmg;
	int atkPer;	
};

struct Treasure
{
	char name[MAX];
	int gil;
};


Treasure getTreasure();
void menu(const int playerHP);
void battleMenu(const int playerHP, Creature creature);
void gameOver();
int intVal(int min, int max);
void getCreature(Creature& creature);
void printInventory(Treasure inventory[], int inventoryLength);
void printCreature(const Creature& creature);
void addTreasure(Treasure inventory[], int& inventoryLength);
bool attackHits(int hitChance);
int battleSequence(const int playerMove, int& playerHP, Creature& creature);

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	
	Creature creature;
	Treasure inventory[MAX_INVENTORY]{};

	int playerCursor = 0;
	int playerMove = 0;
	int playerHP = 100;
	int inventoryLength = 0;


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

	gameOver();

	return 0;
}

void menu(const int playerHP)
{
	std::cout << "\n---- Main Menu ----"
	<< "\n[Player HP: " << playerHP << "] \n"
	<< "\n1) Fight"
	<< "\n2) Check Inventory"
	<< "\n3) Quit While You're Ahead"
	<< "\n>> ";
}

void battleMenu(const int playerHP, Creature creature)
{
	std::cout << "\n\n[Player HP: " << playerHP << "]  "
	<< '[' << creature.name << " HP: " << creature.hp << "]\n"
	<< "\nWhat's the move?"
	<< "\n1) Quick Attack"
	<< "\n2) Heavy Attack"
	<< "\n3) Beg"
	<< "\n4) Turn around and run"
	<< "\n>> ";
}

int battleSequence(const int playerMove, int& playerHP, Creature& creature)
{
	int playerHitChance;
	int playerDamage;

	if (playerMove == 1)
	{
		playerHitChance = 90;
		playerDamage = 20;
	}
	else if (playerMove == 2)
	{
		playerHitChance = 50;
		playerDamage = 40;
	}
	else 
	{
		playerHitChance = 0;
		playerDamage = 0;
		std::cout << "\n\nYou got on your knees and clasped "
		<< "your hands together...\n\n"
		<< creature.name << " just kept looking at you... then attacked!\n\n";
	}

	// if the hit lands
	
	if (playerHitChance > 0)
	{
		if (attackHits(playerHitChance))
		{
			creature.hp -= playerDamage;
			std::cout << "\nYour attack hit!\n";
		}
		else
		{
			std::cout << "\nYour attack missed!\n";
		}
		// if creature is alive still, it hits or not
	}

		if (creature.hp > 0)
		{
			if (attackHits(creature.atkPer))
			{
				playerHP -= creature.atkDmg;
				std::cout << '\n' << creature.name << " hit you!\n";
			}
		else
		{
			std::cout << '\n' << creature.name << " missed!\n";
		}
		
		}	
					
		// if creature is defeated
		if (creature.hp <= 0)
		{
		std::cout << "\n\n" << "You defeated " << creature.name << endl;				
		}

	return playerHP;
}

int intVal(int min, int max)
{
	int value = 0;

	while (!(cin >> value) || value < min || value > max)
	{
		std::cout << "\nOut of all the options, and you chose that huh?"
		<< "\n>> ";
		cin.clear();
		cin.ignore(100, '\n');
	}

	return value;
}

void getCreature(Creature& creature)
{
	int index = rand() % MAX_CREATURES;

	Creature creatures[MAX_CREATURES] =
	{
	//name, atkname, hp, atkdmg, atkperc
	{"Mirror", "Reflect", 100, 50, 30},
	{"Chandelier", "Fall on Head", 120, 60, 15},
	{"Hallway Rug", "Rug Pull", 150, 20, 80},
	{"Piano", "F Sharp", 180, 10, 93},
	{"Hoover Vacuum", "Bristle Cleaning", 100, 45, 80},
	};
	
	creature = creatures[index];
}

void printInventory(Treasure inventory[], int inventoryLength)
{
	int inventorySum = 0;
	
	if(inventoryLength == 0)
	{
		std::cout << "\nLint...";
	}
	else
	{
		for(int i = 0; i < inventoryLength; i++)
		{
			std::cout << "\nItem: " << inventory[i].name
			<< " - " << inventory[i].gil << " gil\n";

			inventorySum+=inventory[i].gil;
		}
	}

		std::cout << "\n\nTotal gil: " << inventorySum << "\n\n";

}

void printCreature(const Creature& creature)
{
	std::cout << "\n\n" << creature.name << " appeared! You're cooked!\n";
}

Treasure getTreasure()
{
	int index = rand() % MAX_TREASURES;
	
	Treasure treasures[MAX_TREASURES] =
	{
	{"Martini (Overpriced)", 50},
	{"Martini", 10},
	{"Microphone", 25},
	{"Lipstick", 35},
	{"Bellhop Hat", 45},
	};

	return treasures[index];
}

void addTreasure(Treasure inventory[], int& inventoryLength)
{
	if (inventoryLength < MAX_INVENTORY)
	{
		inventory[inventoryLength] = getTreasure();

		std::cout << "\nYou received "
		<< inventory[inventoryLength].name << "!\n";
		
		inventoryLength++;
	}
	else
	{
		std::cout << "\nYour inventory is full!\n";
	}
}

bool attackHits(int hitChance)
{
	int roll = rand() %100 + 1;
	return roll <= hitChance;
}

void gameOver()
{
	std::cout << "\n\n----- GAME OVER -----\n\n";

}
