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

	//IDLE
	{
		Behaviour<Plant>* pIdle = mStateMachine.CreateBehaviour(State::Idle);
		pIdle->AddAction<PlantAction_Idle>();

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
		Behaviour<Plant>* pShooting = mStateMachine.CreateBehaviour(State::Shooting);
		pShooting->AddAction<PlantAction_Shooting>();

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
		Behaviour<Plant>* pShooting = mStateMachine.CreateBehaviour(State::Reloading);
		pShooting->AddAction<PlantAction_Reloading>();

		//-> IDLE
		{
			auto transition = pShooting->CreateTransition(State::Idle);
			
			auto condition = transition->AddCondition<PlantCondition_FullAmmo>();
		}
	}

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

void Plant::OnCollision(Entity* collidedWith)
{
}
