#include "Zombie.h"

#include "GameScene.h"

#include <iostream>

Zombie::Zombie(float x, float y, float radius, const sf::Color& color) : Entity(x, y, radius, color)
{
	SetTag(GameScene::Tag::ZOMBIE);

	SetSpeed(50);
	SetDirection(-1, 0);
}

void Zombie::OnCollision(Entity* pCollidedWith)
{
	if (pCollidedWith->IsTag(GameScene::Tag::PROJECTILE))
	{
		Destroy();
	}
}

