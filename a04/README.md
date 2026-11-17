# Assignment 04


**FINAL SUBMISSION IS LABELLED a01**

## Compilation
This program was written and tested using g++ in Ubuntu/WSL.

to compile:

```bash

g++ -Wall -Wextra -std=c++17 a01.cpp -o a01

## Overview
// OVERVIEW:
Turning our original assignment 1 battle system into an explorable adventure.
Player will travel through a tree of rooms, fight enemies, collect treasure,
and try to return to the entrance with the loot. 

Setting will take place in a hotel on a moon at the furthest reaches of our
solar system. 

## Commit
// Commit: 1.0
- Add adventure room tree and cleanup

// Commit: 1.1
- Completed room map and added room display

// Commit: 1.2
- Implemented explore function to traverse the rooms

// Commit: 1.3
- Added treasures to the rooms and test call

// Commit: 1.4
- Added treasure display to options
- Added bool to treasures when collected from a room
- passed tests
- Added creatures to rooms
- Prevent player form collecting treasure until creatures hp is < 0

