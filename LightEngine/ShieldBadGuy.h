#pragma once

#include "Entity.h"
#include "StateMachine.h"
class DummyEntity;

class ShieldBadGuy : public Entity
{
	StateMachine<ShieldBadGuy> mStateMachine;

	float mAttackCooldownTime;
	float mAttackTimer;
	bool CanAttack()const;

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
	void AttackTarget(DummyEntity* entity);

protected:
	void OnUpdate() override;
	void OnCollision(Entity* pCollidedWith) override;
};
