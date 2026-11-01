**FINAL SUBMISSION IS LABELLED **

## Compilation
This program was written and tested using g++ in Ubuntu/WSL.

to compile:

```bash

g++ -Wall -Wextra -std=c++17

## Overview
// OVERVIEW: A ghost train needs its carriages rearranged. A travelling circus
has acquired another wagon. A tiny music festival has a new performer who
needs to go on immediately after the juggling act.

Choose an ordered collection with some personality, then build a singly
linked list to manage it. 

*List is based on a book I am writing. Figured it would be cool to utilize
the world I am creating for this*

Choosen List:
Arrival Platform - Travellers disembark beneathe the pale light of Arcadia
Outer Space Hotel - The concierge greets travelers in the lobby
Tabloid Lounge - A forgotten lounge singer performs for the guests
Echo Balcony - Visitors can watch distant planets through an aging telescope
Departure Terminal - The shuttle prepares for its return to Earth


## Commits
// 1.0:
- Created struct to hold stop name and description
- Node holds only one stop and a pointer to the next node
- Two deletes should prevent objects from pointing to the same node and deleting them
- Added a bool append to sort through the nodes, discard and/or add the next nodes

// 1.1:
- Added a display function in StopList.cpp to 
- Added main.cpp to try a test of the program so far
- Added bool to identify current stop and new insert stop
- Tested program to work with additional stop

// 1.2:
- Added bool remove function to delete a stop by name
- Tested in main, passed
- Added bool save function to save the itinerary to a new file or overwrite


