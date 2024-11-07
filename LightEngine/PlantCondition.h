#pragma once

#include "Condition.h"
#include "Plant.h"

class PlantCondition_ZombieOnLane : public Condition<Plant>
{
public:
	bool OnTest(Plant* owner) override;
};

class PlantCondition_NoAmmo : public Condition<Plant>
{
public:
	bool OnTest(Plant* owner) override;
};

class PlantCondition_FullAmmo : public Condition<Plant>
{
public:
	bool OnTest(Plant* owner) override;
};
