#pragma once

#include "Condition.h"
#include "Plant.h"

class PlantShootCondition : public Condition<Plant>
{
public:
	bool Test(Plant* owner) override;
};

class PlantIdleCondition : public Condition<Plant>
{
public:
	bool Test(Plant* owner) override;
};