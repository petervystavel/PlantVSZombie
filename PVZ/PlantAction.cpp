#include "PlantAction.h"
#include "Plant.h"

#include "GameManager.h"
#include "Projectile.h"
#include "PVZScene.h"
#include "PlantCondition.h"

void PlantAction_Idle::Update(Plant* pPlant)
{
	/* TODO */

	// Transition to shooting
	// Transition to reloading
}

void PlantAction_Shooting::Start(Plant* pPlant)
{
	/* TODO */

	// Start timer
}

void PlantAction_Shooting::Update(Plant* pPlant)
{
	/* TODO */

	// Shoot

	// Transition to idle
	// Transition to reloading
}

void PlantAction_Reloading::Start(Plant* pPlant)
{
	/* TODO */

	// Start timer
}

void PlantAction_Reloading::Update(Plant* pPlant)
{
	/* TODO */

	// Transition to idle
}