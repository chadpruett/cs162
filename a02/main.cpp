#include "Image.h"

int main()
{
	Image image;

	if (!image.load("parse.ppm"))
	{
		return 1;
	}

	image.invert();

	if (!image.write("tiny-inverted-out.ppm"))
	{
		return 1;
	}

	return 0;
}
