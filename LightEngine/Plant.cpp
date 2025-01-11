#include "Plant.h"

#include <string>

#include "PVZScene.h"
#include "Projectile.h"

#include "Debug.h"

void Plant::OnUpdate()
{
	const sf::Vector2f& position = GetPosition();

	std::string ammo = std::to_string(mAmmo) + "/" + std::to_string(mMaxAmmo);

	Debug::DrawText(position.x, position.y, ammo, 0.5f, 0.5f, sf::Color::Blue);
}

void Plant::Shoot()
{
	if (mAmmo <= 0)
		return;

	const sf::Vector2f& position = GetPosition();

	Projectile* pProjectile = CreateEntity<Projectile>(5.0f, sf::Color::Red);
	pProjectile->SetPosition(position.x, position.y);

	mAmmo--;
}

void Plant::Reload()
{
	mAmmo = mMaxAmmo;
}