#pragma once

#include "Entity.h"
#include <SFML/Graphics/Color.hpp>

class Zombie : public Entity
{
	int mLane = -1;

public:
	Zombie(float radius, const sf::Color& color);

	void SetLane(int lane) { mLane = lane; }

protected:
	void OnCollision(Entity* pCollidedWith) override;
	void OnDestroy() override;
};
