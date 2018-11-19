#include "physicsSync.h"

//b2BodyDef bodyDef;
//bodyDef.type = b2_dynamicBody;
//bodyDef.position.Set(0.0f, 4.0f);
//b2Body* body = world.CreateBody(&bodyDef);
//
//b2PolygonShape dynamicBox;
//dynamicBox.SetAsBox(1.0f, 1.0f);
//
//
//b2FixtureDef fixtureDef;
//fixtureDef.shape = &dynamicBox;
//fixtureDef.density = 1.0f;
//fixtureDef.friction = 0.0f;
//body->CreateFixture(&fixtureDef);
//body->SetLinearDamping(0.5f);

void physicsSync::physicsSetup()
{
	//b2BodyDef groundBodyDef;

	//b2Body* groundBody = world->CreateBody(&groundBodyDef);

	//groundBodyDef.position.Set(0.0f, -10.0f);
	//b2PolygonShape groundBox;
	//groundBox.SetAsBox(50.0f, 100.0f);
	//groundBody->CreateFixture(&groundBox, 0.0f);

	/// temp removed ground setup!!

	//b2BodyDef groundBodyDef;
	//groundBodyDef.position.Set(500.0f, 500.0f);
	////groundBodyDef.type = b2_dynamicBody;
	//physicsBodies.push_back( world->CreateBody(&groundBodyDef));

	//
	//b2PolygonShape groundBox;
	//groundBox.SetAsBox(50.0f, 50.0f);
	//physicsBodies.back()->CreateFixture(&groundBox, 0.0f);

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
void physicsSync::addPhysicsObject(float positionX, float positionY, float hitBoxSizeX, float hitBoxSizeY, float density, float friction, float linearDamping)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(positionX , positionY);
	physicsBodies.push_back (world->CreateBody(&bodyDef));

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
