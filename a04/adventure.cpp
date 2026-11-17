//adventure.cpp
#include "adventure.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>

// adventure class constructor
Adventure::Adventure() // runs when object is created
{
	root = new Room{}; // create a room

	// create lobby
	std::strcpy(root->title, "Lobby");
	std::strcpy(root->description, "A beautiful chandelier flickers above "
	"the empty reception desk. Patti Page's 'Old Cape Cod' echoes throughout "
	"the cavernous halls of the hotel. ");
	
	// show next room
	std::strcpy(root->leftPath, "Enter the Grandeur Hallway.");
	
	// create hallway
	root->left = new Room{};
	std::strcpy(root->left->title, "Grandeur Hallway");
	std::strcpy(root->left->description, "The hallway seems to stretch around "
	"your every step.");
	
	// create lunar dune
	root->right = new Room{};
	std::strcpy(root->right->title, "Lunar Dune");
	std::strcpy(root->right->description, "Silver sands stretch beneath "
	"a dusk crimson sky.");
	
	std::strcpy(root->rightPath, "Traverse across the Lunar Dune");

	root->right->parent = root; //set hallway return to lobby

	Room* hallway = root->left; // point to hallway
	hallway->parent = root;

	// create the ballroom, set title and description
	hallway->left = new Room{};
	std::strcpy(hallway->left->title, "Ballroom");
	std::strcpy(hallway->left->description, "An empty dance floor waits "
	"beneathe dusty lights. You can't help but wonder what has gone down here.");
	std::strcpy(hallway->leftPath, "Enter the Ballroom");

	hallway->left->parent = hallway; // return from ballroom to hallway

	hallway->right = new Room{}; // allocate room and connect to hallway right child

	// set room title and description
	std::strcpy(hallway->right->title, "Suite 1027");
	std::strcpy(hallway->right->description, "The light from the "
	"moon's mother planet spills across the neatly fashioned bed.");

	// store path to hallway
	std::strcpy(hallway->rightPath, "Enter Suite 1027");

	// return to hallway
	hallway->right->parent = hallway;

	Room* ballroom = hallway->left;

	// create tabloid lounge
	ballroom->left = new Room{};
	std::strcpy(ballroom->left->title, "Tabloid Lounge");
	std::strcpy(ballroom->left->description, "A candle lit bar curves beside "
	"circular tables. A central stage holds a microphone, drums, electric "
	"piano, guitar and bass.");
	
	std::strcpy(ballroom->leftPath, "Enter Tabloid Lounge");
	ballroom->left->parent = ballroom;

	// create terrace
	ballroom->right = new Room{};
	std::strcpy(ballroom->right->title, "Echo Balcony");
	std::strcpy(ballroom->right->description, "The hotel's balcony "
	"overlooks the lunar landscape. Its spectacular.");
	
	std::strcpy(ballroom->rightPath, "Step onto the Terrace");
	ballroom->right->parent = ballroom;

	Room* dune = root->right;

	dune->left = new Room{};

	std::strcpy(dune->left->title, "Crash Site");
	std::strcpy(dune->left->description, "A broken spacecraft lies "
	" half buried in the silver sand.");

	std::strcpy(dune->leftPath, "Approach Crash Site");

	// connect crash site to lunar dune
	dune->left->parent = dune;

	//treasure system
	hallway->right->treasure = Treasure{"Bellhop Hat", 45};
	hallway->right->hasTreasure = true;

	ballroom->left->treasure = Treasure{"Microphone", 25};
	ballroom->left->hasTreasure = true;

	dune->left->treasure = Treasure{"Communication Log", 75};
	dune->left->hasTreasure = true;

	// player
	playerHP = 100;

	// start with no treasure
	inventoryLength = 0;
	
	// add creatures
	ballroom->left->enemy = Creature{
		"Piano", "F Sharp", 80, 10, 60
	};
	ballroom->left->hasEnemy = true;

	startingLoot = calcLoot(root);

	currentRoom = root; //copy to lobby's address
	
	//temp loot check
	std::cout << "\nStarting treasure: " << startingLoot << " gil\n";
}

Adventure::~Adventure() //
{
	deleteRooms(root); // free memory
}

