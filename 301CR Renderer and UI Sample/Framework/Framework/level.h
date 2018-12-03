#pragma once
#include <vector>

class level
{
public:

	int sizeX;
	int sizeY;


	enum chunk
	{
		nothing,
		wall,
		playerLocation
	};

	struct levelChunk
	{
		chunk whichChunk;
		int positionInGridX;
		int positionInGridY;
		float actualPositionX;
		float actualPositionY;

	};

	std::vector <std::vector<levelChunk>> levelData;



	level(int SizeX, int SizeY);
	~level();

private:
	float sizeBetweenObjects = 50;
};

