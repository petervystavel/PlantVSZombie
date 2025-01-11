#include "PlantAction.h"
#include "Plant.h"

#include "GameManager.h"
#include "Projectile.h"
#include "PVZScene.h"
#include "PlantCondition.h"

void PlantAction_Idle::Update(Plant* pPlant)
{
	if (PlantCondition::IsZombieOnLane(pPlant)) 
	{
		pPlant->mStateMachine.SetState(Plant::State::Shooting);
		return;
	}

	if (PlantCondition::HasFullAmmo(pPlant) == false && PlantCondition::IsZombieOnLane(pPlant) == false)
	{
		pPlant->mStateMachine.SetState(Plant::State::Reloading);
		return;
	}
}

void PlantAction_Shooting::Start(Plant* pPlant)
{
	mShootTimer = pPlant->mShootCadence;
}

void PlantAction_Shooting::Update(Plant* pPlant)
{
	if (PlantCondition::IsZombieOnLane(pPlant) == false)
	{
		pPlant->mStateMachine.SetState(Plant::State::Idle);
		return;
	}

	if (PlantCondition::HasNoAmmo(pPlant))
	{
		pPlant->mStateMachine.SetState(Plant::State::Reloading);
		return;
	}

	mShootTimer += GameManager::Get()->GetDeltaTime();

	if (mShootTimer < pPlant->mShootCadence)
		return;

	mShootTimer -= pPlant->mShootCadence;

	pPlant->Shoot();
}

void PlantAction_Shooting::End(Plant* pPlant)
{
}

void PlantAction_Reloading::Start(Plant* pPlant)
{
	mReloadTimer = 0.f;
}

void PlantAction_Reloading::Update(Plant* pPlant)
{
	mReloadTimer += GameManager::Get()->GetDeltaTime();

	if (mReloadTimer < pPlant->mReloadDuration)
		return;

	pPlant->Reload();

	pPlant->mStateMachine.SetState(Plant::State::Idle);
}