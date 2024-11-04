#include "Zombie.h"

#include <iostream>

Zombie::Zombie(float x, float y, float radius, const sf::Color& color) : Entity(x, y, radius, color)
{
	SetSpeed(50);
	SetDirection(-1, 0);
}

void Zombie::OnCollision(Entity* collidedWith)
{
}

