#include "Plant.h"

#include "GameScene.h"
#include "Projectile.h"

#include "PlantAction.h"
#include "PlantCondition.h"

Plant::Plant(float x, float y, float radius, const sf::Color& color) : Entity(x, y, radius, color)
	, mStateMachine(this, State::Count)
{
	SetTag(GameScene::Tag::PLANT);

	//IDLE
	{
		Behaviour<Plant>* pIdle = mStateMachine.CreateBehaviour(State::Idle);
		pIdle->AddAction(new PlantActionIdle());

		//-> SHOOTING
		{
			Transition<Plant>* pIdleToShooting = pIdle->CreateTransition(State::Shooting);
			pIdleToShooting->AddCondition(new PlantShootCondition());
		}
	}

	//SHOOTING
	{
		Behaviour<Plant>* pShooting = mStateMachine.CreateBehaviour(State::Shooting);
		pShooting->AddAction(new PlantActionShooting());

		//-> IDLE
		{
			Transition<Plant>* pIdleToShooting = pShooting->CreateTransition(State::Idle);
			pIdleToShooting->AddCondition(new PlantIdleCondition());
		}
	}

	mStateMachine.SetState(State::Idle);
}

void Plant::TryShoot()
{
	mShootTimer += GameManager::Get()->GetDeltaTime();

	if (mShootTimer >= mShootCadence)
	{
		mShootTimer -= mShootCadence;

		Scene* pScene = GetScene();

		Projectile* pProjectile = pScene->CreateEntity<Projectile>(GetPosition().x, GetPosition().y, 5.0f, sf::Color::Red);
		
		pProjectile->SetSpeed(100.0f);
		pProjectile->SetDirection(1.0f, 0.0f);
	}

}

void Plant::ClearShootTimer()
{
	mShootTimer = mShootCadence;
}

void Plant::OnUpdate()
{
	mStateMachine.Update();
}

void Plant::OnCollision(Entity* collidedWith)
{
}
