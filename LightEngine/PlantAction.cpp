#include "PlantAction.h"
#include "Plant.h"

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

	PVZScene* pScene = pPlant->GetScene<PVZScene>();

	const sf::Vector2f& position = pPlant->GetPosition();

	Projectile* pProjectile = pScene->CreateEntity<Projectile>(5.0f, sf::Color::Red);
	pProjectile->SetPosition(position.x, position.y);

	pPlant->mAmmo--;
}

void PlantAction_Shooting::OnEnd(Plant* pPlant)
{
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

	pPlant->mAmmo = pPlant->mMaxAmmo;
}