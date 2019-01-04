#include "gameObject.h"


// creating a game object, making a physics object as well as a sfml object
gameObject::gameObject()
{
	//PhysicsWorld->addPhysicsObject(Position.x , Position.y , SizeX, SizeY, Density, Friction, LinearDamping, isStatic);


	//if (outLineSize > 0)
	//{
	//	gameObjectShape.setOutlineThickness(outLineSize);
	//	gameObjectShape.setOutlineColor(outlineColour);
	//}

	
}

void gameObject::setup(b2Vec2 Position, float Rotation, float SizeX, float SizeY, sf::Color Colour, float Density, float Friction, float LinearDamping, bool isStatic)
{

	position = Position;
	rotation = Rotation;

	gameObjectShape.setSize(sf::Vector2f(SizeX * 2, SizeY * 2));
	gameObjectShape.setFillColor(Colour);
	gameObjectShape.setPosition(sf::Vector2f(Position.x, Position.y));

	sizeX = SizeX;
	sizeY = SizeY;

	density = Density;
	friction = Friction;
	linearDamping = LinearDamping;
	IsStatic = isStatic;
}

void gameObject::setNameOfObject(std::string name)
{
	gameObjectName = name;
}

gameObject::~gameObject()
{
}
