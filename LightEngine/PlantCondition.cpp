#include "PlantCondition.h"

#include "GameScene.h"

bool PlantCondition_ZombieOnLane::Test(Plant* pPlant)
{
	Scene* pScene = pPlant->GetScene();
	GameScene* pGameScene = dynamic_cast<GameScene*>(pScene);
	_ASSERT(pGameScene != nullptr);

	bool condition = pGameScene->IsZombieInArea(pPlant->GetAreaIndex());

	return condition;
}

bool PlantCondition_NoZombieOnLane::Test(Plant* pPlant)
{
	Scene* pScene = pPlant->GetScene();
	GameScene* pGameScene = dynamic_cast<GameScene*>(pScene);
	_ASSERT(pGameScene != nullptr);

	bool condition = pGameScene->IsZombieInArea(pPlant->GetAreaIndex());

	return condition == false;
}

bool PlantCondition_NoAmmo::Test(Plant* pPlant)
{
	return pPlant->GetAmmo() == 0;
}

bool PlantCondition_FullAmmo::Test(Plant* pPlant)
{
	return pPlant->GetAmmo() == 6;
}

bool PlantCondition_NoFullAmmo::Test(Plant* pPlant)
{
	return pPlant->GetAmmo() < 6;
}