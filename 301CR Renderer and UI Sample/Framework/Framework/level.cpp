#include "level.h"

//void read_image(const char* img)
//{
//	FREE_IMAGE_FORMAT fif = FreeImage_GetFIFFromFilename(img);
//	FIBITMAP *bmp = FreeImage_Load(fif, img);
//
//	unsigned width = FreeImage_GetWidth(bmp);
//	unsigned height = FreeImage_GetHeight(bmp);
//	int bpp = FreeImage_GetBPP(bmp);
//
//	FIBITMAP* bitmap = FreeImage_Allocate(width, height, bpp);
//	RGBQUAD color; FreeImage_GetPixelColor(bitmap, 10, 10, &color);
//
//}




level::level(int SizeX, int SizeY)
{
	levelData.resize(SizeX);
	for (int i = 0; i < SizeX; i++)
	{
		levelData[i].resize(SizeX);

	}

	setupImage("test.png");



	for (int i = 0; i < SizeX; i++)
	{
		for (int j = 0; j < SizeY; j++)
		{
			if (i == 0 || i == SizeX-1 || j == 0 || j == SizeY-1)
			{
				//levelData[i][j].whichChunk = wall;
			}

			/*else
			{
				levelData[i][j].whichChunk = nothing;
			}*/

			levelData[i][j].actualPositionX = i * sizeBetweenObjects;
			levelData[i][j].actualPositionY = j * sizeBetweenObjects;
		}
	}

	

}

level::~level()
{
}

// goes through an image and fetches colour data, translating it into map data
void level::setupImage(std::string fileName)
{
	sf::Image testImage;

	testImage.loadFromFile(fileName);
	
	sf::Vector2f testVec2 = sf::Vector2f(testImage.getSize());


	for (int i = 0; i < testVec2.x; i++)
	{
		for (int j = 0; j < testVec2.y; j++)
		{
			sf::Color tempColour = testImage.getPixel(i, j);

			float temp1 = (float)tempColour.r;
			float temp2 = (float)tempColour.g;
			float temp3 = (float)tempColour.b;

			sf::Vector3f tempColourVector = sf::Vector3f(temp1, temp2, temp3);

			if (tempColourVector == sf::Vector3f(0.0f, 0.0f, 0.0f))
			{
				levelData[i][j].whichChunk = wall;
			}

			else if(tempColourVector == sf::Vector3f(255.0f, 0.0f, 0.0f))
			{
				levelData[i][j].whichChunk = playerLocation;
			}

			else
			{
				levelData[i][j].whichChunk = nothing;
			}
		}
	}

	


}
