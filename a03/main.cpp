#include "StopList.h"
#include<iostream>
#include<string>

int main()
{
	StopList shuttle;
	
	shuttle.append({"Arrival Platform",
	"Passengers arrive beneath the pale light of Arcadia's moon."});

	shuttle.append({"Outer Space Hotel",
	"The concierge greets travellers in the lobby."});
	
	shuttle.append({"Tabloid Lounge",
	"A forgotten singer perfomrs for the evening guests."});

	shuttle.append({"Echo Balcony",
	"Visitors watch distant planets through an aging telescope."});
	
	shuttle.append({"Departure Terminal",
	"The shuttle prepares for its return to Earth."});

	std::string choice;

	do
	{
		std::cout << "\nOuter Space Hotel Shuttle"
			  << "\n*************************"
			  << "\n1. Display itinerary"
			  << "\n2. Append a stop"
			  << "\n3. Insert a stop after another stop"
			  << "\n4. Remove a stop"
			  << "\n5. Save itinerary"
			  << "\n6. Quit"
			  << "\n\nWhat would you like to do? >> ";
		

		if (!std::getline(std::cin, choice))
		{
			break;
		}
		if (choice == "1")
		{
			shuttle.display();
		}
		else if (choice == "6")
		{
			std::cout << "\nGoodbye from Outer Space!\n\n";
		}
		else if (choice == "2")
		{
			Stop newStop;

			std::cout << "\nEnter the new stop's name: ";
			if (!std::getline(std::cin, newStop.name))
			{
				break;
			}

			std::cout << "Enter its description: ";
			if (!std::getline(std::cin, newStop.description))
			{
				break;
			}

			if (shuttle.append(newStop))
			{
				std::cout << "\nStop added sucessfully.\n";
			}
			else
			{
				std::cout << "\nCould not add stop.\n";
			}
		}
		else if (choice == "3")
		{
			std::string targetName;
			Stop newStop;

			std::cout << "\nInsert after which stop?";
			if (!std::getline(std::cin, targetName))
			{
				break;
			}

			std::cout << "\nEnter the new stop's name: ";
			if (!std::getline(std::cin, newStop.name))
			{
				break;
			}

			std::cout << "Enter its description: ";
			if (!std::getline(std::cin, newStop.description))
			{	
				break;
			}

			if (shuttle.insertAfter(targetName, newStop))
			{
				std::cout << "\nStop inserted successfully.\n";
			}
			else
			{
				std::cout << "\nCould not insert stop.";
			}
		}
		else if (choice == "4")
		{
			std::string stopName;

			std::cout << "\nEnter the name of the stop to remove: ";
			if (!std::getline(std::cin, stopName))
			{
				break;
			}
			
			if (shuttle.remove(stopName))
			{
				std::cout << "\nStop removed sucessfull.\n";
			}
			else
			{
				std::cout << "\nNo stop with that name was found.\n";
			}
		}
		else if (choice == "5")
		{
			std::string filename;

			std::cout << "\nEnter the filename to save to: ";
			if (!std::getline(std::cin, filename))
			{
				break;
			}

			if (shuttle.save(filename))
			{
				std::cout << "\nItinerary saved successfully.\n";
			}
			else
			{
				std::cout << "\nCould not be saved.";
			}
		}
		else
		{
			std::cout << "\nOut of all the options, you choose that huh?\n";
		}	


	} while (choice != "6");
	



	/*shuttle.display();

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

	if (shuttle.remove("Arrival Platform")) // remove stop by name
	{
		std::cout << "\nStop removed successfully.\n";
	}
	else
	{
		std::cout << "\nNo stop with that name found.\n";
	}

	shuttle.display();

	if (shuttle.save("itinerary.txt"))
	{
		std::cout << "\nItinerary saved successfully.\n\n";
	}
	else
	{
		std::cout << "\nCould not save the itinerary.\n\n";
	}
	*/
	
	return 0;
}
