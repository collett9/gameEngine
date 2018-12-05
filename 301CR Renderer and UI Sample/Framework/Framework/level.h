#pragma once
#include <vector>
#include <iostream>
#include <SFML\Graphics.hpp>
#include <string>

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

	void setupImage(std::string fileName);


private:
	float sizeBetweenObjects = 50;
};

