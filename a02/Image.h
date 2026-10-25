#ifndef IMAGE_H
#define IMAGE_H

struct Pixel
{
	int red;
	int green;
	int blue;
};

class Image
{
	private:
		int width;
		int height;
		Pixel** pixels;

	public:
		Image();
		~Image();

		Image(const Image&) = delete;
		Image& operator = (const Image&) = delete;

		bool load(const char file[]);
		void invert();
		bool write(const char fileName[]) const;
		void grayScale();
};

#endif
