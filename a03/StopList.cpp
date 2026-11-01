#include "StopList.h"
#include <iostream>

StopList::StopList()
{
	head = nullptr;
}

StopList::~StopList()
{
	while (head != nullptr)
	{
		Node* temp = head; // initialize the first node to temp
		head = head->next; // move head to the next node
		delete temp; // frees up the memory
	}
}

bool StopList::append(const Stop& stop)
{
	if (stop.name.empty()) // discard an empty name
	{
		return false;
	}
	
	Node* current = head;

	while (current != nullptr)
	{
		if (current->data.name == stop.name) // check for any duplicate names
		{
			return false;
		}

		current = current->next; // move pointer to next node if its not a duplicate
	}

	Node* newNode = new Node; // allocate memory for a node
	newNode->data = stop; // copy the stop into that node
	newNode->next = nullptr; // set pointer to nullptr because it will be the last node

	if (head == nullptr) // if list is empty, connect node to list
	{
		head = newNode;
	}
	else // else change nodes next pointer to hold a new address
	{
		current = head;

		while (current->next != nullptr)
		{
			current = current->next;
		}

		current->next = newNode; //access next through a pointer
	}

	return true;
}
void StopList::display() const
{
	if (head == nullptr)
	{
		std::cout << "\nThe shuttle list is empty.\n";
		return;
	}

	const Node* current = head;

	while (current != nullptr)
	{
		std::cout << '\n' << current->data.name << '\n'
			  << current->data.description << '\n';

		current = current->next;
	}
}

bool StopList::insertAfter(const std::string& name, const Stop& stop)
{
	if (stop.name.empty())
	{
		return false;
	}

	Node* current = head;
	Node* target = nullptr;

	while (current != nullptr)
	{
		if (current->data.name == stop.name)
		{
			return false;
		}

		if (current->data.name == name)
		{
			target = current;
		}

		current = current->next;
	}

	if (target == nullptr)
	{
		return false;
	}
	
	Node* newNode = new Node;
	newNode->data = stop;

	newNode->next = target->next;
	target->next = newNode;

	return true;
}
