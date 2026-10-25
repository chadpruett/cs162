#include "Image.h"
#include <iostream>

int main()
{
	char inputName[250];
	char outputName[250];


	std::cout << "\nInput filename: ";
	std::cin.getline(inputName, 250);

	Image image;

	if (!image.load(inputName))
	{
		return 1;
	}

	int choice = 0;

	std::cout << "\nChoose a transformation\n"
		<< "\n1.Invert\n2.Grayscale\n"
		<< ">> ";
	std::cin >> choice;


	if(!std::cin)
	{
		std::cout << "\nInvalid choice!\n";
		return 1;
	}
	if (choice == 1)
	{
		image.invert();
	}
	else if (choice == 2)
	{
		image.grayScale();
	}
	else
	{
		std::cout << "\nInvalid choice!\n";
		return 1;
	}

	std::cin.ignore(10000, '\n');

	std::cout << "\nOutput filename: ";
	std::cin.getline(outputName, 250);

	if (!image.write(outputName))
	{
		return 1;
	}

	std::cout << "\nImage written successfully.\n";
	return 0;
}
