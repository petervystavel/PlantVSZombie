#pragma once

#include "Entity.h"
#include "StateMachine.h"

class Plant : public Entity
{
	StateMachine<Plant> mStateMachine;

	enum State 
	{
		Idle,
		Shooting,
		Reloading,
	};;


public:
	Plant(float x, float y, float radius, const sf::Color& color);

	void OnUpdate() override {};
	void OnCollision(Entity* pCollidedWith) override;
};