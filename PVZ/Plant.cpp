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

	mAreaIndex = -1;
	mAmmo = mMaxAmmo;

	SetTag(PVZScene::Tag::PLANT);

	//IDLE
	{
		Action<Plant>* pIdle = mpStateMachine->CreateAction<PlantAction_Idle>(State::Idle);

		//-> SHOOTING
		{
			auto transition = pIdle->CreateTransition(State::Shooting);

			auto condition = transition->AddCondition<PlantCondition_ZombieOnLane>();
		}

		//-> RELOADING
		{
			auto transition = pIdle->CreateTransition(State::Reloading);

			transition->AddCondition<PlantCondition_FullAmmo>(false);
			transition->AddCondition<PlantCondition_ZombieOnLane>(false);
		}
	}

	//SHOOTING
	{
		Action<Plant>* pShooting = mpStateMachine->CreateAction<PlantAction_Shooting>(State::Shooting);

		//-> IDLE
		{
			auto transition = pShooting->CreateTransition(State::Idle);

			transition->AddCondition<PlantCondition_ZombieOnLane>(false);
		}

		//-> RELOADING
		{
			auto transition = pShooting->CreateTransition(State::Reloading);

			transition->AddCondition<PlantCondition_NoAmmo>();
		}
	}

	//RELOADING
	{
		Action<Plant>* pShooting = mpStateMachine->CreateAction<PlantAction_Reloading>(State::Reloading);
	}

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

void Plant::OnUpdate()
{
	const sf::Vector2f& position = GetPosition();
	const char* stateName = GetStateName((Plant::State)mpStateMachine->GetCurrentState());

	std::string ammo = std::to_string(mAmmo) + "/" + std::to_string(mMaxAmmo);

	Debug::DrawText(position.x, position.y - 50, stateName, 0.5f, 0.5f, sf::Color::Red);
	Debug::DrawText(position.x, position.y, ammo, 0.5f, 0.5f, sf::Color::Blue);

	mpStateMachine->Update();
}
