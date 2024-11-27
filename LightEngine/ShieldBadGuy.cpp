#include "ShieldBadGuy.h"

#include <string>

#include "SampleScene.h"
#include "Projectile.h"

#include "ShieldBadGuyAction.h"
#include "ShieldBadGuyCondition.h"

#include "Debug.h"

ShieldBadGuy::ShieldBadGuy(float radius, const sf::Color& color) : Entity(radius, color)
, mStateMachine(this, State::Count)
{
	//ROAM
	{
		Behaviour<ShieldBadGuy>* pIdle = mStateMachine.CreateBehaviour(State::Roam);
		pIdle->AddAction(new ShieldBadGuyAction_Roam());

		//-> DEFEND
		{
			auto transition = pIdle->CreateTransition(State::Defend);

			auto condition = transition->AddCondition<ShieldBadGuyCondition_PlayerInsideDistance>();
			condition->SetDistance(200.0f);

			auto condition2 = transition->AddCondition<ShieldBadGuyCondition_PlayerIsForward>();
		}
	}

	//DEFEND
	{
		Behaviour<ShieldBadGuy>* pDefend = mStateMachine.CreateBehaviour(State::Defend);
		pDefend->AddAction(new ShieldBadGuyAction_Defend());

		//-> ROAM
		{
			auto transition = pDefend->CreateTransition(State::Roam);

			auto condition = transition->AddCondition<ShieldBadGuyCondition_PlayerInsideDistance>();
			condition->expected = false;
			condition->SetDistance(200.0f);
		}

		//-> ROAM
		{
			auto transition = pDefend->CreateTransition(State::Roam);

			auto condition = transition->AddCondition<ShieldBadGuyCondition_PlayerIsForward>();
			condition->expected = false;
		}
	}

}

const char* ShieldBadGuy::GetStateName(State state) const
{
	switch (state)
	{
	case Defend: return "Defend";
	case Roam: return "Roam";
	case Attack: return "Attack";
	default: return "Unknown";
	}
}

void ShieldBadGuy::OnUpdate()
{
	const sf::Vector2f& position = GetPosition();
	const char* stateName = GetStateName((ShieldBadGuy::State)mStateMachine.GetCurrentState());

	Debug::DrawText(position.x, position.y - 50, stateName, 0.5f, 0.5f, sf::Color::Red);
	// Debug::DrawText(position.x, position.y, ammo, 0.5f, 0.5f, sf::Color::Blue);

	mStateMachine.Update();
}

void ShieldBadGuy::OnCollision(Entity* collidedWith)
{
}

void ShieldBadGuy::SetState(State state)
{
	mStateMachine.SetState(state);
}
