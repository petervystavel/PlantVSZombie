#include "PlantAction.h"
#include "Plant.h"

void PlantActionShooting::Start(Plant* pPlant)
{
	pPlant->ClearShootTimer();
}

void PlantActionShooting::Update(Plant* pPlant)
{
	pPlant->TryShoot();
}

void PlantActionShooting::End(Plant* pPlant)
{
}