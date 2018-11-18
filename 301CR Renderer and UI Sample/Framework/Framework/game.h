#pragma once
#include <SFML\Graphics.hpp>
#include "Box2D\Box2D.h"
#include <string>
#include "physicsSync.h"
#include <iostream>
#include "gameObject.h"
#include <vector>

class game
{
public:
	sf::RectangleShape groundShape;
	sf::RectangleShape texturedShape;
	sf::CircleShape shape = sf::CircleShape(100.f);


	sf::RenderWindow* gameWindow;
	//physicsSync test = physicsSync(0.0f, 0.0f);

	physicsSync *test = nullptr;


	std::vector <gameObject> gameObjectsVector;

	float32 timeStep = 1.0f / 60.0f;

	int32 velocityIterations = 6;
	int32 positionIterations = 2;

	sf::Event e;

	void setUp(std::string windowName, int Width, int Height);
	void update();
	void eventHandler();
	void render();

	game();
	~game();
};

