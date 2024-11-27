#pragma once

#include "Entity.h"
#include "StateMachine.h"

class ShieldBadGuy : public Entity
{
	StateMachine<ShieldBadGuy> mStateMachine;

public:
	enum State
	{
		Roam,
		Defend,
		Attack,

		Count
	};

public:
	ShieldBadGuy(float radius, const sf::Color& color);

	const char* GetStateName(State state) const;
	void SetState(State state);

protected:
	void OnUpdate() override;
	void OnCollision(Entity* pCollidedWith) override;
};
