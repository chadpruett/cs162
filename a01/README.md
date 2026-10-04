# Assignment 01


**FINAL SUBMISSION IS LABELLED a01**

## Compilation
This program was written and tested using g++ in Ubuntu/WSL.

to compile:

'''bash

g++ -Wall -Wextra -std=c++17 a01.cpp -o a01

## Overview
//OVERVIEW:
Creating an RPG style console-based combat simulation. This will allow a
player to fight random creatures, track and collect treasure, and manage
encounters until the player either dies or runs away.

## Versions
//VERSION: 1.0
Got the functions of the monster and treasure generators going. Got the
program able to excecute and run the loop, while correctly validating
user input. 

//VERSION: 1.1 
Got the battle function loop started. Added printInventory function, to
display array of items and their total sum. Added addTreasure function
to give to player after winning battle.  

//VERSION: 1.2
Cleaned up the battle instance and implemented the bool. Will move them
to a different function in a later version so that main is cleaner.

//VERSION: 1.3
Moved battle instance to a separate function so that main is cleaner.
Added quirky choices to the game.  

//VERSION: 1.4
Lowered "Hoover Vacuum" damage. 
Lowered "Piano" damage.
Fixed issue with attack text not showing during battle sequence. 
Utilized const int with atkTxt, creature cap, and treasure cap.

//VERSION: a01
Final completed program.
