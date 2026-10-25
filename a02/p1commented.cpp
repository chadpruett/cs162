#include <iostream>
#include <fstream>    // For file input/output operations
#include <cstring>    // For string comparison functions
using namespace std;

// Define a structure to hold image data
// P1 is a simple binary image format (black and white only)
struct P1 {
  int width;         // Width of the image in pixels
  int height;        // Height of the image in pixels
  int** pixels;      // 2D dynamic array to store pixel values (0 or 1)
};

// Function to read pixel values from file into the image structure
void parseFile(struct P1 img, ifstream& f){
  for(int i=0; i < img.height; i++){          // Loop through each row
    for(int j=0; j < img.width; j++){         // Loop through each column
      f >> img.pixels[i][j];                  // Read pixel value from file
    }
    f.ignore(256,'\n');                       // Skip to next line after reading row
  }
}

// Function to display the image contents
void printImage(struct P1 img){
  for(int i=0; i < img.height; i++){          // Loop through each row
    for(int j=0; j < img.width; j++){         // Loop through each column
      cout << img.pixels[i][j] << " ";        // Print pixel value with space
    }
    cout << endl;                             // New line after each row
  }
}

// Function to invert the image (change 0s to 1s and vice versa)
void invertImage(struct P1 img){
  for(int i=0; i < img.height; i++){          // Loop through each row
    for(int j=0; j < img.width; j++){         // Loop through each column
      img.pixels[i][j] = !img.pixels[i][j];   // Invert pixel value using logical NOT
    }
  }
}

int main(){
  char preface[50];                           // Buffer to store file format identifier
  ifstream inputFile("test.ppm");             // Open the image file

  struct P1 image;                            // Declare image structure
  
  inputFile.getline(preface,50);              // Read first line (should be "P1")
  if(strcmp(preface,"P1") == 0){              // Check if file is correct format
    cout << "This is an image file so let's process it!" << endl;
    int tempWidth;
    int tempHeight;
    inputFile >> tempWidth;                   // Read image width
    inputFile >> tempHeight;                  // Read image height
    image.width = tempWidth;
    image.height = tempHeight;
    
    inputFile.ignore(256,'\n');               // Skip to next line
    
    // Allocate memory for 2D dynamic array
    image.pixels = new int*[image.height];    // Create array of pointers
    for(int i=0; i < image.height; i++){
      image.pixels[i] = new int[image.width]; // Create each row
    }
    
    // Process the image
    parseFile(image,inputFile);               // Read pixel data
    invertImage(image);                       // Invert the image
    printImage(image);                        // Display the result
  }
  else{
    cout << "Whoops this isn't an image file, bye!" << endl;
    return 0;
  }

  // Note: There's a memory leak here as the dynamically allocated memory
  // isn't being freed. In a complete program, you'd want to delete the arrays.

  return 0;
}
