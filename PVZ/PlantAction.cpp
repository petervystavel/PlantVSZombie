#include "PlantAction.h"
#include "Plant.h"

#include "GameManager.h"
#include "Projectile.h"
#include "PVZScene.h"
#include "PlantCondition.h"

void PlantAction_Idle::Update(Plant* pPlant)
{
	//TRANSITION

	/* TODO */
}

void PlantAction_Shoot::Start(Plant* pPlant)
{
	mTimerProgress = 0.0f;
}

void PlantAction_Shoot::Update(Plant* pPlant)
{
	mTimerProgress += GameManager::Get()->GetDeltaTime();
	if (mTimerProgress < pPlant->mShootCadence)
		return;

	pPlant->Shoot();
	mTimerProgress -= pPlant->mShootCadence;

	//TRANSITION

	/* TODO */
}

void PlantAction_Reloading::Start(Plant* pPlant)
{
	mTimerProgress = 0.0f;
}

void PlantAction_Reloading::Update(Plant* pPlant)
{
	mTimerProgress += GameManager::Get()->GetDeltaTime();
	if (mTimerProgress < pPlant->mReloadDuration)
		return;

	pPlant->mAmmo = pPlant->mMaxAmmo;
	
	//TRANSITION
	
	/* TODO */
}