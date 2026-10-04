#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;

const int MAX = 50;
//const int MAX_ATK_TXT = 50;
const int MAX_INVENTORY = 3;
//const int MAX_TREASURES = 2;

struct Creature
{
	char name[MAX];
	char atkTxt[MAX];
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
void menu();
void battleMenu();
int intVal(int min, int max);
void getCreature(Creature& creature);
//Treasure getTreasure(Treasure& treasure);
void printInventory(Treasure inventory[], int inventoryLength);
void printCreature(const Creature& creature);
void addTreasure(Treasure inventory[], int& inventoryLength);

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	
	Creature creature;
	Treasure treasure;
	Treasure inventory[MAX_INVENTORY]{};

	int playerCursor = 0;
	int playerMove = 0;
	//int playerHP = 100;
	int inventoryLength = 0;

	do
	{
		menu();

		playerCursor = intVal(1, 3);
		
		if (playerCursor == 1)
		{
			getCreature(creature);
			printCreature(creature);
			
			do
			{
				battleMenu();
				playerMove = intVal(1, 3);
					
					
			} while (playerMove != 3);

			//add random inventory generator and give to player
			
			addTreasure(inventory, inventoryLength);


		}
		else if (playerCursor == 2)
		{
			printInventory(inventory, inventoryLength);
		}

	} while (/*playerHP != 0 || */playerCursor != 3);

	std::cout << '\n';

	return 0;
}

void menu()
{
	std::cout << "\n---- Main Menu ----"
	<< "\n1) Fight"
	<< "\n2) Check Inventory"
	<< "\n3) Run"
	<< "\nChoose an option: ";
}

void battleMenu()
{
	std::cout << "\nWhat's the move?"
	<< "\n1) Quick Attack"
	<< "\n2) Heavy Attack"
	<< "\n3) Turn around and run"
	<< "\n>> ";
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
	int index = rand() % 3;

	Creature creatures[3] =
	{
		//name, atkname, hp, atkdmg, atkperc
	{"Mirror", "Reflect", 100, 50, 30},
	{"Chandelier", "Fall on Head", 120, 30, 15},
	{"Hallway Rug", "Rug Pull", 150, 20, 80},
	};
	
	creature = creatures[index];
}

void printInventory(Treasure inventory[], int inventoryLength)
{
	int inventorySum = 0;
	
	if(inventoryLength == 0)
	{
		std::cout << "\nnothing..";
	}
	else
	{
		for(int i = 0; i < inventoryLength; i++)
		{
			std::cout << "\nItem: " << inventory[i].name
			<< '(' << inventory[i].gil << " gil)\n";

			inventorySum+=inventory[i].gil;
		}
	}

		std::cout << "\n\nTotal gil: " << inventorySum << "\n\n";

}

void printCreature(const Creature& creature)
{
	std::cout << creature.name << " appeared! You're cooked!\n";
}

Treasure getTreasure()
{
	int index = rand() % 4;
	
	Treasure treasures[4] =
	{
	{"Martini (Overpriced)", 50},
	{"Martini", 10},
	{"Microphone", 25},
	{"Lipstick", 35},
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
