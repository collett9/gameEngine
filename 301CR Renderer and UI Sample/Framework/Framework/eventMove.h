#pragma once
#include "gameEvent.h"
class eventMove :
	public gameEvent
{
public:
	float XSpeed;
	float YSpeed;

	//eventMove(float xSpeed, float ySpeed);
	eventMove(float xSpeed, float ySpeed, gameObject * gameObjectInvolved);
	~eventMove();
};

