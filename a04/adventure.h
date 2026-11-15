#ifndef ADVENTURE_H
#define ADVENTURE_H

// constants
const int MAX = 50;
const int MAX_ATK_TXT = 20;
const int MAX_INVENTORY =3;
const int MAX_CREATURES = 5;
const int MAX_TREASURES = 5;

// Struct definitions
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

struct Room
{
	char title[MAX];
	char description[300];

	char leftPath[MAX];
	char rightPath[MAX];

	Creature enemy;
	bool hasEnemy;

	Treasure treasure;
	bool hasTreasure;

	Room* left;
	Room* right;
	Room* parent;
};

// class definitions
class Adventure
{
	private:
		Room* root;
		Room* currentRoom;
		
		void deleteRooms(Room* room);
	public:
		Adventure();
		~Adventure();

		// prevent owning the same rooms
		Adventure(const Adventure&) = delete;
		Adventure& operator=(const Adventure&) = delete;
};

// display
void menu(const int playerHP);
void gameOver();
void printCreature(const Creature& creature);
void battleMenu(const int playerHP, Creature creature);

// input and validation
int intVal(int min, int max);

// game setup
void getCreature(Creature& creature);
Treasure getTreasure();

// combat
int battleSequence(const int playerMove, int& playerHP, Creature& creature);
bool attackHits(int hitChance);

// inventory
void addTreasure(Treasure inventory[], int& inventoryLength);
void printInventory(Treasure inventory[], int inventoryLenght);

#endif
