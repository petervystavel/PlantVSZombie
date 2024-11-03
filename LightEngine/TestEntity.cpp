#include "TestEntity.h"

#include <iostream>

TestEntity::TestEntity(float x, float y, float radius, const sf::Color& color) : Entity(x, y, radius, color)
{
}

void TestEntity::OnCollision(Entity* collidedWith)
{
	Destroy();
}