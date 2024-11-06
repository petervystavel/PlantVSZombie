#include "Plant.h"

#include "GameScene.h"
#include "Projectile.h"

#include "PlantAction.h"
#include "PlantCondition.h"

#include "Debug.h"

Plant::Plant(float x, float y, float radius, const sf::Color& color) : Entity(x, y, radius, color)
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
			transition->AddCondition(new PlantCondition_ZombieOnLane());
		}

		//-> RELOADING
		{
			auto transition = pIdle->CreateTransition(State::Reloading);
			transition->AddCondition(new PlantCondition_NoFullAmmo());
			transition->AddCondition(new PlantCondition_NoZombieOnLane());
		}
	}

	//SHOOTING
	{
		Behaviour<Plant>* pShooting = mStateMachine.CreateBehaviour(State::Shooting);
		pShooting->AddAction(new PlantAction_Shooting());

		//-> IDLE
		{
			auto transition = pShooting->CreateTransition(State::Idle);
			transition->AddCondition(new PlantCondition_NoZombieOnLane());
		}

		//-> RELOADING
		{
			auto transition = pShooting->CreateTransition(State::Reloading);
			transition->AddCondition(new PlantCondition_NoAmmo());
		}
	}

	//RELOADING
	{
		Behaviour<Plant>* pShooting = mStateMachine.CreateBehaviour(State::Reloading);
		pShooting->AddAction(new PlantAction_Reloading());

		//-> IDLE
		{
			auto transition = pShooting->CreateTransition(State::Idle);
			transition->AddCondition(new PlantCondition_FullAmmo());
		}
	}

	mStateMachine.SetState(State::Idle);
}

void Plant::OnAction_TryShoot()
{
	mShootTimer += GameManager::Get()->GetDeltaTime();

	if (mShootTimer >= mShootCadence)
	{
		mShootTimer -= mShootCadence;

		Scene* pScene = GetScene();

		Projectile* pProjectile = pScene->CreateEntity<Projectile>(GetPosition().x, GetPosition().y, 5.0f, sf::Color::Red);
		
		pProjectile->SetSpeed(100.0f);
		pProjectile->SetDirection(1.0f, 0.0f);

		mAmmo--;
	}
}

void Plant::OnAction_Reload()
{
	mReloadTimer += GameManager::Get()->GetDeltaTime();

	if (mReloadTimer >= mReloadDuration)
	{
		mReloadTimer = 0.f;
		mAmmo = mMaxAmmo;
	}
}

void Plant::ClearShootTimer()
{
	mShootTimer = mShootCadence;
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

	Debug::DrawText(position.x, position.y - 50, stateName, 0.5f, 0.5f, sf::Color::Red);

	mStateMachine.Update();
}

void Plant::OnCollision(Entity* collidedWith)
{
}
