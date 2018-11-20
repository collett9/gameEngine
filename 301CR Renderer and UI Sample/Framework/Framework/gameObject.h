#pragma once
#include <vector>
#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>
#include "physicsSync.h"


class gameObject
{
public:
	int gameObjectId;

	b2Vec2 position;
	float rotation;

	float sizeY, sizeX;

	sf::RectangleShape gameObjectShape;

	//void renderCreation(sf::Vector2f size, sf::Color colour, sf::Vector2f position, float outLineSize, sf::Color outlineColour);
	//void physicsCreation(float positionX, float positionY, float sizeX, float sizeY, float desnity, float friction, float linearDamping, physicsSync physicsWorld, bool isStatic);


	gameObject(b2Vec2 Position, float Rotation, float SizeX, float SizeY, sf::Color Colour, float Density, float Friction, float LinearDamping, physicsSync * PhysicsWorld, bool isStatic);

	~gameObject();
};

