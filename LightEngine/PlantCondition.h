#pragma once

#include "Condition.h"
#include "Plant.h"

class PlantCondition_ZombieOnLane : public Condition<Plant>
{
public:
	bool Test(Plant* owner) override;
};

class PlantCondition_NoZombieOnLane : public Condition<Plant>
{
public:
	bool Test(Plant* owner) override;
};

class PlantCondition_NoAmmo : public Condition<Plant>
{
public:
	bool Test(Plant* owner) override;
};

class PlantCondition_FullAmmo : public Condition<Plant>
{
public:
	bool Test(Plant* owner) override;
};

class PlantCondition_NoFullAmmo : public Condition<Plant>
{
public:
	bool Test(Plant* owner) override;
};
