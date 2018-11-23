#pragma once
#include "gameEvent.h"
class eventMove :
	public gameEvent
{
public:
	eventMove(float xSpeed, float ySpeed);
	~eventMove();
};

