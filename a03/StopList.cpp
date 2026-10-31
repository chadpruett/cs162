#include "StopList.h"

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

StopList::bool append(const Stop& stop)
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
