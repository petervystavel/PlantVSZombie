#include "PlantAction.h"
#include "Plant.h"

#include "GameManager.h"
#include "Projectile.h"
#include "GameScene.h"

void PlantAction_Shooting::Start(Plant* pPlant)
{
	pPlant->mShootTimer = pPlant->mShootCadence;
}

void PlantAction_Shooting::Update(Plant* pPlant)
{
	pPlant->mShootTimer += GameManager::Get()->GetDeltaTime();

	if (pPlant->mShootTimer < pPlant->mShootCadence)
		return;

	pPlant->mShootTimer -= pPlant->mShootCadence;

	GameScene* pScene = pPlant->GetScene<GameScene>();

	const sf::Vector2f& position = pPlant->GetPosition(0.5f, 0.5f);

	Projectile* pProjectile = pScene->CreateEntity<Projectile>(5.0f, sf::Color::Red);
	pProjectile->SetPosition(position.x, position.y, 0.5f, 0.5f);

	pPlant->mAmmo--;
}

void PlantAction_Shooting::End(Plant* pPlant)
{
}

void PlantAction_Reloading::Start(Plant* pPlant)
{
}

void PlantAction_Reloading::Update(Plant* pPlant)
{
	pPlant->mReloadTimer += GameManager::Get()->GetDeltaTime();

	if (pPlant->mReloadTimer < pPlant->mReloadDuration)
		return;

	pPlant->mReloadTimer = 0.f;
	pPlant->mAmmo = pPlant->mMaxAmmo;
}