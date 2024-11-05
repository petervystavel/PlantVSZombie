#pragma once

#include "Action.h"
#include "Plant.h"

class PlantActionIdle : public Action<Plant>
{
public:
	void Start(Plant* pPlant) override {}
	void Update(Plant* pPlant) override {}
	void End(Plant* pPlant) override {}
};

class PlantActionShooting : public Action<Plant>
{
public:
	void Start(Plant* pPlant) override;
	void Update(Plant* pPlant) override;
	void End(Plant* pPlant) override;
};