#include "eventMove.h"


eventMove::eventMove(float xSpeed, float ySpeed, gameObject* gameObjectInvolved)
{
	whichSubsystemsInvovlved.push_back(Physics);
	//whichSubsystemsInvovlved.push_back(Renderer);

	nameOfEvent = "movement";
	eventType = movement;

	gameObjectsInvolved.push_back(gameObjectInvolved);

	XSpeed = xSpeed;
	YSpeed = ySpeed;

}

eventMove::~eventMove()
{
}