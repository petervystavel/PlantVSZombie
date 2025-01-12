#include "PlantCondition.h"

#include "PVZScene.h"

namespace PlantCondition 
{
	bool IsZombieOnLane(Plant* pPlant)
	{
		PVZScene* pScene = pPlant->GetScene<PVZScene>();

		int areaIndex = pPlant->GetAreaIndex();

		bool condition = pScene->IsZombieInArea(areaIndex);

		return condition;
	}

	bool HasNoAmmo(Plant* pPlant)
	{
		return pPlant->GetAmmo() == 0;
	}

	bool HasFullAmmo(Plant* pPlant)
	{
		return pPlant->GetAmmo() == pPlant->GetMaxAmmo();
	}
}
