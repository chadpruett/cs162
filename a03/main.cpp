#include "StopList.h"
#include<iostream>
int main()
{
	StopList shuttle;

	shuttle.display();

	Stop arrival;
	arrival.name = "Arrival Platform";
	arrival.description = "Passengers arrive beneath the pale light of Arcadia's moon.";

	Stop lounge;
	lounge.name = "Tabloid Lounge";
	lounge.description = "A forgotten lounge singer performs for the evening guests.";

	shuttle.append(arrival);
	shuttle.append(lounge);

	Stop hotel;
	hotel.name = "Outer Space Hotel";
	hotel.description = "The concierge greets travelers in the lobby.";

	if (shuttle.insertAfter("Arrival Platform", hotel))
	{
		std::cout << "\nStop inserted sucessfully.\n";
	}
	else
	{
		std::cout << "\nCould not insert stop.\n";
	}

	shuttle.display();

	return 0;
}
