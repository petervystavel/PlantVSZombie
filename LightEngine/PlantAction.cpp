#include "PlantAction.h"
#include "Plant.h"

void PlantAction_Shooting::Start(Plant* pPlant)
{
	pPlant->ClearShootTimer();
}

void PlantAction_Shooting::Update(Plant* pPlant)
{
	pPlant->OnAction_TryShoot();
}

void PlantAction_Shooting::End(Plant* pPlant)
{
}

void PlantAction_Reloading::Start(Plant* pPlant)
{
}

void PlantAction_Reloading::Update(Plant* pPlant)
{
	pPlant->OnAction_Reload();
}