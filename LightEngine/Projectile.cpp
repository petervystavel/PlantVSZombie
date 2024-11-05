#include "Projectile.h"

#include "GameScene.h"

Projectile::Projectile(float x, float y, float radius, const sf::Color& color)
	: Entity(x, y, radius, color)
{
	SetTag(GameScene::Tag::PROJECTILE);
}

void Projectile::OnUpdate()
{
	//#TODO
}

void Projectile::OnCollision(Entity* pCollidedWith)
{
	if (pCollidedWith->IsTag(GameScene::Tag::ZOMBIE))
	{
		Destroy();
	}
}