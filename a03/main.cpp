#include "StopList.h"

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

	shuttle.display();

	return 0;
}
