#pragma once

#include "Condition.h"
#include "ShieldBadGuy.h"

class ShieldBadGuyCondition_PlayerIsForward : public Condition<ShieldBadGuy>
{
public:
	bool OnTest(ShieldBadGuy* owner) override;
};

class ShieldBadGuyCondition_PlayerInsideDistance : public Condition<ShieldBadGuy>
{
	float mDistance;

public:
	bool OnTest(ShieldBadGuy* owner) override;
	void SetDistance(float distance) { mDistance = distance; }
};