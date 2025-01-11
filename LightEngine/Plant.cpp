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
