#include "Image.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>

Image::Image()
{
	width = 0;
	height = 0;
	pixels = nullptr;
}

Image::~Image()
{
	for (int i = 0; i < height; i++)
	{
		delete[] pixels[i];
	}
	delete[] pixels;
	pixels = nullptr;
}

bool Image::load(const char file[])
{
	std::ifstream inputFile(file);
	if (!inputFile)
	{
		std::cout << "\nFile could not be opened!\n";
		return false;
	}

	char format[3];
	inputFile >> std::setw(3) >> format;

	if (!inputFile || (strcmp(format, "P1") != 0
		&& strcmp(format, "P3") != 0))
	{
		std::cout << "\nUnsupported format.\n";
		return false;
	}

	if (!(inputFile >> width >> height) ||
	width < 1 || width > 1024 ||
	height < 1 || height > 1024)
	{
		std::cout << "\nInvalid image size.\n";
		width = 0;
		height = 0;
		return false;
	}

	if (strcmp(format, "P3") == 0)
	{
		int maxVal;
		
		if (!(inputFile >> maxVal) || maxVal != 255)
		{
			std::cout << "\nExpected a maximum channel value of 255.\n";
			width = 0;
			height = 0;
			return false;
		}
	}

	pixels = new Pixel*[height];

	for (int row = 0; row < height; row++)
	{
		pixels[row] = new Pixel[width];
	}

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			if (strcmp(format, "P3") == 0)
			{
				inputFile >> pixels[row][col].red
					  >> pixels[row][col].green
					  >> pixels[row][col].blue;
			}
			else
			{
				int value;
				inputFile >> value;

				if (value == 0)
				{
					pixels[row][col].red = 255;
					pixels[row][col].green = 255;
					pixels[row][col].blue = 255;
				}
				else
				{
					pixels[row][col].red = 0;
					pixels[row][col].green = 0;
					pixels[row][col].blue = 0;
				}

			}
		}
	}
	
	return true;
}

void Image::invert()
{
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			pixels[row][col].red = 255 -pixels[row][col].red;
			pixels[row][col].green = 255 -pixels[row][col].green;
			pixels[row][col].blue = 255 -pixels[row][col].blue;
		}
	}
}

bool Image::write(const char fileName[]) const
{
	std::ofstream outFile(fileName);

	if (!outFile)
	{
		std::cout << "\nFile could not open!\n";
		return false;
	}

	outFile << "P3\n"
	<< width << " " << height << "\n"
	<< "255\n";

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			outFile << pixels[row][col].red << " "
				<< pixels[row][col].green << " "
				<< pixels[row][col].blue << " ";
		}
		
		outFile << '\n';
	}
	
	return true;
}

void Image::grayScale()
{
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			int avg = (pixels[row][col].red
				+ pixels[row][col].green
				+ pixels[row][col].blue) / 3;

			pixels[row][col].red = avg;
			pixels[row][col].green = avg;
			pixels[row][col].blue = avg;
		}
	}

}
