#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;

const int MAX = 50;
//const int MAX_ATK_TXT = 50;
//const int MAX_INVENTORY = 3;
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

void menu();
int intVal(int min, int max);
void getCreature(Creature& creature);
void printCreature(const Creature& creature);
void getTreasure(Treasure& treasure);

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	
	Creature creature;
	Treasure treasure;

	int playerCursor = 0;
	//int playerHP = 100;
	//int inventoryCount = 0;

	do
	{
		menu();

		playerCursor = intVal(1, 4);
		if (playerCursor == 1)
		{
			getCreature(creature);
			printCreature(creature);
		}
		else if (playerCursor == 2)
		{
			std::cout << "\nNothing..";
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

int intVal(int min, int max)
{
	int value = 0;

	while (!(cin >> value) || value < min || value > max)
	{
		std::cout << "\nThere were only four options. And you chose that?"
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
	{"Chandelier", "Fall on Head", 120, 15},
	{"Hallway Rug", "Rug Pull", 150, 20, 80},
	};
	
	creature = creatures[index];
}

void printCreature(const Creature& creature)
{
	std::cout << creature.name << " appeared! You're cooked!\n";
}

void getTreasure(Treasure& treasure)
{
	int index = rand() % 4;
	
	Treasure treasures[4] =
	{
	{"Martini (Overpriced)", 50},
	{"Martini", 10},
	{"Microphone", 25},
	{"Lipstick", 35},
	};

	treasure = treasures[index];
}
