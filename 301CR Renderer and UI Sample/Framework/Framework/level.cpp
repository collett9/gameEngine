#include "level.h"


level::level(int SizeX, int SizeY)
{
	levelData.resize(SizeX);
	for (int i = 0; i < SizeX; i++)
	{
		levelData[i].resize(SizeX);

	}



	for (int i = 0; i < SizeX; i++)
	{
		for (int j = 0; j < SizeY; j++)
		{
			if (i == 0 || i == SizeX-1 || j == 0 || j == SizeY-1)
			{
				levelData[i][j].whichChunk = wall;
			}

			else
			{
				levelData[i][j].whichChunk = nothing;
			}

			levelData[i][j].actualPositionX = i * sizeBetweenObjects;
			levelData[i][j].actualPositionY = j * sizeBetweenObjects;
		}
	}

}

level::~level()
{
}
