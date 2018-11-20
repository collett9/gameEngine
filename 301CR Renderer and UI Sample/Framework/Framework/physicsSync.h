#pragma once
#include <vector>
#include "Box2D\Box2D.h"

class physicsSync
{
public:
	float gravityX, gravityY;

	b2World* world = new b2World(b2Vec2(gravityX, gravityY));

	std::vector <b2Vec2> positionVectors;
	std::vector <float> rotationVectors;
	std::vector <b2Vec2> sizeVectors;

	std::vector <b2Body*> physicsBodies;

	void physicsSetup();

	void addPhysicsObject(float positionX, float positionY, float hitBoxSizeX, float hitBoxSizeY, float density, float friction, float linearDamping, bool isStatic);

	void physicsUpdate(float32 timeStep, int32 velocityIterations, int32 positionIterations);


	physicsSync(float GravityX, float GravityY);

	

	~physicsSync();
};

