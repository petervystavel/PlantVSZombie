#include "PlantCondition.h"

#include "GameScene.h"

bool PlantCondition_ZombieOnLane::OnTest(Plant* pPlant)
{
	GameScene* pScene = pPlant->GetScene<GameScene>();
	
	int areaIndex = pPlant->GetAreaIndex();

	bool condition = pScene->IsZombieInArea(areaIndex);

	return condition;
}

bool PlantCondition_NoAmmo::OnTest(Plant* pPlant)
{
	return pPlant->GetAmmo() == 0;
}

bool PlantCondition_FullAmmo::OnTest(Plant* pPlant)
{
	return pPlant->GetAmmo() == 6;
}
