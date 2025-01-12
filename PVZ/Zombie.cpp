#include "Zombie.h"

#include "PVZScene.h"

#include <iostream>

void Zombie::OnInitialize()
{
	SetTag(PVZScene::Tag::ZOMBIE);

	SetDirection(-1, 0, 50);
}

void Zombie::OnCollision(Entity* pCollidedWith)
{
	if (pCollidedWith->IsTag(PVZScene::Tag::PROJECTILE) || pCollidedWith->IsTag(PVZScene::Tag::PLANT))
	{
		Destroy();
	}
}

void Zombie::OnDestroy()
{
	_ASSERT(mLane != -1);

	PVZScene* pScene = GetScene<PVZScene>();

	pScene->OnDestroyZombie(mLane);
}
