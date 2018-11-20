#include "gameObject.h"


// creating a game object, making a physics object as well as a sfml object
gameObject::gameObject(b2Vec2 Position, float Rotation, float SizeX, float SizeY, sf::Color Colour, float Density, float Friction, float LinearDamping, physicsSync* PhysicsWorld, bool isStatic)
{
	PhysicsWorld->addPhysicsObject(Position.x , Position.y , SizeX, SizeY, Density, Friction, LinearDamping, isStatic);

	gameObjectShape.setSize(sf::Vector2f(SizeX * 2, SizeY * 2));
	gameObjectShape.setFillColor(Colour);
	gameObjectShape.setPosition(sf::Vector2f(Position.x, Position.y));

	sizeX = SizeX;
	sizeY = SizeY;

	//if (outLineSize > 0)
	//{
	//	gameObjectShape.setOutlineThickness(outLineSize);
	//	gameObjectShape.setOutlineColor(outlineColour);
	//}

	
}

gameObject::~gameObject()
{
}
