#include "physicsSync.h"


void physicsSync::physicsSetup()
{
	//setting up the position vectors for the first frame
	positionVectors.resize(physicsBodies.size());
	rotationVectors.resize(physicsBodies.size());

	for (int i = 0; i < physicsBodies.size(); i++)
	{
		positionVectors[i] = physicsBodies[i]->GetPosition();
		rotationVectors[i] = physicsBodies[i]->GetAngle();
	}

}

// adds physics object to the scene, currently only adds a box ADD MORE TYPES
void physicsSync::addPhysicsObject(float positionX, float positionY, float hitBoxSizeX, float hitBoxSizeY, float density, float friction, float linearDamping, bool isStatic)
{
	if (isStatic == true)
	{
		b2BodyDef bodyDef;
		//bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(positionX, positionY);
		physicsBodies.push_back(world->CreateBody(&bodyDef));

		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox(hitBoxSizeX, hitBoxSizeY);


		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = density;
		fixtureDef.friction = friction;
		physicsBodies.back()->CreateFixture(&fixtureDef);
		physicsBodies.back()->SetLinearDamping(linearDamping);

		sizeVectors.push_back(b2Vec2(hitBoxSizeX, hitBoxSizeY));
	}

	else if (isStatic == false)
	{
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(positionX, positionY);
		physicsBodies.push_back(world->CreateBody(&bodyDef));

		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox(hitBoxSizeX, hitBoxSizeY);


		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = density;
		fixtureDef.friction = friction;
		physicsBodies.back()->CreateFixture(&fixtureDef);
		physicsBodies.back()->SetLinearDamping(linearDamping);

		sizeVectors.push_back(b2Vec2(hitBoxSizeX, hitBoxSizeY));
	}


}

// updates the physics and outputs the positions and rotations of the various physics objects
void physicsSync::physicsUpdate(float32 timeStep, int32 velocityIterations, int32 positionIterations)
{
	world->Step(timeStep, velocityIterations, positionIterations);

	positionVectors.resize(physicsBodies.size());
	rotationVectors.resize(physicsBodies.size());

	for (int i = 0; i < physicsBodies.size(); i++)
	{

		positionVectors[i] = b2Vec2(physicsBodies[i]->GetPosition().x , physicsBodies[i]->GetPosition().y );
		rotationVectors[i] = physicsBodies[i]->GetAngle();
	}

}

physicsSync::physicsSync(float GravityX, float GravityY)
{
	gravityX = GravityX;
	gravityY = GravityY;

}

physicsSync::~physicsSync()
{
}
