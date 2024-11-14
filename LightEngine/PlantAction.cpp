#include "PlantAction.h"
#include "Plant.h"

#include "GameManager.h"
#include "Projectile.h"
#include "GameScene.h"

void PlantAction_Shooting::Start(Plant* pPlant)
{
	mShootTimer = pPlant->mShootCadence;
}

void PlantAction_Shooting::Update(Plant* pPlant)
{
	mShootTimer += GameManager::Get()->GetDeltaTime();

	if (mShootTimer < pPlant->mShootCadence)
		return;

	mShootTimer -= pPlant->mShootCadence;

	GameScene* pScene = pPlant->GetScene<GameScene>();

	const sf::Vector2f& position = pPlant->GetPosition();

	Projectile* pProjectile = pScene->CreateEntity<Projectile>(5.0f, sf::Color::Red);
	pProjectile->SetPosition(position.x, position.y);

	pPlant->mAmmo--;
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

	pPlant->mAmmo = pPlant->mMaxAmmo;
}