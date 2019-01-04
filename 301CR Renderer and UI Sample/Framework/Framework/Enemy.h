#pragma once
#include "gameObject.h"
class Enemy :
	public gameObject
{
public:
	int health;

	Enemy(b2Vec2 position, int Health);
	~Enemy();
};

