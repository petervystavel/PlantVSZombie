#pragma once

#include "Entity.h"

class Projectile : public Entity
{
protected:
	void OnInitialize() override;
	void OnUpdate() override;
	void OnCollision(Entity* pCollidedWith) override;
};

