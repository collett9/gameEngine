#include "Enemy.h"


Enemy::Enemy(b2Vec2 position, int Health)
{
	setup(position, 0, 25, 25, sf::Color::Red, 0, 0, 0, 1);
	health = Health;
}

Enemy::~Enemy()
{
}
