#ifndef STOPLIST_H
#define STOPLIST_H
#include <string>

struct Stop
{
	std::string name;
	std::string description;
};

class StopList
{
	private:
		struct Node
		{
			Stop data;
			Node* next;
		};

		Node* head; // hold one stop and a pointer to the next node

	public:
		StopList();
		~StopList();

		StopList(const StopList&) = delete;
		StopList& operator=(const StopList&) = delete;
		bool append(const Stop& stop);
		void display() const;
};


#endif
