#pragma once

#include "Action.h"
#include "Plant.h"

class PlantAction_Idle : public Action<Plant>
{
public:
	void Start(Plant* pPlant) override {}
	void Update(Plant* pPlant) override {}
	void End(Plant* pPlant) override {}
};

class PlantAction_Shooting : public Action<Plant>
{
public:
	void Start(Plant* pPlant) override;
	void Update(Plant* pPlant) override;
	void End(Plant* pPlant) override;
};

class PlantAction_Reloading : public Action<Plant>
{
public:
	void Start(Plant* pPlant) override;
	void Update(Plant* pPlant) override;
	void End(Plant* pPlant) override {};
};