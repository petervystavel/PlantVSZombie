#include "Plant.h"

#include <string>

#include "GameScene.h"
#include "Projectile.h"

#include "PlantAction.h"
#include "PlantCondition.h"

#include "Debug.h"

Plant::Plant(float radius, const sf::Color& color) : Entity(radius, color)
	, mStateMachine(this, State::Count)
{
	mAreaIndex = -1;
	mAmmo = mMaxAmmo;

	SetTag(GameScene::Tag::PLANT);

	//IDLE
	{
		Behaviour<Plant>* pIdle = mStateMachine.CreateBehaviour(State::Idle);
		pIdle->AddAction(new PlantAction_Idle());

		//-> SHOOTING
		{
			auto transition = pIdle->CreateTransition(State::Shooting);
			
			auto condition = transition->AddCondition<PlantCondition_ZombieOnLane>();
		}

		//-> RELOADING
		{
			auto transition = pIdle->CreateTransition(State::Reloading);

			auto condition1 = transition->AddCondition<PlantCondition_FullAmmo>();
			condition1->expected = false;

			auto condition2 = transition->AddCondition<PlantCondition_ZombieOnLane>();
			condition2->expected = false;
		}
	}

	//SHOOTING
	{
		Behaviour<Plant>* pShooting = mStateMachine.CreateBehaviour(State::Shooting);
		pShooting->AddAction(new PlantAction_Shooting());

		//-> IDLE
		{
			auto transition = pShooting->CreateTransition(State::Idle);
			
			auto condition = transition->AddCondition<PlantCondition_ZombieOnLane>();
			condition->expected = false;
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
		pShooting->AddAction(new PlantAction_Reloading());

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
