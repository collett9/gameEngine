#include "physicsSync.h"


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

		//sizeVectors.push_back(b2Vec2(hitBoxSizeX, hitBoxSizeY));
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

		//sizeVectors.push_back(b2Vec2(hitBoxSizeX, hitBoxSizeY));
	}


}

void physicsSync::physicsSetup()
{
	for (int i = 0; i < positionVectors.size(); i++)
	{
		// change this later to get all of the data before it comes here
		addPhysicsObject(positionVectors[i].x, positionVectors[i].y, sizeVectors[i].x, sizeVectors[i].y, 0.5, 0.5, 0.5, false);
	}

	//setting up the position vectors for the first frame
	//positionVectors.resize(physicsBodies.size());
	//rotationVectors.resize(physicsBodies.size());

	for (int i = 0; i < physicsBodies.size(); i++)
	{
		//positionVectors[i] = physicsBodies[i]->GetPosition();
		rotationVectors[i] = physicsBodies[i]->GetAngle();
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

void physicsSync::physicsEventSolver(gameEvent* gameEventToSolve)
{

	if (gameEventToSolve->eventType == gameEvent::movement)
	{
//		eventMove move = *(eventMove*)gameEventToSolve;
		
		//float speedXTest = static_cast<float>(gameEventToSolve->dateToStore[0]);
		
		//float speedYTest = moveTest.YSpeed;

		//float speedXTest = *(float*)gameEventToSolve->voidPointerData;
		//float *speedYTest = static_cast<float*>(gameEventToSolve->voidPointerData2);

	/*	void* n = new void*;

		memcpy(n, &gameEventToSolve->voidPointerData , sizeof(float));

		float* newFloat = (float*)gameEventToSolve->voidPointerData;

		float deRef = *newFloat;*/

		float *numberFinal = (float*)gameEventToSolve->testBin->eventVoidPointerVector[0];
		float numberFinalFinal = *numberFinal;

		//eventMove* moveTest = (eventMove*)gameEventToSolve;
		//physicsBodies[gameEventToSolve->gameObjectsInvolved[0]->gameObjectId]->SetLinearVelocity() );
		gameEventToSolve->whichSubsystemsInvovlved.pop_back();
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
