#pragma once

#include "Action.h"
#include "Plant.h"

class PlantAction_Idle : public Action<Plant>
{
public:
	void OnStart(Plant* pPlant) override {}
	void OnUpdate(Plant* pPlant) override {}
	void OnEnd(Plant* pPlant) override {}
};

class PlantAction_Shooting : public Action<Plant>
{
	float mShootTimer = 0.0f;

public:
	void OnStart(Plant* pPlant) override;
	void OnUpdate(Plant* pPlant) override;
	void OnEnd(Plant* pPlant) override {};
};

class PlantAction_Reloading : public Action<Plant>
{
	float mReloadTimer = 0.0f;

public:
	void OnStart(Plant* pPlant) override;
	void OnUpdate(Plant* pPlant) override;
	void OnEnd(Plant* pPlant) override {};

	friend Plant;
};