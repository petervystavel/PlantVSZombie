#include "PlantCondition.h"

#include "GameScene.h"

bool PlantShootCondition::Test(Plant* pPlant)
{
	Scene* pScene = pPlant->GetScene();
	GameScene* pGameScene = dynamic_cast<GameScene*>(pScene);
	_ASSERT(pGameScene != nullptr);

	bool condition = pGameScene->IsZombieInArea(pPlant->GetAreaIndex());

	return condition;
}

bool PlantIdleCondition::Test(Plant* pPlant)
{
	Scene* pScene = pPlant->GetScene();
	GameScene* pGameScene = dynamic_cast<GameScene*>(pScene);
	_ASSERT(pGameScene != nullptr);

	bool condition = pGameScene->IsZombieInArea(pPlant->GetAreaIndex());

	return condition == false;
}
