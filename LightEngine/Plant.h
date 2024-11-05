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

		Count
	};

	float mShootCadence = 1.0f;
	float mShootTimer = 0.0f;
	int mAreaIndex;

public:
	Plant(float x, float y, float radius, const sf::Color& color);

	void SetAreaIndex(int index) { mAreaIndex = index; }
	int GetAreaIndex() { return mAreaIndex; }

	void OnUpdate() override;
	void OnCollision(Entity* pCollidedWith) override;
	
	void TryShoot();
	void ClearShootTimer();
};