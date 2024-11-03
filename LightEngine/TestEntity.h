#pragma once

#include "Entity.h"
#include <SFML/Graphics/Color.hpp>

class TestEntity : public Entity
{
public:
	TestEntity(float x, float y, float radius, const sf::Color& color);
	void InternalUpdate() override {};
	void OnCollision(Entity* collidedWith) override;
};

