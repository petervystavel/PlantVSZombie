#pragma once

#include "Entity.h"

template<typename T>
class StateMachine;

class Plant : public Entity
{
	StateMachine<Plant>* mpStateMachine;

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
	void SetAreaIndex(int index) { mAreaIndex = index; }
	const char* GetStateName(State state) const;

	void Shoot();
	void Reload();
	
protected:
	void OnInitialize() override;
	void OnUpdate() override;

	friend class PlantAction_Idle;
	friend class PlantAction_Reloading;
	friend class PlantAction_Shooting;

	friend class PlantCondition_FullAmmo;
	friend class PlantCondition_NoAmmo;
	friend class PlantCondition_ZombieOnLane;
};
