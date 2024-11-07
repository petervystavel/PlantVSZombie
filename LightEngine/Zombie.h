#pragma once

#include "Entity.h"
#include <SFML/Graphics/Color.hpp>

class Zombie : public Entity
{
public:
	Zombie(float radius, const sf::Color& color);

	void OnUpdate() override {};
	void OnCollision(Entity* pCollidedWith) override;
};
