#pragma once
#include "Entity.h"

class DummyEntity : public Entity
{
public:
	DummyEntity(float radius, const sf::Color& color)
		: Entity(radius, color)
	{
	}

	void OnCollision(Entity* other) override;
};

