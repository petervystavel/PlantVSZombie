#pragma once

#include "Action.h"
#include "ShieldBadGuy.h"

class ShieldBadGuyAction_Idle : public Action<ShieldBadGuy>
{
public:
	void Start(ShieldBadGuy* pShieldBadGuy) override {}
	void Update(ShieldBadGuy* pShieldBadGuy) override {}
	void End(ShieldBadGuy* pShieldBadGuy) override {}
};

class ShieldBadGuyAction_Defend : public Action<ShieldBadGuy>
{
public:
	void Start(ShieldBadGuy* pShieldBadGuy) override;
	void Update(ShieldBadGuy* pShieldBadGuy) override;
	void End(ShieldBadGuy* pShieldBadGuy) override;
};


class ShieldBadGuyAction_Roam : public Action<ShieldBadGuy>
{
	int mDirectionX = 1;
public:
	void Start(ShieldBadGuy* pShieldBadGuy) override;
	void Update(ShieldBadGuy* pShieldBadGuy) override;
	void End(ShieldBadGuy* pShieldBadGuy) override;
};

class ShieldBadGuyAction_Attack : public Action<ShieldBadGuy>
{
public:
	void Start(ShieldBadGuy* pShieldBadGuy) override;
	void Update(ShieldBadGuy* pShieldBadGuy) override;
	void End(ShieldBadGuy* pShieldBadGuy) override;
};