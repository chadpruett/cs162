#include "Image.h"
int main()
{
	Image image;

	if (!image.load("parse.ppm"))
	{
		return 1;
	}

	//image.invert();
	image.grayScale();
	if (!image.write("tiny-grayscale-out.ppm"))
	{
		return 1;
	}

	return 0;
}
