#include "Zombie.h"

#include "GameScene.h"

#include <iostream>

void Zombie::OnInitialize()
{
	SetTag(GameScene::Tag::ZOMBIE);

	SetDirection(-1, 0, 50);
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

void Zombie::OnDestroy()
{
	_ASSERT(mLane != -1);

	GameScene* pScene = GetScene<GameScene>();

	pScene->OnDestroyZombie(mLane);
}
