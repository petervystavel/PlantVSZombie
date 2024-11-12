#include "Zombie.h"

#include "GameScene.h"

#include <iostream>

Zombie::Zombie(float radius, const sf::Color& color) : Entity(radius, color)
{
	SetTag(GameScene::Tag::ZOMBIE);

	GoToDirection(-1, 0, 50);
}

void Zombie::OnCollision(Entity* pCollidedWith)
{
	if (pCollidedWith->IsTag(GameScene::Tag::PROJECTILE))
	{
		Destroy();
	}

	if (pCollidedWith->IsTag(GameScene::Tag::PLANT))
	{
		Destroy();
	}
}

