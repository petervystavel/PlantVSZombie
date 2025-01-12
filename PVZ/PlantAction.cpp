#include "PlantAction.h"
#include "Plant.h"
#include "StateMachine.h"

#include "GameManager.h"
#include "Projectile.h"
#include "PVZScene.h"

void PlantAction_Shooting::OnStart(Plant* pPlant)
{
	mShootTimer = pPlant->mShootCadence;
}

void PlantAction_Shooting::OnUpdate(Plant* pPlant)
{
	mShootTimer += GameManager::Get()->GetDeltaTime();

	if (mShootTimer < pPlant->mShootCadence)
		return;

	mShootTimer -= pPlant->mShootCadence;

	pPlant->Shoot();
}

void PlantAction_Reloading::OnStart(Plant* pPlant)
{
	mReloadTimer = 0.f;
}

void PlantAction_Reloading::OnUpdate(Plant* pPlant)
{
	mReloadTimer += GameManager::Get()->GetDeltaTime();

	if (mReloadTimer < pPlant->mReloadDuration)
		return;

	pPlant->Reload();

	pPlant->mpStateMachine->SetState(Plant::Idle);
}