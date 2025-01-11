#include "Plant.h"

#include <string>

#include "PVZScene.h"
#include "Projectile.h"

#include "PlantAction.h"
#include "PlantCondition.h"

#include "Debug.h"

Plant::Plant() :
	mStateMachine(this, State::Count)
{
	mAreaIndex = -1;
	mAmmo = mMaxAmmo;

	SetTag(PVZScene::Tag::PLANT);

	mStateMachine.AddAction<PlantAction_Idle>(State::Idle);
	mStateMachine.AddAction<PlantAction_Shooting>(State::Shooting);
	mStateMachine.AddAction<PlantAction_Reloading>(State::Reloading);

	mStateMachine.SetState(State::Idle);
}

const char* Plant::GetStateName(State state) const
{
	switch (state)
	{
	case Idle: return "Idle";
	case Shooting: return "Shooting";
	case Reloading: return "Reloading";
	default: return "Unknown";
	}
}

void Plant::OnUpdate()
{
	const sf::Vector2f& position = GetPosition();
	const char* stateName = GetStateName((Plant::State)mStateMachine.GetCurrentState());

	std::string ammo = std::to_string(mAmmo) + "/" + std::to_string(mMaxAmmo);

	Debug::DrawText(position.x, position.y - 50, stateName, 0.5f, 0.5f, sf::Color::Red);
	Debug::DrawText(position.x, position.y, ammo, 0.5f, 0.5f, sf::Color::Blue);

	mStateMachine.Update();
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
