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

	int mAmmo;
	int mMaxAmmo = 6;

	float mShootCadence = 1.0f;
	
	float mReloadDuration = 2.0f;
	
	int mAreaIndex;

public:
	Plant(float radius, const sf::Color& color);

	void SetAreaIndex(int index) { mAreaIndex = index; }
	int GetAreaIndex() { return mAreaIndex; }
	const char* GetStateName(State state) const;
	int GetAmmo() { return mAmmo; }

protected:
	void OnUpdate() override;
	void OnCollision(Entity* pCollidedWith) override;

	friend class PlantAction_Idle;
	friend class PlantAction_Reloading;
	friend class PlantAction_Shooting;
};
