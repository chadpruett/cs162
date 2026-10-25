#include <iostream>
#include <fstream>    // For file input/output operations
#include <cstring>    // For string comparison functions
using namespace std;

// adding a struct pixel to hold three RGB integers
struct Pixel
{
	int red;
	int green;
	int blue;
};

// Define a structure to hold image data
// P1 is a simple binary image format (black and white only)
struct P3 {
  int width;         // Width of the image in pixels
  int height;        // Height of the image in pixels
  Pixel** pixels;      // 2D dynamic array to store pixel values (0 or 1)
};

// Function to read pixel values from file into the image structure
void parseFile(struct P3 img, ifstream& f){
  for(int i=0; i < img.height; i++){          // Loop through each row
    for(int j=0; j < img.width; j++){         // Loop through each column
      //f >> img.pixels[i][j];                  // Read pixel value from file
	
	  f >> img.pixels[i][j].red      // read pixels from file
	  >> img.pixels[i][j].green
	  >> img.pixels[i][j].blue;
    }
    //f.ignore(256,'\n');                       // Skip to next line after reading row
  }
}

// Function to display the image contents
void printImage(struct P3 img){
  for(int i=0; i < img.height; i++){          // Loop through each row
    for(int j=0; j < img.width; j++){         // Loop through each column
      //cout << img.pixels[i][j] << " ";        // Print pixel value with space
	    std::cout << img.pixels[i][j].red << " " // read rgb values
		      << img.pixels[i][j].green << " "
		      << img.pixels[i][j].blue << " ";
    }
    cout << endl;                             // New line after each row
  }
}

//add freeImage function
void freeImage(struct P3& img)
{
	for (int i = 0; i < img.height; i++)
	{
		delete[] img.pixels[i];
	}
	delete[] img.pixels;
	img.pixels = nullptr;
}




// Function to invert the image (change 0s to 1s and vice versa)
void invertImage(struct P3 img){
  for(int i=0; i < img.height; i++){          // Loop through each row
    for(int j=0; j < img.width; j++){         // Loop through each column
      //img.pixels[i][j] = !img.pixels[i][j];   // Invert pixel value using logical NOT
      	img.pixels[i][j].red = 255 - img.pixels[i][j].red;
	img.pixels[i][j].green = 255 - img.pixels[i][j].green;
	img.pixels[i][j].blue = 255 - img.pixels[i][j].blue;
    }
  }
}

int main(){
  char preface[50];                           // Buffer to store file format identifier
  ifstream inputFile("pikachu.ppm");             // Open the image file
  if (!inputFile) // verify file opens
  {
	std::cout << "\nCould not open file.\n";
	return 1;
  }

  //struct P3 image;                            // Declare image structure
  struct P3 image;
  
  inputFile.getline(preface,50);              // Read first line (should be "P3")

  if(strcmp(preface,"P3") == 0){              // Check if file is correct format
    cout << "This is an image file so let's process it!" << endl;
    int tempWidth;
    int tempHeight;
    int rgbValue;
    inputFile >> tempWidth;                   // Read image width
    inputFile >> tempHeight;    // Read image height
    inputFile >> rgbValue;

	if (rgbValue != 255) // check the extra value in P3 file
	{
		std::cout << "\nExpected 255.\n";
		return 1;
	}

    image.width = tempWidth;
    image.height = tempHeight;

    //inputFile.ignore(256,'\n');               // Skip to next line
    
    /* Allocate memory for 2D dynamic array
    image.pixels = new int*[image.height];    // Create array of pointers
    for(int i=0; i < image.height; i++){
      image.pixels[i] = new int[image.width]; // Create each row
    }*/
	
    	// create array of pointers for rgb integers
	image.pixels = new Pixel*[image.height];
	for (int i = 0; i < image.height; i++)
	{
		image.pixels[i] = new Pixel[image.width];
	}
    
    // Process the image
    parseFile(image,inputFile);               // Read pixel data
    invertImage(image);                       // Invert the image
    printImage(image);                        // Display the result
    // call added freeImage function to free memory
    freeImage(image);

  }
  else{
    cout << "Whoops this isn't an image file, bye!" << endl;
    return 0;
  }

  // Note: There's a memory leak here as the dynamically allocated memory
  // isn't being freed. In a complete program, you'd want to delete the arrays.

  return 0;
}
