#pragma once
#include <SFML\Graphics.hpp>
#include "Box2D\Box2D.h"
#include <string>
#include "physicsSync.h"
#include <iostream>
#include "gameObject.h"
#include <vector>
#include <glm\glm.hpp>
#include "renderer.h"
#include "gameEvent.h"
#include "eventMove.h"

class game
{
public:
	sf::RectangleShape groundShape;
	sf::RectangleShape texturedShape;
	sf::CircleShape shape = sf::CircleShape(100.f);


	
	//physicsSync test = physicsSync(0.0f, 0.0f);

	physicsSync *physics = nullptr;

	renderer *rendererGame = nullptr;

	bool isGameWindowOpen;


	std::vector <gameObject*> gameObjectsVector;
	std::vector <gameEvent*> gameEventsVector;

	float32 timeStep = 1.0f / 60.0f;

	int32 velocityIterations = 6;
	int32 positionIterations = 2;

	sf::Event e;

	void setUp(std::string windowName, int Width, int Height);
	void update();
	void eventHandler();
	void inputHandler();
	void render();

	game();
	~game();
};

