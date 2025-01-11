#pragma once

#include "Entity.h"

class Plant : public Entity
{
	int mAmmo;
	int mMaxAmmo = 6;

public:
	void Shoot();
	void Reload();
	
protected:
	void OnInitialize() override;
	void OnUpdate() override;
};
