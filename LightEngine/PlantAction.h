#pragma once

#include "Action.h"
#include "Plant.h"

class PlantActionIdle : public Action<Plant>
{
public:
	void OnEnter(Plant* pPlant) override;
	void OnUpdate(Plant* pPlant) override;
	void OnExit(Plant* pPlant) override;
};

