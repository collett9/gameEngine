#include "eventMove.h"


eventMove::eventMove(float xSpeed, float ySpeed)
{
	whichSubsystemsInvovlved.push_back(Physics);
	whichSubsystemsInvovlved.push_back(Renderer);

	eventType = movement;


}

eventMove::~eventMove()
{
}