void Adventure::collectTreasure()
{
	if (!currentRoom->hasTreasure)
	{
		return;
	}
	
	if (currentRoom->hasEnemy && currentRoom->enemy.hp > 0 )
	{
		return;
	}

	if (inventoryLength < MAX_INVENTORY)
	{
		inventory[inventoryLength] = currentRoom->treasure;
		inventoryLength++;

		std::cout << "\nYou gathered "
			  << currentRoom->treasure.name << " worth "
			  << currentRoom->treasure.gil << " gil.\n";
		
		// set treasure to collected
		currentRoom->hasTreasure = false;
	}
	else
	{
		std::cout << "\nYou can't carry anymore treasure...\n";
	}
}

int Adventure::calcLoot(const Room* room) const
{
	// no treasure 
	if (room == nullptr)
	{
		return 0;
	}

	// if treasure is in room
	int roomLoot = 0;

	if (room->hasTreasure)
	{
		roomLoot = room->treasure.gil;
	}

	return roomLoot + calcLoot(room->left) + calcLoot(room->right);
}

void Adventure::displayRoom() const
{
	// display room title & description
	std::cout << "\n----- " << currentRoom->title << " ----\n"
		  << currentRoom->description << "\n";

	// display player hp
	std::cout << "\n[Player HP: " << playerHP << "]\n";
	
	// show a path if available
	if (currentRoom->left != nullptr)
	{
		std::cout << "\n1) " << currentRoom->leftPath;
	}

	if (currentRoom->right != nullptr)
	{
		std::cout << "\n2) " << currentRoom->rightPath;
	}

	// if no path is available
	if (currentRoom->parent != nullptr)
	{
		std::cout << "\n3) Return to " << currentRoom->parent->title;
	
	}
	else
	{
		std::cout << "\n3) Leave the adventure";	
	}

	// display inventory
	std::cout << "\n4) Check inventory";

	std::cout << "\n";
}

void Adventure::explore()
{
	bool exploring = true;

	while (exploring)
	{
		// collect treasure before anything displays
		collectTreasure();

		displayRoom();

		std::cout << "\n>> ";
		int choice = intVal(1, 4);

		if (choice == 1)
		{
			if (currentRoom->left != nullptr)
			{
				currentRoom = currentRoom->left;
			}
			else
			{
				std::cout << "\nThere is no path that way.\n";
			}
		}
		else if (choice == 2)
		{
				
			if (currentRoom->right != nullptr)
			{
				currentRoom = currentRoom->right;
			}
			else
			{
				std::cout << "\nThere is no path that way.\n";
			}
		}
		else if (choice == 3)
		{
			if (currentRoom->parent != nullptr)
			{
				currentRoom = currentRoom->parent;
			}
			else
			{
				std::cout << "\nYou leave the adventure.\n";
				exploring = false;
			}
		}
		else // added display inventory option
		{
			printInventory(inventory, inventoryLength);
		}
	}

}

void Adventure::deleteRooms(Room* room)
{
	if (room == nullptr)
	{
		return;
	}

	deleteRooms(room->left);
	deleteRooms(room->right);

	delete room;
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
		std::cout << "\nYou grabbed a book off a bookshelf\n"
		<< "next to you and threw it at " << creature.name << "\n";
		
		playerHitChance = 90;
		playerDamage = 35;
	}
	else if (playerMove == 2)
	{
		std::cout << "\nYou twirled your microphone\n"
		<< "and launched it at " << creature.name << "\n";
		playerHitChance = 50;
		playerDamage = 55;
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

			std::cout << '\n' << creature.name << " used "
			<< creature.atkTxt;

			if (attackHits(creature.atkPer))
			{
				playerHP -= creature.atkDmg;
				std::cout << " and hit you!\n";
			}
			else
			{
				std::cout << " and missed!\n";
			}
		
		}	
					
		// if creature is defeated
		if (creature.hp <= 0)
		{
		std::cout << "\n\n" << "You defeated " << creature.name << '\n';				
		}

	return playerHP;
}

int intVal(int min, int max)
{
	int value = 0;

	while (!(std::cin >> value) || value < min || value > max)
	{
		std::cout << "\nOut of all the options, and you chose that huh?"
		<< "\n>> ";
		std::cin.clear();
		std::cin.ignore(100, '\n');
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
	{"Piano", "F Sharp", 180, 5, 93},
	{"Hoover Vacuum", "Bristle Cleaning", 100, 35, 30},
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
			std::cout << '\n' << inventory[i].name
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
