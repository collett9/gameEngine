#include "gameObject.h"



void gameObject::renderCreation(sf::Vector2f size, sf::Color colour, sf::Vector2f position, float outLineSize, sf::Color outlineColour)
{

	gameObjectShape.setSize(size); 
	gameObjectShape.setFillColor(colour); 
	gameObjectShape.setPosition(position);

	if (outLineSize > 0)
	{
		gameObjectShape.setOutlineThickness(outLineSize) ;
		gameObjectShape.setOutlineColor(outlineColour);
	}

}

void gameObject::physicsCreation(float positionX, float positionY, float sizeX, float sizeY, float desnity, float friction, float linearDamping, physicsSync physicsWorld)
{
	physicsWorld.addPhysicsObject(positionX, positionY, sizeX, sizeY, desnity, friction, linearDamping);

}

gameObject::gameObject(b2Vec2 Position, float Rotation, float SizeX, float SizeY, sf::Color Colour, float Density, float Friction, float LinearDamping, physicsSync* PhysicsWorld)
{
	PhysicsWorld->addPhysicsObject(Position.x, Position.y, SizeX, SizeY, Density, Friction, LinearDamping);

	gameObjectShape.setSize(sf::Vector2f(SizeX * 2, SizeY * 2));
	gameObjectShape.setFillColor(Colour);
	gameObjectShape.setPosition(sf::Vector2f(Position.x - SizeX, Position.y - SizeY));

	//if (outLineSize > 0)
	//{
	//	gameObjectShape.setOutlineThickness(outLineSize);
	//	gameObjectShape.setOutlineColor(outlineColour);
	//}

	
}

gameObject::~gameObject()
{
}
