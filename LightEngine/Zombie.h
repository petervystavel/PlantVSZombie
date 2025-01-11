#pragma once

#include "Entity.h"
#include <SFML/Graphics/Color.hpp>

class Zombie : public Entity
{
	int mLane = -1;

public:
	void SetLane(int lane) { mLane = lane; }

protected:
	void OnInitialize() override;
	void OnCollision(Entity* pCollidedWith) override;
};
