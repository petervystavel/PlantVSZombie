#pragma once

#include "Entity.h"

class Plant : public Entity
{
	int mAmmo;
	int mMaxAmmo = 6;

	float mReloadDuration = 2.0f;
	
	int mAreaIndex;

public:
	void SetAreaIndex(int index) { mAreaIndex = index; }

	void Shoot();

	void Reload();
	
protected:
	void OnUpdate() override;
};
