#pragma once

#include "Entity.h"

class Plant : public Entity
{
	int mAmmo;
	int mMaxAmmo = 6;

	float mShootCadence = 1.0f;
	
	float mReloadDuration = 2.0f;
	
	int mAreaIndex;

public:
	void SetAreaIndex(int index) { mAreaIndex = index; }
	int GetAmmo() const { return mAmmo; }
	int GetMaxAmmo() const { return mMaxAmmo; }
	int GetAreaIndex() const { return mAreaIndex; }
	
protected:
	void OnUpdate() override;
};
