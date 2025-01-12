#include "Plant.h"

#include <string>

#include "PVZScene.h"
#include "Projectile.h"

#include "StateMachine.h"
#include "PlantAction.h"
#include "PlantCondition.h"

#include "Debug.h"

void Plant::OnInitialize()
{
	mpStateMachine = new StateMachine<Plant>(this, State::Count);

	mAmmo = mMaxAmmo;
	mAreaIndex = -1;
	SetTag(PVZScene::Tag::PLANT);

	mpStateMachine->AddAction<PlantAction_Idle>(State::Idle);
	mpStateMachine->AddAction<PlantAction_Shoot>(State::Shooting);
	mpStateMachine->AddAction<PlantAction_Reloading>(State::Reloading);

	mpStateMachine->SetState(State::Idle);
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
	const char* stateName = GetStateName((Plant::State)mpStateMachine->GetCurrentState());

	std::string ammo = std::to_string(mAmmo) + "/" + std::to_string(mMaxAmmo);

	Debug::DrawText(position.x, position.y - 50, stateName, 0.5f, 0.5f, sf::Color::Red);
	Debug::DrawText(position.x, position.y, ammo, 0.5f, 0.5f, sf::Color::Blue);

	mpStateMachine->Update();
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
